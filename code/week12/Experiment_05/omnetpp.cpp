#-----------------------------------------------------------------------------
[Config experiment02]
network = Network02
sim-time-limit = 20s

*.host*.ipv4.arp.typename = "GlobalArp"

*.hostA.numApps = 1
*.hostA.app[0].typename = "UdpBasicApp"
*.hostA.app[0].destAddresses = "hostB"
*.hostA.app[0].destPort = 5000
*.hostA.app[0].messageLength = 1000B
*.hostA.app[0].sendInterval = exponential(10ms)
*.hostA.app[0].packetName = "UDPData"

*.hostB.numApps = 1
*.hostB.app[0].typename = "UdpSink"
*.hostB.app[0].localPort = 5000

*.host*.wlan[0].typename = "AckingWirelessInterface"
*.host*.wlan[0].mac.useAck = false
*.host*.wlan[0].mac.fullDuplex = false
*.host*.wlan[0].radio.transmitter.communicationRange = 500m
*.host*.wlan[0].radio.receiver.ignoreInterference = true
*.host*.wlan[0].mac.headerLength = 23B

*.host*.**.bitrate = 1Mbps

# --- visualizer part 
*.hostA.wlan[0].radio.displayCommunicationRange = true
*.visualizer.sceneVisualizer.descriptionFigure = "title"
*.visualizer.mediumVisualizer.displaySignals = true
*.visualizer.physicalLinkVisualizer.displayLinks = true
*.visualizer.physicalLinkVisualizer.packetFilter = "UDPData"

#-----------------------------------------------------------------------------
[Config experiment03]
network = Network03
extends = experiment02

*.host*.forwarding = true # routing forwarding enable
*.configurator.config = xml("<config><interface hosts='**' address='10.0.0.x' netmask='255.255.255.0'
/><autoroute metric='errorRate'/></config>") # set address, subnetmask 
*.configurator.optimizeRoutes = false # not using route optimization 
*.host*.ipv4.routingTable.netmaskRoutes = "" # from interference, maintain netmask

*.visualizer.physicalLinkVisualizer.displayLinks = true 
*.visualizer.dataLinkVisualizer.displayLinks = true 
*.visualizer.networkRouteVisualizer.displayRoutes = true 
*.visualizer.*LinkVisualizer.lineShift = 0 
*.visualizer.networkRouteVisualizer.lineShift = 0 
*.visualizer.networkRouteVisualizer.packetFilter = "UDPData"

#-----------------------------------------------------------------------------
[Config experiment04]
network = Network03
extends = experiment03

*.host*.wlan[0].radio.receiver.ignoreInterference = false
*.host*.wlan[0].radio.transmitter.interferenceRange = 500m
*.hostA.wlan[0].radio.displayInterferenceRange = true
*.visualizer.dataLinkVisualizer.packetFilter = ""

*.host*.wlan[0].typename = "WirelessInterface"
*.host*.wlan[0].radio.typename = "UnitDiskRadio"
*.host*.wlan[0].mac.typename = "CsmaCaMac"
*.host*.wlan[0].mac.ackTimeout = 300us
*.host*.wlan[0].queue.typename = "DropTailQueue"

*.host*.wlan[0].mac.useAck = true