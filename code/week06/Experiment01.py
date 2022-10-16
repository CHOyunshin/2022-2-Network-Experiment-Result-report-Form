#!/usr/bin/python      
__author__ = "yunshin.cho"
from mininet.node import CPULimitedHost
from mininet.topo import Topo
from mininet.net import Mininet
from mininet.log import setLogLevel, info
from mininet.node import RemoteController

class Simple3PktSwitch(Topo):
    def __init__(self, **opts):
        super(Simple3PktSwitch, self).__init__(**opts)
        # Add hosts and switches
        h1 = self.addHost('h1',mac='00:00:00:00:00:01',ip='10.0.0.1')
        h2 = self.addHost('h2',mac='00:00:00:00:00:02',ip='10.0.0.2')
        h3 = self.addHost('h3',mac='00:00:00:00:00:03',ip='10.0.0.3')
        opts = dict(protocols='OpenFlow13')
        # Adding switches
        # instead of use the --mac command in CLI, i set the ip address manually
        s1 = self.addSwitch('s1', ip = '127.0.0.1',port = '6633', opts=opts)
        # Add links
        self.addLink(h1, s1)
        self.addLink(h2, s1)
        self.addLink(h3, s1)
        
def installStaticFlows(net):
    for sw in net.switches:                             # h1 h3 사이 flow 설정하기
        info('Adding flows to %s...' % sw.name)
        sw.dpctl('add-flow', 'in_port=1,nw_dst=10.0.0.3,actions=output=3')      
        sw.dpctl('add-flow', 'in_port=3,nw_dst=10.0.0.1,actions=output=1')
        info(sw.dpctl('dump-flows'))                    # Flow table을 확인해 추가된 경로 확인

def run_scenario_expeiriment_01():
    '''
        Scenario : Compare the ping test before and after adding the flow between host 1 & 3
    '''
    c = RemoteController('c', '0.0.0.0', 6653)
    net = Mininet(topo=Simple3PktSwitch(), host=CPULimitedHost, controller = RemoteController)
    net.addController(c)
    net.start()
    h1, h2, h3, s1 = net.get('h1'), net.get('h2'), net.get('h3'), net.get('s1')
    s1.dpctl('dump-flows')  
    print(h1.cmd('ping -c2',h3.IP())) # ping test between h1 and h3 with sending 2 pings
    net.pingAll()                     # Ping test between all hosts before adding the flow 
    installStaticFlows( net )         # Adding flow between h1 and h3 
    net.pingAll()                     # Ping test between all hosts after adding the flow 
    print(h1.cmd('ping -c2',h3.IP())) # ping test between h1 and h3 with sending 2 pings
    print(h2.cmd('ping -c2',h3.IP())) # ping test between h2 and h3 with sending 2 pings
    net.end()
    
if __name__ == '__main__':
    setLogLevel('info')
    run_scenario_expeiriment_01()