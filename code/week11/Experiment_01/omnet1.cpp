[Config SinglePair - TCP - D2D]
* .eNB.lteNic.phy.enableD2DqiReporting = false // If this is set True, UE reports CQI to eNodeB. We disabled it.
* *.usePreconfiguredTxParams = true            // Enable using preconfigured CQI value 
* *.d2dCqi = 1                                 // Assigning CQI value


[Config SinglePair]
* .eNNB.mobility.initialX = 500m               // eNodeB initial x-coordinate
* .eNNB.mobility.initialY = 500m               // eNodeB initial y-coordinate

* .ueD2DTx[0].mobility.initialX = 475m         // TX initial x-coordinate
* .ueD2DTx[0].mobility.initialY = 500m         // TX initial y-coordinate
* .ueD2DRx[0].mobility.initialX = 525m         // RX initial x-coordinate
* .ueD2DRx[0].mobility.initialY = 500m         // RX initial y-coordinate