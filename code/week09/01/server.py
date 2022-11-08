from socket import *
import sys 

serverSocket = socket(AF_INET,SOCK_STREAM) #IPv4, TCP socket 생성

severPort = 6789

serverSocket.bind((‘’,serverPort))
serverSocket.listen(1)

while 1:
	print('The server is ready to receive')
	connectionSocket, addr = serverSocket.accept()
	try:
		# Receives the request message from the client 
		message = connectionSocket.recv(1024).decode()
		filename = message.split()[1]
		f = open(filename[1:])
		outputdata = f.read()
		# Send the HTTP response header line to the connection Socket 
		connectionSocket.send("HTTP/1.1 200 OK\r\n\r\n".encode())
		
		# Send the content of the requested file to the connection socket
		for i in range(0, len(outputdata)):
			connectionSocket.send(outputdata[i].encode())
		connectionSocket.send('\r\n'.encode())

		# close the client connection socket
		connectionSocket.close()
		
	except IOError:
			connectionSocket.send("HTTP/1.1 404 Not Found\r\n\r\n".encode())
			connectionSocket.send("<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n".encode())
			connectionSocket.close()

serverSocket.close()
sys.exit() #Terminate the program after sending the corresponding data

