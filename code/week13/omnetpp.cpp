///Simulation parameters///
sim-time-limit = 300s							// Simulation time 300s

///RSU SETTINGS///
*.rsu[0].mobility.x = 1500						// Coordinate of RSU1
*.rsu[0].mobility.y = 1500
*.rsu[0].mobility.z = 3

*.rsu[1].mobility.x = 1800						// Coordinate of RSU2
*.rsu[1].mobility.y = 1800
*.rsu[1].mobility.z = 3

///Mobility///
*.node[*0].veinsmobility.accidentCount = 1		// 1st vehicle accident
*.node[*0].veinsmobility.accidentStart = 50
*.node[*0].veinsmobility.accidentDuration = 40

*.node[*4].veinsmobility.accidentCount = 1		// 5th vehicle accident
*.node[*4].veinsmobility.accidentStart = 80
*.node[*4].veinsmobility.accidentDuration = 50