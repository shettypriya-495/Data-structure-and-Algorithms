#include"stack.h"
#include"stack.c"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int32_t evaluatePostfix(char *exp, stack *stk, stack_result *res) 
{ 
    
    
    for (int32_t i = 0; exp[i]; ++i) 
    { 
        // If the scanned character is an operand (number), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
        {
            stk=stack_push(stk, exp[i] - '0',res); 
        }
  
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            stk= stack_pop(stk,res); 
            int32_t val1=res->data;
            stk = stack_pop(stk,res);
            int32_t val2=res->data; 
            switch (exp[i]) 
            { 
            case '+': stack_push(stk, val2 + val1,res); 
                        break; 
            case '-': stack_push(stk, val2 - val1,res); 
                        break; 
            case '*': stack_push(stk, val2 * val1,res); 
                        break; 
            case '/': stack_push(stk, val2/val1,res); 
                        break; 
            } 
        } 
    } 
 stk=stack_pop(stk,res);
 return res->data;
 } 
 int main() 
{ 
    char exp[] = "231*+9-";
    stack s=stack_new(20);
    stack *stk=&s;
    stack_result res; 
    printf ("postfix evaluation: %d", evaluatePostfix(exp,stk,&res)); 
    return 0; 
} 
