#ifndef _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_
#define MAX_DEPTH 32
#include <stdint.h>

typedef struct _QUEUE_ queue;
typedef struct _QUEUE_RESULT_ queue_result;

struct _QUEUE_
{
	uint32_t size;
	uint32_t count;
	uint32_t head;
	uint32_t tail;
	int32_t data[MAX_DEPTH];
};
struct _QUEUE_RESULT_
{
	int32_t data;
	int32_t status;

};

#define QUEUE_OK 0
#define QUEUE_FULL 1
#define QUEUE_EMPTY 2

/*public interfaces*/
queue queue_new(uint32_t size);
uint32_t queue_full(const queue *q);
uint32_t queue_empty(const queue *q);
queue* queue_add(queue *q, int32_t element, queue_result *res);
queue* queue_delete(queue *q, queue_result *res);
#endif