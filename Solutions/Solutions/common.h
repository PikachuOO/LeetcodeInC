#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <malloc.h>
#include <string.h>

#ifndef NULL
	#define NULL ((void*)0)
#endif
#define FALSE (0)
#define TRUE (1)

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))

typedef unsigned int BOOL;

#endif
