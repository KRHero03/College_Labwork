#include <bits/stdc++.h>// Library for common data structures and algos
#include <stdio.h>      // Standard IO
#include <unistd.h> 
#include <sys/types.h>  // For common syscalls
#include <sys/wait.h>   // For wait
#include <fcntl.h>      // For File handling
#include <sys/stat.h>   // For attributes of file
#include <dirent.h>     // For directory handling
#include <libgen.h>     // General purpose library

using namespace std;

void fork_example(){
    cout<<"FORK EXAMPLE"<<endl;
    /*  Clone the calling process, creating an exact copy
        -1 : error
        0 : child process
        positive val: parent process*/
    pid_t id = fork();
    int cstatus;

    if(id==-1){
        cerr<<errno<<endl;
        exit(0);
    }else{        
        cout<<id<<endl;
        if(id==0) {
            cout<<"child process executed!"<<endl;
            /* Exits the calling process with a status code*/
            exit(1);
        }
        else wait(&cstatus); // Waits the calling process until child process has exited
    }
}

void exec_example(){
    /*  Executes commands and arguments
        @param
        command : command that you need to execute
        args    : arguments  */
    cout<<"EXEC EXAMPLE"<<endl;
    int cstatus;
    pid_t child = fork();
    if(child==-1){
        exit(0);
    }else{
        if(child==0){
            char* args[] = {"ls","-a",NULL};
            execvp(args[0],args);
            exit(1);
        }else{
            wait(&cstatus);
        }
    }
}

void getpid_example(){
    /*  Returns pid of calling process */
    cout<<"PID EXAMPLE"<<endl;
    cout<<getpid()<<endl;
}

void file_example(){
    cout<<"FILE EXAMPLE"<<endl;
    // Creates a file in disk with required flags RDWR = Read/Write
    int fd =creat("temp.txt",O_RDWR);

    struct stat sfile;
    // Gets attributes for a file
    stat("temp.txt", &sfile);
    cout<<"ST MODE: "<<sfile.st_mode<<endl;

    if(fd==-1){
        cout<<"Failed to create a file!"<<endl;
        exit(0);
    }
    cout<<"Created file with fd: "<<fd<<endl;

    // Writes in file
    write(fd,"Hello World! This is a string",strlen("Hello World! This is a string"));
    cout<<"Written in file!"<<endl;

    char* y = (char* )calloc(100,sizeof(char));

    // Read a file
    int fd1 = open("temp.txt",O_RDONLY);
    int end = read(fd1,y,90);
    y[end] = '\0';
    printf("Read from file: %s\n",y);

    // Closes a file
    close(fd);
    close(fd1);

    cout<<"Closed file!"<<endl;
}

void dir_example(){
    cout<<"DIRECTORY EXAMPLE"<<endl;
    DIR *dir;
    struct dirent * dp;
    // Opens the directory
    if((dir=opendir("."))==NULL){
        cout<<"Error in opening current folder!"<<endl;
        exit(0);
    }
    cout<<"Reading Directory"<<endl;

    // Reads the directory
    while((dp=readdir(dir))!=NULL){
        printf("%s\n",dp->d_name);
    }

    // Closes directory
    closedir(dir);
    cout<<"Closed Directory"<<endl;

}

void chmod_example(){
    cout<<"CHMOD EXAMPLE"<<endl;
    char mode[] = "0777";
    char buf[100] = "temp.txt";
    int i;
    i = strtol(mode, 0, 8);

    // Changes access mode of file
    if (chmod (buf,i) < 0)
    {
        // Prints the string mapping of error code
        cout<<"Error in chmod of temp.txt"<<" "<<strerror(errno)<<endl;
        exit(1);
    }
    cout<<"CHMOD successful!"<<endl;
}

void chown_example(){
    cout<<"CHOWN EXAMPLE"<<endl;
    
    // Gets UID
    uid_t uid = getuid();
    cout<<"User ID: "<<uid<<endl;

    // Changes ownership of the file
    if(chown("temp.txt",uid,-1)==-1){
        cout<<"Error in chown syscall! Error: "<<strerror(errno)<<endl;
        exit(0);
    }
    cout<<"CHOWN Successful!"<<endl;
}

int main(){

    fork_example();
    exec_example();
    getpid_example();
    file_example();
    dir_example();
    chmod_example();
    chown_example();

    return 0;
    
}