import socket
import sys
import threading
clients = []
ServerSocket = socket.socket()
host = 'localhost'
port = 9999
ThreadCount = 0
PClient = ""
try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(str(e))
print('Waiting to establish Connection...')
ServerSocket.listen(5)

def saysomething():
    msg1 = input("Broadcast Message: ")
    msg = "Server : " + msg1
    for i in clients:
        i[0].send(msg.encode())

def addClients():
    global ThreadCount,PClient
    while True:
        try:
            Client, address = ServerSocket.accept()
        except socket.error as e:
            break
        print('Connected to: ' + address[0] + ':' + str(address[1]))
        clients.append((Client,address))
        print("Connection established!")
        ThreadCount += 1
        if(ThreadCount == 1):
            PClient = Client
        print("Press 1 to Broadcast Messages and 3 to Stop Server. ")
def recvMsg():
    while True:
        if(PClient != ""):
            Response = PClient.recv(1024)
            print(Response.decode('utf-8'))
            print("Press 1 to Broadcast Messages and 3 to Stop Server. ")
if __name__ == '__main__':
    t1 = threading.Thread(target=addClients, args=())
    t2 = threading.Thread(target= recvMsg,args=())
    t1.start()
    t2.start()
    print("Server Started")
    print("Press 1 to Broadcast Messages and 3 to Stop Server. ")
    choice = int(input())
    while(choice != 3):
        if(choice == 1):
            saysomething()
        print("Press 1 to Broadcast Messages and 3 to Stop Server. ")
        choice = int(input())
    print("Server Stopped!")
    ServerSocket.close()
    quit(0)

# import socket, threading
# class ClientThread(threading.Thread):
#     def __init__(self,clientAddress,clientsocket,id):
#         threading.Thread.__init__(self)
#         self.csocket = clientsocket
#         self.id = id
#         self.clientAddress = clientAddress
#         print ("New connection added: ", self.clientAddress)

#     def run(self):
#         print ("Connection from : ", self.clientAddress)
        
#         data = self.csocket.recv(2048)
#         response = data.decode()
#         if response=="Client Initial Handshake":
#             print ("Initial Handshake successful from Client: ",self.clientAddress)
#             self.csocket.send(bytes("Server - Connection established!" ,'UTF-8'))
#         else:
#             print ("Initial Handshake failed from Client: ",self.clientAddress)
#             return
        
#         while True:
#             data = self.csocket.recv(2048)        
#             response = data.decode()
#             response = response.strip()
#             print("Response: ",response.strip())
#             if response == "exit":
#                 self.csocket.send(bytes("Bye!",'UTF-8'))
#                 break

#             self.csocket.send(bytes("Server - "+response ,'UTF-8'))

            
#         print ("Client disconnected: ",self.clientAddress)
        
# LOCALHOST = "127.0.0.1"
# PORT = 8080
# server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
# server.bind((LOCALHOST, PORT))
# print("Server started")
# print("Waiting for client request..")
# sockets = dict()

# while True:
#     server.listen(1)
#     clientsock, clientAddress = server.accept()
#     newthread = ClientThread(clientAddress, clientsock,0)
#     newthread.start()