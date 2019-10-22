#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 32

#define takeoff 1
#define landing 0 

typedef struct _heap_ Heap;
typedef struct  _plane_ plane;

struct _plane_
{
	uint32_t time_stamp;
	uint32_t plane_number;
	uint32_t event;
};
struct  _heap_
{
	uint32_t	size;
	plane data[HEAP_MAX_SIZE]	;
};

Heap 	heap_new(plane data[], uint32_t len);
Heap*	heap_insert(Heap *heap, plane *new_plane);
static void _swap_(int32_t *data1, int32_t *data2);
Heap*	Reschedule(Heap *heap, uint32_t time1, uint32_t time2);





#endif
