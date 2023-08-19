void findSum(vector<int> &candidates, int start, int target, vector<int> &current, vector<vector<int>> &result) 
{
    if (target == 0) 
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) 
    {
        if (i > start && candidates[i] == candidates[i - 1]) 
            continue; // Skip duplicates

        if (candidates[i] > target) 
            break; // No need to continue, candidates are sorted

        current.push_back(candidates[i]);
        findSum(candidates, i + 1, target - candidates[i], current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    findSum(candidates, 0, target, current, result);
    return result;
}
