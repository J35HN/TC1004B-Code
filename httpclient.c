#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

extern int h_errno;


int main(int argc, char **argv) {
    char *hostName = argv[1];
    char *message = "GET / HTTP/1.0\r\n\r\n";
    char c;
    struct sockaddr_in serverAddress;
    struct hostent *serverInfo = gethostbyname(hostName); // Dirección IP de este dominio. 
    bzero(&serverAddress, sizeof(serverAddress)); // Inicializa en cero un arreglo.
    serverAddress.sin_family = AF_INET; // Qué tipo de protocolo a usar (4 o 6).
    serverAddress.sin_port = htons(80); // Conectar al puerto 80.
    // serverAddress.sin_addr = serverInfo->h_addr_list[0]; // no se puede    
    bcopy((char *)serverInfo->h_addr, 
	  (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    connect(sockfd,(const struct sockaddr *)&serverAddress,sizeof(serverAddress)); // Conectar con socket a la dirección. 
    
    write(sockfd,message,strlen(message));
    while(read(sockfd,&c,1)){
        printf("%c",c);
    }
    close(sockfd);
    printf("\n");

    return 0;
}