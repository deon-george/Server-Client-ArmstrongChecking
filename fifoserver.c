#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<fcntl.h>
// low level file operation header file which is best for fifo rather to <stdio.h>

int main(){

  char msg[100];
  FILE *read_fp;
  FILE *write_fp;
  
  printf("\tServer is live....");
  while(1){
  
  
  // replaced fopen("pipe1","r") with:
  int fd = open("pipe1", O_RDONLY);  // blocks until client writes
  read_fp = fdopen(fd, "r");
  //read_fp=fopen("pipe1","r");
  if(read_fp == NULL ){
  continue;
  }
  fgets(msg,100,read_fp);
  fclose(read_fp);
  //char conversion to int 
   msg[strcspn(msg, "\n")] = '\0'; //fix for the line issue in the output
  if(strcmp(msg, "exit")==0){
  printf("\tClient is Disconnecting\n");
  exit(0);}
  
  int num = atoi(msg);
  
  int temp = num;
  int remainder;
  int result,i,n=0;
  //counting no of digits
  while(temp>0){
  temp = temp/10;
  ++n;}
  //calculating the sum of power of the digits and checking armstrong or not
  temp = num;
  int sum=0;
  while(temp>0){
  remainder = temp % 10;
  result = pow(remainder,n);
  sum = sum + result;
  temp = temp / 10;
  }
  int flag=0;
  //checking armstrong or not
  if(sum == num){
  printf("\nServer: The Number %d is an Armstrong number",num);
  flag=1;
  }
  else{
    printf("\nServer: The Number %d is not an Armstrong number",num);
  }
  //conversion of int to char
  //flag=atoi(msg);
  char msg1[100];
  sprintf(msg1,"%d",flag);
  write_fp = fopen("pipe2","w");
  if(write_fp == NULL){
  continue;
  }
  fprintf(write_fp,"%s",msg1);
  fclose(write_fp);
  
  }
  return 0;
  }
  
  
