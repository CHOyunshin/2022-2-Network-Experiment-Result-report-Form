#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import random
from socket import *

# Create a UDP socket 
serverSocket = socket(AF_INET,SOCK_DGRAM) #IPv4, UDP socket 생성
severPort = 6789

serverSocket.bind(('',severPort))

while 1: 
    rand = random.randint(0,10)
    # Receive the client packet along with the adress it is coming from
    message, address = serverSocket.recvfrom(1024)

    #Capitalize the message from the client 
    message = message.upper()
    # iF rand is less than 4, we consider the packet lost and do not
    if rand < 4:
        continue
    serverSocket.sendto(message, address)

