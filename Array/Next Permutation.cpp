vector<int> nextPermutation(int N, vector<int> array)
    {
        int index = -1;

        //finds out the index at which the next element is greater than the current element, if there is nothing that means
        // array is sorted and reverse and return
        for(int i=N-2;i>=0;i--)
        {
            if(array[i] < array[i+1])
            {
                index = i;
                break;
            }
        }
        
        if(index == -1)
        {
            reverse(array.begin(),array.end());
            return array;
        }

        //finds the element which is greater than array[index] and swaps
        for(int i=N-1;i>index;i--)
        {
            if(array[i] > array[index])
            {
                swap(array[i],array[index]);
                break;
            }
        }
        
        reverse(array.begin()+index+1,array.end());
        return array;
    }
