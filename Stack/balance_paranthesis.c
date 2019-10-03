#include"stack.h"
#include"stack.c"
#include<stdio.h>
#include<string.h>
uint32_t isMatching(char char1, char char2)
{
	if (char1 == '(' && char2 == ')') 
     return 1; 
   else if (char1 == '{' && char2 == '}') 
     return 1; 
   else if (char1 == '[' && char2 == ']') 
     return 1; 
   else
     return 0; 
}
void print_stack(stack *stk)
{
	for(int i=0; i<stk->size;i++)
	{
		printf("%s\t",&stk->data[i] );
	}
}
uint32_t balanced_paranthesis(char *str, stack *stk, stack_result *res)
{
	//assert(str!='\0');  //what if the null string as input
	for(int i=0;i<strlen(str);i++)
	{
		if((str[i]=='{') || (str[i]=='[')||(str[i]=='('))
		{
			stk=stack_push(stk,str[i], res);
		}
		else if((str[i]=='}') || (str[i]==']')||(str[i]==')'))
		{
			
			if(stk==NULL)
			{
				return 0;
			}
			else 
			{
              stk=stack_pop(stk,res);
              
              //printf("%c\t",res->data );
              if(!isMatching(res->data,str[i]))
              {
              	return 0;
              }
			}	//chech the top element i the stack and if matches pop else retutn false
		} 
	}
	    //printf("%d\n",stk->top );
		return (stack_empty(stk)==1);
}


int main()
{
	char str[]="{{{[{]}}}}";
	stack s=stack_new(8);
	stack *stk=&s;
	stack_result res;
	if(balanced_paranthesis(str,stk,&res))
	{
		printf("Balanced\n");
	}
	else
	{
		printf(" Not Balanced\n");
	}
	
    return 0;
}