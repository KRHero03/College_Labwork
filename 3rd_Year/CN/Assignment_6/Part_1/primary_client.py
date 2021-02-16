import socket
import threading
import sys
ServerSocket = socket.socket()
ClientSocket = socket.socket()

clients = []
host = 'localhost'
port = 9998
ThreadCount = 0
try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Waiting to establish Connection...')

ServerSocket.listen(5)
def addClients():
    global ThreadCount
    t = []
    while True:
        Client, address = ServerSocket.accept()
        print('Connected to: ' + address[0] + ':' + str(address[1]))
        clients.append((Client,address))
        print("New Client Found... ")
        ThreadCount += 1
        th = threading.Thread(target=forwardMsg, args=(Client,address))
        th.start()
        t.append(th)

host = 'localhost'
port = 9999
print('Waiting to establish Connection...')

try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

def recvResp():
    while True:
        try:
            Response = ClientSocket.recv(1024)
        except socket.error as e:
            print(e)
            sys.exit("Connection interrupted by Server!")
        print(Response.decode('utf-8'))

def forwardMsg(Client,address):
    while True:
        fmsg = Client.recv(1024).decode('utf-8')
        fmsg = str(address)+" Forwarded Client Message :"+fmsg
        print(fmsg)
        ClientSocket.send(fmsg.encode())

if __name__ == '__main__':
    t1 = threading.Thread(target=addClients, args=())
    t2 = threading.Thread(target=recvResp, args=())
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    ClientSocket.close()
    ServerSocket.close()