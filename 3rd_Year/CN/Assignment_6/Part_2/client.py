'''
    Author : KRHero
    IDE : VSCode
'''

import socket
SERVER = "127.0.0.1"
PORT = 8080
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((SERVER, PORT))
client.sendall(bytes("Client Initial Handshake",'UTF-8'))
while True:
    in_data =  client.recv(1024)
    print("Response: " ,in_data.decode())
    if in_data.decode()=="Bye!":
        print("Connection disconnected!")
        break
    out_data = input()
    client.sendall(bytes(out_data,'UTF-8'))
client.close()