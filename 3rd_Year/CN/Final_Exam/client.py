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
    print("Enter Array (Numbers separated by Spaces): ")
    out_data = input()
    print("Enter Number to be multiplied: ")
    num = input()
    final_num = out_data + " "+num    
    client.sendall(bytes(final_num,'UTF-8'))
    in_data =  client.recv(1024)
    print("Response: " ,in_data.decode())
    if in_data.decode()=="Bye!":
        print("Connection disconnected!")
        break
client.close()