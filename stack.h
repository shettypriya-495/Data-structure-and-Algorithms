#ifndef _INCLUDED_STACK_
#define _INCLUDED_STACK_
#ifndef _STACK_CONTENT_TYPE_
#define _STACK_CONTENT_TYPE_ char
#endif
#define MAX_DEPTH 32
#include <stdint.h>

typedef struct _STACK_ stack;
typedef struct _STACK_RESULT_ stack_result;

struct _STACK_
{
	uint32_t size;
	int32_t top;
	_STACK_CONTENT_TYPE_ data[MAX_DEPTH];
};
struct _STACK_RESULT_
{
	_STACK_CONTENT_TYPE_ data;
	int32_t status;

};

#define STACK_OK 0
#define STACK_FULL 1
#define STACK_EMPTY 2

/*public interfaces*/
stack stack_new(uint32_t size);
uint32_t stack_full(const stack *stk);
uint32_t stack_empty(const stack *stk);
stack* stack_push(stack *stk, _STACK_CONTENT_TYPE_ ele, stack_result *res);
stack* stack_pop(stack *stk, stack_result *res);
stack* stack_peek(stack *stk, stack_result *res);

#endif