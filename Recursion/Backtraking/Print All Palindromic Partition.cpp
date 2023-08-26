#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& s)
{
	int n = s.size();
	int i = 0, j = n - 1;
	while (i < j) 
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
	
void Partition(vector<vector<string>> &res, string &s, int current_index, vector<string> &curr)
{
	if (current_index == s.size()) 
	{
		res.push_back(curr);
		return;
	}
		
	string t = "";
	for (int i = current_index; i < s.size(); i++) 
	{
    	t = t+s[i];
		if (checkPalindrome(t)) 
		{
			curr.push_back(t);
            Partition(res, s, i + 1, curr);
			curr.pop_back();
		}
	}
}

int main()
{
	vector<vector<string> > res;
	string s = "aabb";

	int current_index = 0;
	vector<string> curr;
	Partition(res, s, current_index, curr);
	
	for (auto& v : res) 
	{
		for (auto& it : v) 
			cout << it << " ";
		cout << "\n";
	}
	return 0;
}
