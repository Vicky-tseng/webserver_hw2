#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){

	int sockfd=0;
	struct sockaddr_in info;
	char buffer[1024]={'\0'},buffer2[1024]={'\0'};

        sockfd=socket(AF_INET,SOCK_STREAM,0);

        bzero(&info,sizeof(info));
        info.sin_family=AF_INET;
        //inet_aton("123.123.13.12",&info.sin_addr);
        info.sin_port=htons(8080);
	connect(sockfd,(struct sockaddr *)&info,sizeof(info));
	

//	fgets(buffer,10,stdin);
//	send(sockfd,buffer,strlen(buffer)+1,0);	
	while(1){
		//char message[]={"Hi server"};
//		connect(sockfd,(struct sockaddr *)&info,sizeof(info));
		printf("Send to Server:\n");
		fgets(buffer,10,stdin);
//		scanf("%d",buffer);
		send(sockfd,buffer,strlen(buffer)+1,0);
		sleep(10);
		recv(sockfd,buffer2,1024,0);
		printf("%s",buffer2);

	}


return 0;

}

