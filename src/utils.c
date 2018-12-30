#include "utils.h"
#include <string.h>
#include <stdlib.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char *ptr;
	*argc = 0;
	int num =0;
        argv[0]=(char**)malloc(sizeof(char*)*5);
        for(int i=0;i<5;i++){
                argv[0][i]=(char*)malloc(sizeof(char)*30);
        }
        ptr=strtok(command," \n");

        while(ptr!=NULL){
      		strcpy(argv[0][num++],ptr);
                ptr=strtok(NULL," \n");
        }
	*argc = num;
}
