#include <bits/stdc++.h>
using namespace std;

class Heap
{
    private:
        int *array;
        int size;
        int capacity;
    public:
    
    Heap(int capacity)
    {
        array = new int[capacity];
        size = 0;
        this->capacity = capacity; 
    }
    
    void insertElement(int element)
    {
        if(size ==  capacity)
            return;
            
        size++;
        array[size-1] = element;
        
        for(int i=size-1; i !=0 && array[getParent(i)]>array[i];)
        {
            swap(array[i],array[getParent(i)]);
            i = getParent(i);
        }
    }
    
    int getLeftChild(int index)
    {
        return (2*index+1);
    }
    
    int getRightChild(int index)
    {
        return (2*index+2);
    }
    
    int getParent(int index)
    {
        return floor((index-1)/2);
    }
    
    void printHeap()
    {
        for(int i=0;i<size;i++)
            cout<<array[i]<<" ";
    }
    
    
};

int main()
{
    Heap H(10);
    H.insertElement(3);//, 10, 12, 8, 2, 14)
    H.insertElement(2);
    H.insertElement(15);
    H.insertElement(20);
    H.insertElement(1);
    H.insertElement(5);
    H.insertElement(30);
    H.printHeap();
    
    
}
