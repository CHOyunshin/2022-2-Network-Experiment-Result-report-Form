[Config experiment03]
network = Network03
extends = experiment02

*.host*.wlan[0].radio.transmitter.communicationRange = 250m

*.host*.forwarding = true # routing forwarding enable
*.configurator.config = xml("<config><interface hosts='**' address='10.0.0.x' netmask='255.255.255.0'/>
                        <autoroute metric='errorRate'/></config>") # set address, subnetmask 
*.configurator.optimizeRoutes = false # not using route optimization 
*.host*.ipv4.routingTable.netmaskRoutes = "" # from interference, maintain netmask
*.visualizer.physicalLinkVisualizer.displayLinks = true 
*.visualizer.dataLinkVisualizer.displayLinks = true 
*.visualizer.networkRouteVisualizer.displayRoutes = true 
*.visualizer.*LinkVisualizer.lineShift = 0 
*.visualizer.networkRouteVisualizer.lineShift = 0 
*.visualizer.networkRouteVisualizer.packetFilter = "UDPData"