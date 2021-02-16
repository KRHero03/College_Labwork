'''
    Author : KRHero
    IDE : VSCode
'''
import socket, threading
class ClientThread(threading.Thread):
    def __init__(self,clientAddress,clientsocket):
        threading.Thread.__init__(self)
        self.csocket = clientsocket
        self.clientAddress = clientAddress
        print ("New connection added: ", self.clientAddress)
    def run(self):
        print ("Connection from : ", self.clientAddress)
        
        data = self.csocket.recv(2048)
        response = data.decode()
        if response=="Client Initial Handshake":
            print ("Initial Handshake successful from Client: ",self.clientAddress)
        else:
            return

        while True:
            try:
                data = self.csocket.recv(2048)
            except:
                break
            response = data.decode()
            print("Response from server: ",response)
            response = response.strip()
            if(response=="exit"):
                self.csocket.send(bytes("Bye!",'UTF-8'))
                break       
            params = response.split(' ')
            numbers = [int(num) for num in params[:len(params)-1]]
            multiplier = int(params[-1])
            final_ans = [num*multiplier for num in numbers]
            final_response = ""
            for num in final_ans:
                final_response = final_response + str(num) + " "
            final_response = final_response.strip()

            self.csocket.send(bytes(final_response,'UTF-8'))


            
        print("Client disconnected: ",self.clientAddress)
        
LOCALHOST = "127.0.0.1"
PORT = 8080
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((LOCALHOST, PORT))
print("Server started")
print("Waiting for client request..")
while True:
    server.listen(1)
    clientsock, clientAddress = server.accept()
    newthread = ClientThread(clientAddress, clientsock)
    newthread.start()