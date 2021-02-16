
import socket
import threading
import sys
ClientSocket = socket.socket()
ClientSocket1 = socket.socket()
# Connecting with Main server
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
            sys.exit()
        print("\n")
        print(Response.decode('utf-8'))
        print("Enter Message: ")
        
host = 'localhost'
port = 9998
print('Waiting to establish Connection...')
try:
    ClientSocket1.connect((host, port))
except socket.error as e:
    print(str(e))
if __name__ == '__main__':
    t2 = threading.Thread(target=recvResp, args=())
    t2.start()
    msg = input("Enter Message: ")
    while(msg != ""):
        ClientSocket1.send(msg.encode())
        msg = input("Enter Message: ")
    t2.join()
    ClientSocket.close()
    ClientSocket1.close()

# import socket
# SERVER = "127.0.0.1"
# PORT = 8080
# client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client.connect((SERVER, PORT))
# client.sendall(bytes("Client Initial Handshake",'UTF-8'))
# while True:
#     in_data =  client.recv(1024)
#     print("Response: " ,in_data.decode())
#     if in_data.decode()=="Bye!":
#         print("Connection disconnected!")
#         break
#     out_data = input()
#     client.sendall(bytes(out_data,'UTF-8'))
# client.close()