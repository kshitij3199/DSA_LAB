#include<stdio.h>
#include<stdlib.h>
int main(){
FILE *op = fopen("original.txt","r"); 
FILE *cp = fopen("copyfile.txt","w"); 
if (op == NULL || cp ==NULL) 
{
	printf("no such file found");
      exit(1); 
}
do
    { 
        // Taking input single character at a time 
        char c = fgetc(op); 
  
        // Checking for end of file 
        if (feof(op)) 
            break ; 
  
        //printf("%c", c);
	fputc(c, cp);  
    }  while(1); 
  
    
fclose(op);
fclose(cp);
printf("File is successfully copied into copyfile.txt"); 
return(0); 







}
