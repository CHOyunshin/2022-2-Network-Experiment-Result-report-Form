#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from socket import *
import os
import sys
import time

Host = '192.168.55.235'
Port = 6797

clientSocket = socket(AF_INET, SOCK_STREAM)

clientSocket.connect((Host,Port))

message = input('요청할 파일 이름: ')
clientSocket.sendall(message.encode())

data = clientSocket.recv(4096)
data_iter = 0

os.chdir("C:\\Users\\MYpx\\SocketProgramming\\Ex_2\\client")
nowdir = os.getcwd()
with open(nowdir+ "\\" + message, 'wb') as f:     #현재 dir에 filename으로 파일을 받는다
	try:
		while data:     #데이터가 있을 때까지
			f.write(data)     #4096바이트 쓴다
			data_iter = data_iter + 1
			print('파일 %s (seq : %d) is received' %(message, data_iter))
			data = clientSocket.recv(4096)     #4096바이트를 받아 온다
			time.sleep(0.5)
	except Exception as ex:
		print(ex)

