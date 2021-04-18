#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> //confirmar

//SOCK_STREAM -> TCP
//SOCK_DGRAM -> UDP
//netcat -l 12000
int main(){
    char buffer[30];
    int conection = 0;
    int socket_id = 0;
    char msg[] = "GET\r\n";
    socket_id = socket(PF_INET, SOCK_STREAM, 0);//Crea el Socket 

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("142.250.78.36");
    server.sin_port = htons(80);

    conection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if(conection < 0){
        printf("Error al realizar la conexión\r\n");
        return(-1);
    }

    printf("Conexión realizada con éxito\r\n");
    send(socket_id, msg, sizeof(msg), 0);
 //   recv(socket_id,buffer,sizeof(buffer),0);
    printf("Tama--> %d\n\n\n",recv(socket_id,buffer,sizeof(buffer),0));  
    while(recv(socket_id,buffer,sizeof(buffer),0) > 0){
    printf("%s",buffer);
    }
    close(socket_id);
    
     
              
    return(0);   
}