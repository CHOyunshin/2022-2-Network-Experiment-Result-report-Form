sh ovs-ofctl add-flow  s1 in_port=1,nw_dst=10.1.1.1,actions=output=2
sh ovs-ofctl add-flow  s2 in_port=1,nw_dst=10.1.1.1,actions=output=2
sh ovs-ofctl add-flow  s4 in_port=2,nw_dst=10.1.1.1,actions=output=3
sh ovs-ofctl add-flow  s6 in_port=4,nw_dst=10.1.1.1,actions=output=1
sh ovs-ofctl add-flow  s6 in_port=1,nw_dst=10.6.1.1,actions=output=2
sh ovs-ofctl add-flow  s5 in_port=1,nw_dst=10.6.1.1,actions=output=2
sh ovs-ofctl add-flow  s3 in_port=2,nw_dst=10.6.1.1,actions=output=1
sh ovs-ofctl add-flow  s1 in_port=3,nw_dst=10.6.1.1,actions=output=1