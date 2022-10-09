#include <iostream>
#include <list>

#define BLOCKSIZE 4
#define ALLOCSIZE 10
//PoolAllocator
class Allocator
{
private:
    int *AllocMem;
    int *start;
    int *end;

public:

    std::list<int*> FreeBlocks;
    
    Allocator(){};
    ~Allocator(){};

    void create(size_t size);
    void* allocate(size_t blocksize);
    void  deallocate(int* block, int blocklen);
    void  free();
    void  destoy();

};