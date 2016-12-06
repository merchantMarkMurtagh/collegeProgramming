#include <stdio.h>

int tokenise(char str[], int start, char result[])
{
    int i;
    int j=0;

     for(i=start; str[i] != '\0'; i++){

        result[j]=str[i];
        j=j+1;
        if(str[i]==' ' && str[i+1] !=' ')
        {
          return i+1;
        }

    }
    return -1;
}

int main()
{

    int MAX_STRING=256;
    char line[256];
    fgets(line, MAX_STRING, stdin);
    char result[256];
    int start=0;


    while(start !=-1){
      for(int i=0; i<256; i++)
      {
          result[i]='\0';
	  }
	  start=tokenise(line, start, result);
	  printf("%s\n", result);


	}
	return 0;
}	   