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
    
    void minHeapify(int index)
    {
        //for comparing
        int left_child_index = getLeftChild(index);
        int right_child_index = getRightChild(index);
        int smallest = index;
        
        if(left_child_index < size && array[left_child_index] < array[index])
            smallest = left_child_index;
            
        if(right_child_index < size && array[right_child_index] < array[index])
            smallest = right_child_index;
            
        //check if the root itself it smalled index, if so don't do anything because we assume
        // the given index only violates the min heap property
        if(smallest != index)
        {
            swap(array[index],array[smallest]);
            minHeapify(smallest);
        }
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
