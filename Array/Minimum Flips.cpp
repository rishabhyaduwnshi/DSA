#include <bits/stdc++.h>
using namespace std;


void minimumFlips(int array[], int size)
{
    for(int i=1;i<size;i++)
    {
        if(array[i] != array[i-1])
        {
            if(array[i] != array[0])
                cout<<"From "<<i<<" to ";
            else
                cout<<(i-1)<<"\n";
        }
    }
    
    if(array[size-1] != array[0])
        cout<<(size-1)<<"\n";
}



int main()
{
    int array[] = {1,1,0,0,0,1,1,0,0,1};
    int size = sizeof(array)/sizeof(int);
    minimumFlips(array,size);
    return 0;
}
