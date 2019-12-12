#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/time.h>

int list[10]={0};
int matrix[9]={0};

//int an=0;
int main(){

	
	char input[1]={},input2[1]={};
	int ps=0,start=0;
	char message[256]={'\0'},msg[100];
	int sockfd=0;
	int client=0;
	struct sockaddr_in info,clientinfo;
	socklen_t addrlen=sizeof(clientinfo);
	pthread_t t;
	long ret;
	int listener,to=0;
	pid_t pid;
	int i,num2=10,num,num3=10,num_list=0;
	int fd[2],fd2[2];
	FILE *fp=NULL,*fp2=NULL,*fp3=NULL;

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	bzero(&info,sizeof(info));
	info.sin_family=AF_INET;
//	info.sin_addr.s_addr=INADDR_ANY;
//	inet_aton("123.123.13.12",&info.sin_addr);
	info.sin_port=htons(8080);
	bind(sockfd,(struct sockaddr *)&info,sizeof(info));
	listener=listen(sockfd,64);
	
//	fd_set rfd;
//	FD_SET(listener,&rfd);
//	int stat;

//	strcpy(message,"\t|\t|\t\n------\n\t|\t|\t\n-----\n\t|\t|\t\n");
//	fp=fopen("matrix.txt","r+");
//	fwrite(message,1,sizeof(message),fp);
//	fclose(fp);
	
//	int fp=open("cat2.jpg",O_RDONLY);
//	printf("%d",fp);       

//   	client=accept(sockfd,(struct sockaddr *)&info,&addrlen);
	while(1){
//		listen(sockfd,64);		
		client=accept(sockfd,(struct sockaddr *)&info,&addrlen);
		list[to]=client;
		to=to+1;
//		printf("%d",client);
//		sprintf(msg,"%d %d %d %d %d",list[0],list[1],list[2],list[3],list[4]);
//		send(client,message,sizeof(message),0);
//		fd_set rfd;
//		FD_ZERO(&rfd);
//		FD_SET(listener,&rfd);
//		int stat;
//		struct timeval timer;
//		timer.tv_sec=1;
		recv(client,input,sizeof(input),0);
		sprintf(msg,"%d %d %d %d %d",list[0],list[1],list[2],list[3],list[4]);
  //              printf("%s",input);
  //              strcpy(message," | | \n------\n | | \n-----\n | | \n");
                send(client,msg,sizeof(msg),0);
//		recv(client,input2,sizeof(input2),0);
//		stat=select(client+1,&rfd,NULL,NULL,NULL);
//		if(FD_ISSET(client,&rfd)){
//			client=accept(sockfd,(struct sockaddr *)&info,&addrlen);
//			FD_SET(client,&rfd);
//		}
//		recv(client,input,sizeof(input),0);
//		recv(client,input2,sizeof(input2),0);
//		printf("%s",input2);
//		ps=atoi(input2);
//		sleep(3);
//		for(i=0;i<9;i++)
//		printf("%c",input2[i]);
//		if(ps==123)
//			printf("yes");
///		i=strcmp(input2,ps);
//		printf("%d",ps);
		printf("yes");
//		to=to+1;
		start=start+1;
		if(start==1){
//			sleep(5);
//			printf("yes1");
			pipe(fd);
			pid=fork();
			if(pid==0){
//			read(fd[0],matrix,sizeof(matrix));
				while(1){
			//printf("%d",pid);
			
				recv(client,input,sizeof(input),0);
				memset(message,'\0',sizeof(message));
//				fp2=fopen("matrix.txt","r");
//				fgets(matrix,10,fp2);
//				fread(message,1,256,fp2);
//				printf("%s\n",input);
//				fclose(fp2);
//			recv(client,input,sizeof(input),0);
				num=atoi(input);
//				close(fd[1]);
				read(fd[0],matrix,sizeof(matrix));
				sleep(3);
//				close(fd[0]);
				matrix[num]=1;
//				for(i=0;i<8;i++)
//				printf("%d",matrix[i]);
//				printf("\n");
//				write(fd[1],matrix,sizeof(matrix));
	                //printf("%s",input);
  	 	     	        strcpy(message,"\t|\t|\t\n------\n\t|\t|\t\n-----\n\t|\t|\t\n");
				for(i=0;i<=8;i++){
					if(matrix[i]==1)
						num2=i;
					if(matrix[i]==2)
						num3=i;
					if(num2<=3)
						message[num2*2-2]='O';
					if(num2>3&&num2<=6)
						message[(num2-4)*2+13]='O';
					if(num2>6&&num2<=9)
						message[(num2-8)*2+27]='O';
					if(num3<=3)
                                                message[num3*2-2]='X';
                                        if(num3>3&&num3<=6)
                                                message[(num3-4)*2+13]='X';
                                        if(num3>6&&num3<=9)
                                                message[(num3-8)*2+27]='X';
					num2=10;
					num3=10;
                		}
				printf("yes");
				printf("%s",message);
				write(fd[1],matrix,sizeof(matrix));
				send(client,message,sizeof(message),0);

///			printf("%s",message);
//				fp3=fopen("matrix.txt","w");
//				fwrite(message,1,sizeof(message),fp3);
//				fclose(fp3);
				
//				write(fd[1],matrix,sizeof(matrix));
//				close(fd[1]);
				}
			}
	
//			else{
//				if(to==2){
//				while(1){
//				close(fd[0]);
//				write(fd[1],matrix,sizeof(matrix));
//				close(fd[1]);
///				read(fd[0],matrix,sizeof(matrix));
//				close(fd[0]);
//				}
//				}
////			write(fd[1],matrix,sizeof(matrix));
//			}
		}
		if(start==2){
//			sleep(5);
			printf("yes2");
			pipe(fd2);
			pid=fork();
			if(pid==0){
				while(1){
					recv(client,input,sizeof(input),0);
                                memset(message,'\0',sizeof(message));
//                              fp2=fopen("matrix.txt","r");
//                              fgets(matrix,10,fp2);
//                              fread(message,1,256,fp2);
//                              printf("%s\n",input);
//                              fclose(fp2);
//                      recv(client,input,sizeof(input),0);
                                num=atoi(input);
//                              close(fd[1]);
                                read(fd2[0],matrix,sizeof(matrix));
                                sleep(5);
//                              close(fd[0]);
                                matrix[num]=2;
				strcpy(message,"\t|\t|\t\n------\n\t|\t|\t\n-----\n\t|\t|\t\n");
                                for(i=0;i<=8;i++){
                                        if(matrix[i]==1)
                                                num2=i;
					if(matrix[i]==2)
                                                num3=i;
                                        if(num2<=3)
                                                message[num2*2-2]='O';
                                        if(num2>3&&num2<=6)
                                                message[(num2-4)*2+13]='O';
                                        if(num2>6&&num2<=9)
                                                message[(num2-8)*2+27]='O';
					if(num3<=3)
                                                message[num3*2-2]='X';
                                        if(num3>3&&num3<=6)
                                                message[(num3-4)*2+13]='X';
                                        if(num3>6&&num3<=9)
                                                message[(num3-8)*2+27]='X';
					num2=10;
					num3=10;
                                }
                                printf("yes");
                                printf("%s",message);
                                write(fd2[1],matrix,sizeof(matrix));
                                send(client,message,sizeof(message),0);
				}
			}

			else{
                                while(1){
//                              close(fd[0]);
				write(fd[1],matrix,sizeof(matrix));
				read(fd[0],matrix,sizeof(matrix));
                                write(fd2[1],matrix,sizeof(matrix));
//                              close(fd[1]);
                                read(fd2[0],matrix,sizeof(matrix));
//  //                            close(fd[0]);
                                }
//                      write(fd[1],matrix,sizeof(matrix));
                       }
		}
		
//		pthread_create(&t,NULL,child,&client);
//		_beginthreadex(NULL,0,child,&client,0,NULL);
//		recv(client,input,sizeof(input),0);
//		printf("%s",input);
//		strcpy(message," | | \n------\n | | \n-----\n | | \n");
//		send(client,message,sizeof(message),0);
//		pthread_joint(t,NULL);			
//			

//		if(!strncmp())

		

//		ret=read(fp,buffer,strlen(buffer));
		
//		fread(buffer,1,1024,fp);
//		printf("%s",buffer);


//		if(pid=fork()<0){

//			exit(3);
//		}
//		else{

//			if(pid==0){
//				close(sockfd);
				//handle_socket(sockfd);
//			}
//			else{
//				close(client);
//			}
//		}
		
//		if()


	}

//	int er=connect(sockfd,(struct sockaddr *)&info,sizeof(info));

//	printf("%d",er);


return 0;
}
