void permutations(string str, set<string> &result, int last_index,int current_index = 0)
{
    if(current_index == last_index)
	   result.insert(str);
	            
	for(int j=current_index;j<str.length();j++)
	{
	   swap(str[current_index],str[j]);
	   permutations(str,result,last_index,current_index+1);
	   swap(str[current_index],str[j]);
	}
	        
}
	    
vector<string>find_permutation(string S)
{
    set<string> result; //used set for avoiding duplicates
	  vector<string> final_result;
    permutations(S,result,S.length()-1,0);
    for(auto x : result)
	    final_result.push_back(x);
    return final_result;
}
