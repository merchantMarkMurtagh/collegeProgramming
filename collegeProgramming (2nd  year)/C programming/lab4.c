#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

int tokenise(char str[], int start, char result[])
{
    int i;
    int j=0;

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


struct charStack {
	char size[1];
	int top;
}
stChar;

void pushC(char operator)
{
	stChar.top++;
	stChar.size[stChar.top]=operator;
	


}

char popC()
{
	
	char item = stChar.size[stChar.top];
	stChar.top--;
	return (item);
}
int isEmptyC()
{
	if(stChar.top<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void DisplayC()
{
	if(isEmptyC()==1)
	{
		printf("%s\n", "STACK EMPTY!!!");
	}
	for (int i = stChar.top; i > 0; i--)
	{
		printf("%c\n", stChar.size[i]);
		printf("%s\n", " ");
		
		
	}
	
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
	for (int i = st.top+1; i > 0; i--)
	{
		printf("The result is: %f\n", st.size[i]);
		
	}
}




int higherP(char operator)
{
	int precedenceValue=0;
	if(operator=='+')
	{
		return precedenceValue=1;
	}
	else if(operator=='-')
	{
		return precedenceValue=1;
	}
	else if(operator=='x')
	{
		return precedenceValue=2;
	}
	else if(operator=='/')
	{
		return precedenceValue=2;
	}
	return 0;
		
}

int isOperator(char oper)
{
	if(oper=='+' || oper=='-' || oper =='x' || oper == '/')
	{
		return 1;
	}
	else
	{ 
		return 0;
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
	char outputString[256];
	
	char space = ' ';
	
	
	
	while(start!=-1)
	{
		//printf("%s\n", outputString);
		for(int i=0; i<256; i++)
     	{
         	result[i]='\0';
  		}
		
		start=tokenise(line, start, result);
		
		
		if(isdigit(result[0]))
		{
			strcat(outputString, &result[0]);
			strcat(outputString, &space);
			
			
		}
		else if(result[0]=='(')
		{
			pushC('(');
			
		}
		else if(result[0]=='+' || result[0]=='-' || result[0]=='x' || result[0]== '/')  
		{
			
			int stackValue = higherP(stChar.size[stChar.top]);
			int compareValue = higherP(result[0]);
			
			
			while(isOperator(stChar.size[stChar.top])==1 && stackValue>compareValue)
			{
				
				char popOp= popC();
				strcat(outputString, &popOp);
				strcat(outputString, &space);
				stackValue= higherP(stChar.size[stChar.top]);
				
			}
			pushC(result[0]);
			
		}
		else if(result[0]==')')
		{
			
			while(stChar.size[stChar.top] != '(') 
			{
				
				char popOpTwo =popC();
				strcat(outputString, &popOpTwo);
				strcat(outputString, &space);
				
				
			}
			popC();
		}
	}
	
	while(stChar.size[stChar.top] !=0)
	{
		char popOpF= popC();

		strcat(outputString, &popOpF);
		strcat(outputString, &space);
	}
	
	printf("The output String is: %s\n", outputString);
	start=0;
	
	while(start!=-1)			//Where polish notation starts.
	{


	    	for(int i=0; i<256; i++)
	    	{
	        	result[i]='\0';
	  		}

		start=tokenise(outputString, start, result);



		if(isdigit(result[0]))
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
	
	
