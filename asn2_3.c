#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
/*
AUTHOR:KOWSHIK P N & MALLIKARJUN KALYANSHETTI.
GOAL:VALIDATE THE USERNAME AND PASSWORD USING FILES.
*/
int main(int argc,char **argv)
{
	char *cvalue1=NULL;
	char *cvalue2=NULL;
	int c;
while((c=getopt(argc,argv,"f:l:"))!=-1)
switch(c)
{
case 'f': cvalue1=optarg;
	  break;
			   
case 'l':  cvalue2=optarg;
	   break;

default:  printf("Please enter as -f <input_file> -l <log_File> \n");
           return 1;
}
	int count;
	FILE *f1,*f2;
	int i=0,j=0;
	int flag=0;
char username[30],password[30];	
for(count=0;count<3;count++)
{

	f1=fopen(cvalue1,"r");
	f2=fopen(cvalue2,"a");
	if(f1==NULL || f2==NULL)
	{
		printf("Error in opening the file\n");                 
		break;
	}	
	printf("Enter the username\n");
	scanf("%s",username);
	printf("Enter the password\n");
	scanf("%s",password);
	printf("\n");
	
	while(!feof(f1))
	{
	
	char user[100];
	char pass[100];
	char str1[100];
	fscanf(f1, "%s", str1 );
	i=j=0;
	
		while(str1[i]!=',')
		{
			user[i]=str1[i];
			i++;
		}
		user[i]='\0';
		i++;
		while(str1[i]!='\0')
		{
			pass[j]=str1[i];
			j++;
			i++;
		}
		pass[j]='\0';
	
		if(strcmp(username,user)==0 && strcmp(password,pass)==0)
		{
			flag=1;
			break;
		}
	  }


		
	if(flag==1)
	{
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fprintf( f2,"Valid Input Recieved: %s %s\n", asctime (timeinfo),username);
	fprintf( f2,"Output Displayed: %s\n", asctime (timeinfo));
	fclose(f1);
	fclose(f2);
	printf("Welcome <%s>!!\n",username);
	break;
	}
	else
	{
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fprintf( f2,"Invalid Input Recieved: %s %s\n", asctime (timeinfo),username);
	fprintf( f2,"Output Displayed: %s\n", asctime (timeinfo));
	fclose(f1);
	fclose(f2);
        printf("Invalid Username/Password,Try Again.\n");	   
	}
}
if(count==3)
printf("Maximum Attempts exceeded!!\n");
return 0;
}
