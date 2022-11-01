from mininet.topo import Topo

class Ring( Topo ):

    def build( self,Switch_num,lossy=True):
        Switch=[]
        Host=[]
        for i in range(Switch_num):
            Switch.append(self.addSwitch('s{}'.format(i+1)))
            Host.append(self.addHost('h{}'.format(i+1)))
            self.addLink(Host[i],Switch[i])
        for i in range(Switch_num-1):
            self.addLink(Switch[i],Switch[i+1])
        self.addLink(Switch[0],Switch[Switch_num-1])
topos = { 'mytopo': ( lambda num: Ring(Switch_num=num) ) }