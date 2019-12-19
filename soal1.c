#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>

int main(int argc, char** argv)
{
	
	 // We use two pipes 
    // First pipe to send input string from parent 
    // Second pipe to send concatenated string from child 
  
    int fd1[2];  // Used to store two ends of first pipe 
    int fd2[2];  // Used to store two ends of second pipe 
  
    //char fixed_str[] = "forgeeks.org"; 
    //char input_str[100]; 
    pid_t p; 
  
    if (pipe(fd1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    if (pipe(fd2)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
  
    int temp;
    printf("please enter the number");
    scanf("%d", &temp); 
    p = fork(); 
  
    if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
    // Parent process 
    else if (p > 0) 
    { 
  
        long int digits = temp;
        int result ;
        close(fd1[0]);  // Close reading end of first pipe 
  
        // Write input string and close writing end of first 
        // pipe. 
        write(fd1[1], &digits , sizeof(digits)); 
        close(fd1[1]); 
  
        // Wait for child to send a string 
        wait(NULL); 
  
        close(fd2[1]); // Close writing end of second pipe 
  
        // Read string from child, print it and close 
        // reading end. 
        read(fd2[0], &result, sizeof(result) ); 
	
        printf("Result %d \n", result); 
        close(fd2[0]); 
    } 
  
    // child process 
    else
    { 
        close(fd1[1]);  // Close writing end of first pipe 
  
        // Read a string using first pipe 
        int digits ; 
        int result = 0;
        read(fd1[0], &digits , sizeof(digits)); 
	
  
        // Concatenate a fixed string with it 
	int x = digits;
	while(digits>0)
	{
		x = digits % 10;
		
		if(x % 2 == 1)
			result += x;
		digits = digits / 10;		
	}
       
        // Close both reading ends 
        close(fd1[0]); 
        close(fd2[0]); 
  
        // Write concatenated string and close writing end 
        write(fd2[1], &result, sizeof(result)); 
        close(fd2[1]); 
  
        exit(0); 
    } 
} 
        
