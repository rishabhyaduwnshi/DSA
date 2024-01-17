int subarraysWithSumK(vector < int > a, int b) 
{
    map<int,int> st;
    int xor_sum = 0;
    st[0] = 1;
    int count = 0;

    for(int i=0;i<a.size();i++)
    {
        xor_sum = xor_sum^a[i];
        int remaning_xor = xor_sum^b;

        if(st.find(remaning_xor) != st.end())
            count += st[remaning_xor];
        
        st[xor_sum]++;
    }

    return count;
    
}
