#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

int tokenise(char str[], int start, char result[])
{
    int i;
    int j=0;s

     for(i=start; str[i] != '\0'; i++)
	 {

        result[j]=str[i];
        j=j+1;
        if(str[i]==' ' && str[i+1] !=' ')
        {
          return i+1;
        }
		

    }
    return -1;
}





struct stack {
	double size[0];
	int top;
}
st;

void push(double number)
{
	st.top++;
	st.size[st.top]=number;
}

double pop()
{
	double item;
	item = st.size[st.top];
	st.top--;
	return (item);
}
int isEmpty()
{
	if(st.top<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Display()
{
	if(isEmpty()==1)
	{
		printf("%s\n", "STACK EMPTY!!!");
	}
	for (int i = st.top; i > 0; i--)
	{
		printf("%f\n", st.size[i]);
	}
}









int main()
{
	
    int MAX_STRING=256;
    char line[256];
	char result[256];
    fgets(line, MAX_STRING, stdin);
	int start=0;
	double resultN =0;

	while(start!=-1)
	{
		
		
    	for(int i=0; i<256; i++)
    	{
        	result[i]='\0';
  		}
  		
		start=tokenise(line, start, result);
		
		
		if(isdigit(result[0]))
		{
			char *ptr;
			double numberPush=strtod(&result[0], &ptr);
			push(numberPush);
		}
		else if( result[0]=='-' && isdigit(result[1]))
		{
			char *ptr;
			double numberPush=strtod(&result[0], &ptr);
			
			push(numberPush);
		}
		else
		{
			
			double number1= pop();
			double number2= pop();
			
			
			if(result[0]== '+')
			{
				double result= number1+number2;
				push(result);
			}
			else if(result[0]== '-')
			{
				double result= number2-number1;
				push(result);
			}
			else if(result[0]== 'x')
			{
				double result= number1*number2;
				push(result);
			}
			else
			{
				double result= number2/number1;
				push(result);
			}
			
		}
	}

	Display();
	
	return 0;
}
	
	
