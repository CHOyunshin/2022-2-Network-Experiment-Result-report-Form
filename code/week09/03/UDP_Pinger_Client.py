#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import sys, time
from socket import *

argv  = sys.argv
host = argv[1]
port = argv[2]
timeout = 3.5 

clientsocket = socket(AF_INET,SOCK_DGRAM)
clientsocket.settimeout(timeout)
port = int(port)
ptime = 0

# # 별도로 server 선언해 주기 
# server = (host, port)

while ptime < 10:
    ptime += 1
    # Format the message to be sent
    data = "Ping " + str(ptime) + " " + time.asctime()
    try:
        # Sent time
        RTTb = time.time()
        # Send the UOP packet with the ping message
        clientsocket.sendto(data.encode(), (host, port))
        #Receive the server response
        message, address = clientsocket.recvfrom(1024)
        # Recerveo tie
        RTTa = time.time()
        # Diso lay the server resoonse as an outout
        print("Reply from " + address[0] + ": " + message.decode())
        # Round trip time is the difference between sent and received time
        RTT = (RTTa - RTTb)* 1000
        print("RTT: %.4f msec" %(RTT))
    except:
    # Server does not response
    # Assume the packet is lost
        print("Request timed out.")
        continue
clientsocket.close()

