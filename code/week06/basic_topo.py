#!/usr/bin/python      
__author__ = "yunshin.cho"
from mininet.node import CPULimitedHost
from mininet.topo import Topo
from mininet.net import Mininet
from mininet.log import setLogLevel, info
from mininet.node import RemoteController
from mininet.cli import CLI

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
    
    def run():
        c = RemoteController('c', '0.0.0.0', 6653)
        net = Mininet(topo=Simple3PktSwitch(), host=CPULimitedHost, controller = RemoteController)
        net.addController(c)
        net.start()
        CLI(net)
        net.stop()
        
# if the script is run directly (sudo custom/optical.py):
if __name__ == '__main__':
    setLogLevel('info')
    run()