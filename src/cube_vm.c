#include "cube_vm.h"

CVM_HANDLE create_cube_vm(CVM_SIZE_TYPE stack_size)
{
    struct CVM_OBJECT* stack = malloc(stack_size * sizeof(struct CVM_OBJECT));
    CVM_HANDLE vm = malloc(sizeof(struct CUBE_VM));
    vm->stack_size = stack_size;
    vm->stack = stack;
    vm->top = 0;
    return vm;
}

void destroy_cube_vm(CVM_HANDLE handle)
{
    free(handle->stack);
    free(handle);
}

CVM_OBJECT_HANDLE cvm_get_top(CVM_HANDLE handle)
{
    return cvm_get_object(handle, -1);
}

CVM_OBJECT_HANDLE _cvm_get_next_stack_ptr(CVM_HANDLE handle)
{
    return handle->stack + (handle->top);
}
CVM_OBJECT_HANDLE cvm_get_object(CVM_HANDLE handle, CVM_INT stack_index)
{
    if(stack_index >= 0)
    {
        if(stack_index < handle->top)
        {
            return handle->stack + stack_index;
        }
    }
    else
    {
        CVM_INT adjusted_position = handle->top + stack_index;
        if(adjusted_position >= 0)
        {
            return handle->stack + adjusted_position;
        }
    }
    return NULL;
}
CVM_OBJECT_HANDLE cvm_push_int(CVM_HANDLE handle, CVM_INT obj)
{
    CVM_OBJECT_HANDLE object_ptr = _cvm_get_next_stack_ptr(handle);
    object_ptr->data_int = obj;
    object_ptr->object_type = CVM_OBJECT_INT;
    handle->top++;
    return object_ptr;
}