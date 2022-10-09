#include <iostream>
#include <new>

class Vector
{
    private:
        int* dyn_arr;

    public:
        Vector();
        ~Vector();


        void* operator new (size_t size, int line);
        void operator delete (void* ptr);

};

void* operator new (size_t size, int line)
{
    int* ptr = (int*)calloc (1, sizeof(int)+size);

    if (line)
    {

    }
}