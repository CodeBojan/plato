#include "memory.h"
#include "types.h"

/*an idea: I can store the pointer to the allocated buffers internally as a global var (hash table? or array)
and when the program shuts down, init a sequence that will free them? is that possible?
*/

int callocate(BUFFER* out_buffer, int size){
    /*
        If there was something previously allocated, deallocate it?
        Question: what if this is not dynamic memory?
        Answer: nothing good. DO NOT PASS POINTERS POINTING TO STATIC memory HERE
    */
    out_buffer->_memory = (char*)calloc(size, sizeof(char));
    out_buffer->_size = size;
    if(out_buffer->_memory == NULL)
        return -1;
    out_buffer->_size = size;
    return 1;
}

int mallocate(BUFFER* out_buffer, int size){
    out_buffer->_memory = (char*)malloc(size * sizeof(char));
    out_buffer->_size = size;
    if(out_buffer->_memory == NULL)
        return -1;
    return 1;
}

int reallocate(BUFFER* out_buffer, int size){
    out_buffer->_memory = (char*)realloc(out_buffer->_memory, size * sizeof(char));
    out_buffer->_size = size;
    if(out_buffer->_memory == NULL)
        return -1;
    return 1;
}

//TODO: add a type parameter that is going to allocate a certain type of buffer, not just char!
//SOLUTION: set of functions per type. For more details, see 10.6.2025.
BUFFER* alloc_buffer(int size){
    BUFFER* buffer;
    if(mallocate(buffer, size) == 1)
        return buffer;
    return NULL;
}

int realloc_buffer(BUFFER* buffer, int new_size){
    if(reallocate(buffer, new_size)){
        return 1;
    }
    //log failure
    return -1;
}

void free_buffer(BUFFER* buffer){
    free(buffer->_memory);
}

BUFFER** allocate_buffer_matrix(int length, int size){
    BUFFER** matrix;
    matrix = alloc_buffer(length);
    char failed = 0;
    for(int i = 0; i < length; i++){
        matrix[i] = alloc_buffer(size);
        if(matrix[i] == NULL){
            //log failure
            failed = 1;
            break;
        }
    }
    if(failed)
        return NULL;
    return matrix;
}