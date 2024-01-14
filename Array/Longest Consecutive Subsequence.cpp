int findLongestConseqSubseq(int array[], int N)
    {
      unordered_set<int> us;
      
      int longest = 1;
      int count = 1;
      
      for(int i=0;i<N;i++)
        us.insert(array[i]);
        
    for(auto it : us)
    {
        if(us.find(it-1) == us.end())
        {
            count = 1;
            int current_element = it;
            
            while(us.find(current_element+1) != us.end())
            {
                count = count+1;
                current_element = current_element+1;
            }
            
            longest = max(longest,count);
        }
    }
    
    return longest;
    }
