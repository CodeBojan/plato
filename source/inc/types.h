#ifndef TYPES_H
#define TYPES_H

//all fields are PRIVATE.
typedef struct buffer{
    char* _memory;   //to be used only for pointing to dynamic memory
    int _size;   
} BUFFER;

#endif