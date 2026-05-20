#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
// low level file operation which is best for fifo rather to <stdio.h>

int main(){

  char msg[100];
  FILE *read_fp;
  FILE *write_fp;
  
  printf("\t\t***Client is ready***");
  printf("\n");
  while(1){
  printf("\n");
  printf("client: Enter the number to be checked(for Armstrong)-");
  fgets(msg,100,stdin);
  msg[strcspn(msg, "\n")] = '\0'; //fix for the line issue in the output
  if(strcmp(msg, "exit")==0){
  printf("\tClient is Disconnecting\n");
  exit(0);}
  //writing in pipe1
 
  // replaced fopen("pipe1","w") with:
  int fd = open("pipe1", O_WRONLY);  // blocks until server is ready
  write_fp = fdopen(fd, "w");
   //write_fp=fopen("pipe1","w");
  if(write_fp == NULL ){
  continue;
  }
  fprintf(write_fp,"%s",msg);
  fclose(write_fp);
  //reading in pipe2
  char msg1[100];
  read_fp=fopen("pipe2","r");
  if(read_fp == NULL){
  continue;
  }
  fgets(msg1,100,read_fp);
  fclose(read_fp);
  
  //final result
 int indianFlag = atoi(msg1);
  
  if(indianFlag == 1){
  printf("\nServer: The Number %s is an Armstrong number\n",msg);
  }
  else{
    printf("\nServer: The Number %s is not an Armstrong number\n",msg);
  }
  
  } 
  return 0;
  }
  
  
