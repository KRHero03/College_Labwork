import java.io.*;
import java.net.*;

public class Client{

    private DataInputStream input = null;
    private DataOutputStream out = null;
    private DataInputStream in = null;

    public Client(String address, int port){

        Socket socket = null;
        try{
            socket = new Socket(address, port);
            System.out.println("Connected");
            input = new DataInputStream(System.in);
            out = new DataOutputStream(socket.getOutputStream());
            in =  new DataInputStream(new BufferedInputStream(socket.getInputStream()));
        }catch(UnknownHostException u){
            System.out.println("Unable to connect! Unknown host!");
        }catch(IOException i){
            System.out.println("Invalid Input by User!");
        }

        Thread readMessage = new Thread(new Runnable() { 
  
            @Override
            public void run() { 
  
                while (true) { 
                    try { 
  
                        // read the message sent to this client 
                        String msg = in.readUTF(); 
                        System.out.println("Server: "+ msg); 
                    } catch (IOException e) {   
                        System.out.println("Unknown Error Occured while reading Message! Trace: "+e.toString());
                        break;
                    } 
                } 
            } 
        });

        readMessage.start();
        String line = "";
        while (!(line.equals("Over"))) { 
            try { 

                // read the message sent to this client 
                line = input.readLine();
                out.writeUTF(line); 
            } catch (IOException e) {   
                System.out.println("Unknown Error Occured while sending Message! Trace: "+e.toString());
                break;
            } 
        } 
        readMessage.stop();
        try{
            input.close();
            out.close();
            socket.close();
        }catch(IOException i){
            System.out.println(i);
        }

    }
    
    public static void main(String args[]){
        Client client = new Client("127.0.0.1", 5000);
    }
}