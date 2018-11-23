#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER 1024


int strtoint(char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("Gecersiz islem\n");
            break;
         }
 }
 return number;
}

int main(int argc, char *argv[],char ** envp)
{
	char line[BUFFER];
	
    char *deger1=(char*) malloc(5*sizeof(char));
	char *deger2=(char*) malloc(5*sizeof(char));
	char *operator=(char*) malloc(5*sizeof(char));
    int a;
	int i;
	pid_t pid;
 
    while(1) {
        printf("myshell >> ");
        if(!fgets(line, BUFFER, stdin)) break;
        char *p = strchr(line, '\n');
        if (p) *p = 0;
        if(strcmp(line, "exit")==0) break;
		char **newargv = (char**)malloc(sizeof(char*)*100);
		int j;
		for(j=0;j<100;j++){
			newargv[j]=(char*) malloc(5*sizeof(char));
		}
		int iter=0;
		char *ch;
		int argCount=0;
		int flag=0;
		  ch = strtok(line, " ");
		  
		  while (ch != NULL) {
				strcpy(newargv[argCount],ch);
				argCount++;
				ch = strtok(NULL," ");
			}
		int count=0;
		int *andLocation=(int*)malloc(sizeof(int)*20);
		for(iter=0;iter<argCount;iter++){
			if(strcmp(newargv[iter],"&")==0){
				andLocation[count]=iter;
				count++;
			}
			else if(strcmp(newargv[iter],"rakam")==0 ||strcmp(newargv[iter],"cat")!=0){
				flag=1;
			}
			else if(strcmp(newargv[iter],"rakam")!=0 ||strcmp(newargv[iter],"cat")==0){
				flag=1;
			}
			else if(strcmp(newargv[iter],"rakam")==0 && strcmp(newargv[iter],"cat")==0){
				flag=2;
			}
			
		}
		
		int whileLoop=0;
		int argFlag=0;
		int locationIter=0;
		int secIterArgFlag=0;
		int andPlace;
		andPlace=andLocation[locationIter]; // iceri alinacak
		while(whileLoop<count+1){
			
			int argsFillIter=0;
			locationIter=count-1;
			if(andPlace==0){
				andPlace=argCount;
			}
			char **arguments=(char**)malloc(sizeof(char*)*3);
			for(j=0;j<3;j++){				
				arguments[j]=(char*) malloc(5*sizeof(char));
			}
			argCount=0;
			for(argFlag=secIterArgFlag;argFlag<andPlace;argFlag++){
				strcpy(arguments[argsFillIter],newargv[argFlag]);
				argCount++;
				argsFillIter++;
			}
				if(flag==1){
					secIterArgFlag=andPlace+1;
					andPlace=andPlace+argCount+1;		
				}else if (flag==2){
					secIterArgFlag=andPlace;
					andPlace=andPlace+argCount-1;
				}
				else{
					secIterArgFlag=andPlace+1;
					andPlace=andPlace+argCount+1;
				}
		int fv=0;

		fv = fork();
		if(fv==0){
			char tmp[10];
			char oper1[5];
			char oper2[5];
			strcpy(oper1,arguments[0]);
			if (argCount==2){
				strcpy(arguments[0],arguments[1]);
				arguments[1]=NULL;
				if(strcmp(oper1,"rakam")==0){
					if(strtoint(arguments[0])!=-1)
					{
						a=execve("rakam",arguments,envp);
					}
				}
				else if(strcmp(oper1,"cat")==0){
						printf("cat: %s\n",arguments[0]);
				}
				else{
					printf("Hatalı parametre girişi.\n");
				}
			
			}
			else if(argCount==3){
			strcpy(arguments[0], arguments[1] );
			strcpy(arguments[1], arguments[2] );
			arguments[2]=NULL;
			if(strcmp(oper1,"mul")==0){ 		
				if(strtoint(arguments[0])!=-1 && strtoint(arguments[1])!=-1)
				{
						i= execve("mul",arguments,envp);
				}
				
			}
			else if(strcmp(oper1,"div")==0){
				if(strtoint(arguments[0])!=-1 && strtoint(arguments[1])!=-1)
				{	
						i= execve("div",arguments,envp);
				}
			}
			else{
					printf("Hatalı parametre girişi.\n");
				}
			}	
		else{
				if(strcmp(oper1,"clear")==0){
					system("clear");
				}
				else if(strcmp(oper1,"exit")==0){
					break;
				}
				else{
					printf("Hatalı parametre girişi.\n");
				}
			}
		}
		
		else{
			wait(&i);			
		}
		whileLoop++;
		}
	}
	return 0;
}