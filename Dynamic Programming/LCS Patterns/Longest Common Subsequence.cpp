int lcs(string &str1, string &str2, int s1_length, int s2_length, vector<vector<int>> &dp)
{
    if(s1_length == 0 || s2_length == 0)
        return 0;

    if(dp[s1_length][s2_length] == -1)
    {  
        if(str1[s1_length-1] == str2[s2_length-1])
            return dp[s1_length][s2_length] = 1+lcs(str1,str2,s1_length-1,s2_length-1,dp);
        else
            return dp[s1_length][s2_length] = max(lcs(str1,str2,s1_length,s2_length-1,dp),
                                                    lcs(str1,str2,s1_length-1,s2_length,dp));
    }
    else
        return dp[s1_length][s2_length];
}

int longestCommonSubsequence(string text1, string text2) 
{
    vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
    return lcs(text1,text2,text1.length(),text2.length(),dp);   
}
