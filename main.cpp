#include "Allocator.h"

int main()
{
    Allocator AL;
    AL.create(10);

    int* ptr;
    int i = 0;
    for (int* n : AL.FreeBlocks)
    {
        printf ("FreeBlock %d - pointer %p\n", i, ptr);
        i++;
    }

    AL.allocate(11);
    printf("\nALLOCATED\n");
    i = 0;
    for (int* n : AL.FreeBlocks)
    {
        printf ("FreeBlock %d - pointer %p\n", i, ptr);
        i++;
    }

    AL.free();
    printf("\nFREE\n");
    i = 0;
    for (int* n : AL.FreeBlocks)
    {
        printf ("FreeBlock %d - pointer %p\n", i, ptr);
        i++;
    }

    AL.destoy();

    
}