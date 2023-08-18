long long power(int N, int R) 
{
    if (R == 0)
        return 1;
        
    long long halfPower = power(N, R / 2) % 1000000007;
    
    if (R % 2 == 1)
        return (N * ((halfPower * halfPower) % 1000000007)) % 1000000007;
    else
        return (halfPower * halfPower) % 1000000007;
}
