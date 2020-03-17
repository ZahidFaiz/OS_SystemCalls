#include <sys/types.h>          
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include<unistd.h>
#define PORT 8080


char sortalpha(char *buf1)
{	
	int i=0;
	char temp;
	for(;i<strlen(buf1);i++)
	{
		for(int j=0;j<strlen(buf1);j++)

		if(buf1[j+1]>=buf1[j])
		{
			temp=buf1[j];
			buf1[j]=buf1[j+1];
			buf1[j+1]=temp;
		}
	}
	
	printf("SORTED: '%s'\n", buf1);
}






int main ()
{	int new;
	int data[100];
	int server_socket_fd;
	unsigned int len;
	struct sockaddr_in server,client; 

	char msg[]= "This is sent by server";

	server_socket_fd=socket(AF_INET,SOCK_STREAM,0);
	if(server_socket_fd==-1)
	{
		printf("server created \n");
	}

	        server.sin_family = AF_INET;
        	server.sin_port = htons( 8000 );
        	server.sin_addr.s_addr = INADDR_ANY;

	 len= sizeof(struct sockaddr_in);


	if (bind(server_socket_fd,(struct sockaddr *)&server,len)<-1);
	{
		perror("bind");

	}
	
	int listen_sock;	

	if ((listen_sock=listen(server_socket_fd,10)<0))
	{
		perror("listen");

	}
	
	 int client_address_len = 0;

	while (1) {

		int sock;
		sock=accept(server_socket_fd, (struct sockaddr *)&client,&client_address_len);
		 
			perror("");
		//	printf("could not open a socket to accept data\n");
		//	return 1;
		

		int n = 0;
		int len = 0, maxlen = 100;
		char buffer[maxlen];
		char *pbuffer = buffer;

		printf("client connected with ip address: %s\n",
		       inet_ntoa(client.sin_addr));


		while ((n = recv(sock, pbuffer, maxlen, 0)) > 0) {
			pbuffer += n;
			maxlen -= n;
			len += n;

			printf("received: '%s'\n", buffer);
			sortalpha(buffer);
			send(sock, buffer, len, 0);
		}

		close(sock);
	}

	close(listen_sock);
}
