#include "banker.h"

#define MAX_CUSTOMERS       20
#define MAX_RESOURCE_TYPES  10

static pid_t pids[MAX_CUSTOMERS];
static size_t available[MAX_RESOURCE_TYPES];
static size_t maximum[MAX_CUSTOMERS][MAX_RESOURCE_TYPES];
static size_t allocation[MAX_CUSTOMERS][MAX_RESOURCE_TYPES];