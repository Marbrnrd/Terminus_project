#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
 
int cd_home(void)
{
    const char *const home = getenv("HOME");
    if (home){
        printf("chdir(%s) = %d\n", home, chdir(home));
	return chdir(home);
    }
    return -1;
}
 
int main(int argc, char **argv)
{ 
    switch (argc) {
    case 1:
	return cd_home();
        break;
    case 2:
        if (!strcmp(argv[1], "~"))
            return cd_home();
        else{
           printf("chdir(%s) = %d\n", argv[1], chdir(argv[1]));
	   return chdir(argv[1]);
	   // char cwd[PATH_MAX];
	   // if(getcwd(cwd, sizeof(cwd)) != NULL){ 
	//	    printf("Current working dir: %s\n", cwd);
	//	    system(strcat(cwd,
	  //  }
	    //else{
	//	    perror("getcwd() error");
	  //  }
	}
        break;
    default:
        fprintf(stderr, "usage: cd <directory>\n");
        return EXIT_FAILURE;
    }
    //return EXIT_SUCCESS;
}