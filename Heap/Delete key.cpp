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
        
        if(left_child_index < size && array[left_child_index] < array[smallest])
            smallest = left_child_index;
            
        if(right_child_index < size && array[right_child_index] < array[smallest])
            smallest = right_child_index;
            
        //check if the root itself it smalled index, if so don't do anything because we assume
        // the given index only violates the min heap property
        if(smallest != index)
        {
            swap(array[index],array[smallest]);
            minHeapify(smallest);
        }
    }
    
    int extractMinimum()
    {
        if(size == 0)
            return INT_MAX;
        
        if(size == 1)
        {
            size--;
            return array[0];
        }
        
        swap(array[0],array[size-1]);
        size--;
        minHeapify(0);
        return array[size];
    }
    
    //decrease the value at a given index
    void decreaseKey(int index, int key)
    {
        array[index] = key;
        while(index != 0 && array[getParent(index)] > array[index])
        {
            swap(array[index],array[getParent(index)]);
            index = getParent(index);
        }
    }
    
    //delete an element from given index, changes that to - infinite using decreaseKey, then calls extractMinimum
    void deleteKey(int index) 
    { 
        decreaseKey(index, INT_MIN); 
        extractMinimum(); 
    }
};

int main()
{
    Heap H(10);
    H.insertElement(3);
    H.insertElement(2);
    H.insertElement(15);
    H.insertElement(20);
    H.insertElement(1);
    H.insertElement(5);
    H.insertElement(30);
    
    H.decreaseKey(7,7);
    H.deleteKey(2);
    H.printHeap();
    
    
}
