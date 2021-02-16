
import java.io.*;
import java.net.*;

public class Server{

    private Socket socket = null;
    private ServerSocket server = null;
    private DataInputStream in = null;
    private DataOutputStream out = null;
    private DataInputStream input = null;
    public Server(int port){
    
        try{

            server = new ServerSocket(port);

            System.out.println("Server started");
            while(true){
                System.out.println("Waiting for a client ...");
                socket = server.accept();
                System.out.println("Client accepted");    

                in = new DataInputStream(
                new BufferedInputStream(socket.getInputStream()));
                out = new DataOutputStream(socket.getOutputStream());
                input = new DataInputStream(System.in);

                Thread writeMessage = new Thread(new Runnable() { 
    
                    @Override
                    public void run() { 
                        while (true){
                            try{
                                String inputString = input.readLine();
                                out.writeUTF(inputString);
                            }catch(IOException i){
                                System.out.println("Lost connection with socket!");
                                break;
                            }
                        }
                        
                    } 
                });
                writeMessage.start();
                String line = "";
                while (!line.equals("Over")) { 
                    try {         
                        // read the message sent to this client 
                        line = in.readUTF(); 
                        System.out.println("Client: "+ line); 
                    } catch (IOException e) {   
                        System.out.println("Unknown Error Occured while reading Message! Trace: "+e.toString());
                        break;
                    } 
                }                
                writeMessage.stop();
                System.out.println("Closing connection");
                socket.close();
                in.close();
            }
        }catch(IOException i){
            System.out.println(i);
        }
    }
    public static void main(String args[]){
        Server server = new Server(5000);
    }
}