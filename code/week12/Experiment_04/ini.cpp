[Config experiment04]
network = Network03
extends = experiment03

*.host*.wlan[0].radio.receiver.ignoreInterference = false
*.host*.wlan[0].radio.transmitter.interferenceRange = 250m
*.hostA.wlan[0].radio.displayInterferenceRange = true
*.visualizer.dataLinkVisualizer.packetFilter = ""

*.host*.wlan[0].typename = "WirelessInterface"
*.host*.wlan[0].radio.typename = "UnitDiskRadio"
*.host*.wlan[0].mac.typename = "CsmaCaMac"
*.host*.wlan[0].mac.ackTimeout = 300us
*.host*.wlan[0].queue.typename = "DropTailQueue"

*.host*.wlan[0].mac.useAck = true