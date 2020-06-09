#include "cube_vm.h"
#include <stdio.h>

int main(void)
{
    CVM_HANDLE vm = create_cube_vm(16);
    cvm_push_int(vm, 12);
    CVM_INT obj = 0;
    CVM_OBJECT_HANDLE top = cvm_get_top(vm);
    if(top != NULL)
    {
        obj = top->data_int;
    }
    
    printf("Top: %lld", obj);
    destroy_cube_vm(vm);
}