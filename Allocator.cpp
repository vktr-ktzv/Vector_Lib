#include "Allocator.h"

void Allocator::create(size_t size)
{
    this->AllocMem = new int[size*BLOCKSIZE];

    int* it = AllocMem;
    while (it < &this->AllocMem[size*BLOCKSIZE])
    {
        FreeBlocks.push_front (it);
        it += BLOCKSIZE;
    }

    this->start = this->AllocMem;
    this->end = this->AllocMem + sizeof(int)*(size*BLOCKSIZE);
}

void* Allocator::allocate(size_t blocksize)
{
    int blockamount;
    if (blocksize % BLOCKSIZE)
    {
        blockamount = blocksize / BLOCKSIZE +1;
    }

    else
    {
        blockamount = blocksize / BLOCKSIZE;
    }


    if (blockamount < this->FreeBlocks.size())
    {
        int* ptr = this->FreeBlocks.front();
        for (int i = 0; i < blockamount; i++)
        {
            this->FreeBlocks.pop_front();
        }

        return ptr;
    }
    else
    {
        printf("No more data..\n");
        return nullptr;
    }

}

void  Allocator::deallocate(int* block, int blocklen)
{
    this->FreeBlocks.push_front(block);
}

void  Allocator::free()
{
    this->FreeBlocks.clear();

    for (int i = 0; i < ALLOCSIZE; i++)
    {
        this->FreeBlocks.push_front(this->AllocMem + i*BLOCKSIZE);
    }
}

void  Allocator::destoy()
{
    this->FreeBlocks.clear();
    delete (this->AllocMem);

    printf("\nDeleted\n");
}