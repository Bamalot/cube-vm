#ifndef CUBE_VM_H
#define CUBE_VM_H

#include <stdlib.h>

/*
Type definitions for customization
*/
#define CVM_INT signed long long
#define CVM_FLOAT double
#define CVM_SIZE_TYPE size_t
#define CVM_HANDLE struct CUBE_VM*
#define CVM_OBJECT_HANDLE struct CVM_OBJECT*

// Various types a CubeVM object could be
enum CVM_OBJECT_TYPE {
    CVM_OBJECT_INT,
    CVM_OBJECT_FLOAT,
};

/* 
    Struct representing a CubeVM object, consisting of data and a type
    The type should be checked before accessing the data
*/
struct CVM_OBJECT {
    union {
        CVM_FLOAT data_float;
        CVM_INT data_int;
    };
    enum CVM_OBJECT_TYPE object_type;
};

/* The VM itself. It keeps track of the top and size of the stack.*/
struct CUBE_VM {
    CVM_SIZE_TYPE stack_size;
    struct CVM_OBJECT* stack;
    CVM_SIZE_TYPE top;
};


// Creates a new VM. "stack_size" is not in bytes, but rather object count
CVM_HANDLE create_cube_vm(CVM_SIZE_TYPE stack_size);
// Cleans up the memory of the vm
void destroy_cube_vm(CVM_HANDLE handle);
// Returns the object on top of the stack
CVM_OBJECT_HANDLE cvm_get_top(CVM_HANDLE handle);
// Returns an object at any position in the stack. 0 = bottom of the stack, and negative indices start from the top. -1 = top
CVM_OBJECT_HANDLE cvm_get_object(CVM_HANDLE handle, CVM_INT stack_index);
// Pushs an Int object onto the stack
CVM_OBJECT_HANDLE cvm_push_int(CVM_HANDLE handle, CVM_INT obj);

CVM_OBJECT_HANDLE _cvm_get_next_stack_ptr(CVM_HANDLE handle);

#endif