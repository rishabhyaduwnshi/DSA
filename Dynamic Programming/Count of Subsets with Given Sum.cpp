#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> memo;

int countSubsetSum(int subset_array[], int length, int sum)
{
    if (sum == 0)
        return 1;

    if (length == 0)
        return 0;

    string key = to_string(length) + "_" + to_string(sum);
    
    if (memo.find(key) != memo.end())
        return memo[key];

    int includeCurrent = 0, excludeCurrent = 0;

    if (subset_array[length - 1] <= sum)
        includeCurrent = countSubsetSum(subset_array, length - 1, sum - subset_array[length - 1]);

    excludeCurrent = countSubsetSum(subset_array, length - 1, sum);

    memo[key] = includeCurrent + excludeCurrent;
    return memo[key];
}

int main()
{
    int subset_array[] = { 2, 4, 5, 8, 10, 12 };
    int sum = 12;
    int n = sizeof(subset_array) / sizeof(subset_array[0]);

    int count = countSubsetSum(subset_array, n, sum);
    cout << "Number of subsets with sum " << sum << " is: " << count << endl;

    return 0;
}
