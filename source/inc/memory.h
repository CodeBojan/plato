#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include "types.h"

int callocate(BUFFER* out_buffer, int size);
int mallocate(BUFFER* out_buffer, int size);
int reallocate(BUFFER* out_buffer, int new_size);

#endif