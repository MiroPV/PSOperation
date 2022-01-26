#include <iostream>
#include <chrono>
using namespace std;

class SimpleData
{
    int data[4096];
};

void SimpleAllocation()
{
    auto start = chrono::steady_clock::now();
    for(int i=0; i<1000000; i++)
    {
        SimpleData *p = new SimpleData;
        delete p;
    }
    auto end = chrono::steady_clock::now();
    cout<<"Duration of Simple allocation = "<<  chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}

