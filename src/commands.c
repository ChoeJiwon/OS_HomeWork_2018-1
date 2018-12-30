#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))	//ch success -> !validate:0 -> return 0
    return -1;

  return 0;				//ch error
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))	//pwd success : !validate = 0 ->return 0
    return -1;

  return 0;				//pwd error
}


int validate_cd_argv(int argc, char** argv) {
	if(chdir(argv[1])) return 0;	//ch success : return 0 -> return 1
					//return 1 : !validate -> 0 
	return 1;
}

int validate_pwd_argv(int argc, char** argv) {
	char buf[8096];
	char *a;
	a = getcwd(buf,8096);		//getcwd success : not NULL
	if(a){				//execution
	printf("%s\n",buf);		//practically It is do_pwd
	return 1;			// => return 1
	}

  return 0;
}

