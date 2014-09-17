#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
void updatefile(char[],char[],char[]);
/*
 * AUTHORS:KOWSHIK_P_N - 1PI12IS042 and MALLIKARJUN_KALYANSHETTI - 1PI12IS051.
 * GOAL:VALIDATE THE USERNAME AND PASSWORD USING FILES AND TO LOG THE INFORMATION IN A LOGFILE.
 * FUNCTIONS: 
 	-> main() => asks user to enter his/her login crediantals
 	-> updatefile() => upfates the last login time in the file containing user details.
 */
int main(int argc,char **argv)
{
	char *agr_var1=NULL;
	char *agr_var2=NULL;
	int c;
	while((c=getopt(argc,argv,"f:l:"))!=-1)
		switch(c)
		{
			case 'f': agr_var1=optarg;
				  break;
						   
			case 'l': agr_var2=optarg;
				   break;

			default:  printf("Please execute the program as \"./a.out -f <input_file> -l <log_File>\"\n");
					  return 1;
	}
	int count;
	FILE *user_file,*log_file;
	int i=0,j=0,k=0;
	int flag=0;
	char username[30],password[30];	
	for(count=0;count<3;count++)
	{

		user_file=fopen(agr_var1,"r");
		log_file=fopen(agr_var2,"a");
		if(user_file==NULL || log_file==NULL)
		{
			printf("Error in opening the file\n");                 
			break;
		}	
		printf("Enter the username : ");
		scanf("%s",username);
		printf("Enter the password : ");
		scanf("%s",password);
		printf("\n");
		char date[50];
		char dest[50];
		while(!feof(user_file))
		{
			char user[25];
			char pass[25];
			char str1[100];
	
			fgets(str1,100,user_file);
			i=j=k=0;
	
				while(str1[i]!=',')
				{
					user[i]=str1[i];
					i++;
				}
				user[i]='\0';
				i++;

				while(str1[i]!=',')
				{
					pass[j]=str1[i];
					j++;
					i++;
				}
				pass[j]='\0';
				i++;
				while(str1[i]!='\0')
				{
					date[k]=str1[i];
					k++;
					i++;
				}
				date[k]='\0';
				strcpy(dest,date);
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
			fprintf( log_file,"%s : Logged in by <%s>", asctime (timeinfo),username);
			updatefile(agr_var1,dest,asctime(timeinfo));
			printf("Welcome <%s> !!\n",username);
			printf("Last Login time:%s",dest);
			fprintf(log_file,"%s : Last login time displayed", asctime (timeinfo));
			fclose(user_file);
			fclose(log_file);
			break;
		}
		else
		{
			time_t rawtime;
			struct tm * timeinfo;
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			fprintf( log_file,"\n%s : Invalid input by %s\n", asctime (timeinfo),username);
			fclose(log_file);
			if(count!=3)
				printf("Invalid Username/Password , please try again.\n");	   
		}
	}
	if(count==3)
	printf("Maximum number of attempts exceeded!!\n");
	return 0;
}

void updatefile(char InputFileName[],char Find[],char Replace[])
{
    char Buffer[4096];
    char *TemporaryFileName = "temp.txt";
    int line = 0;
    FILE *Input,*Output;
    Input = fopen(InputFileName, "r");
    Output = fopen(TemporaryFileName, "w");
    while(NULL != fgets(Buffer, 4096, Input))
    {
        char *Stop = NULL;
        char *Start = Buffer;
        while(1)
        {
            Stop = strstr(Start, Find);
            if(NULL == Stop)
            {
                fwrite(Start, 1, strlen(Start), Output);
                break;
            }
            fwrite(Start, 1, Stop - Start, Output);
            fwrite(Replace, 1, strlen(Replace), Output);
            Start = Stop + strlen(Find);
        }
        line++;
    }
    fclose(Input);
    fclose(Output);
    remove(InputFileName);
    rename(TemporaryFileName, InputFileName);
}
