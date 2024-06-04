int subsetXOR(vector<int> a, int n, int k) 
{
        int current_xor = 0;
        map<int,int> xor_map;
        xor_map[current_xor] = 1;
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            current_xor = current_xor^a[i];
            int complement_xor = current_xor^k;
            count += xor_map[complement_xor];
            xor_map[current_xor]++;
        }
        
        return count;
}
