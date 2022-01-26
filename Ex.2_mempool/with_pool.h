#include <iostream>
#include <chrono>
using namespace std;

int data[4096];
class PoolData
{
public:

    //The new operator denotes a request for
    //memory allocation on the Free Store.
    //If sufficient memory is available, new operator initializes the
    //memory and returns the address of the newly allocated and initialized
    //memory to the pointer variable.

    void *operator new(size_t Size)
    {
        return (void *)data;
    }
    void operator delete(void *p)
    {
    }
};

void PoolAllocation()
{
  auto start = chrono::steady_clock::now();
  for(int i=0; i<1000000; i++)
  {
      PoolData *p = new PoolData;
      delete p;
  }
      auto end = chrono::steady_clock::now();
      cout<<"Duration of Pool allocation = "<<  chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}
