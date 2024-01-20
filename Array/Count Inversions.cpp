#include <bits/stdc++.h>

int merge(std::vector<int>& array, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int count = 0;
    std::vector<int> result;

    while (left <= mid && right <= high) 
    {
        if (array[left] <= array[right]) 
        {
            result.push_back(array[left]);
            left++;
        } 
        else 
        {
            //because all the elements from after left to mid is greater than current
            count += (mid - left + 1);
            result.push_back(array[right]);
            right++;
        }
    }

    while (left <= mid) 
    {
        result.push_back(array[left]);
        left++;
    }

    while (right <= high) 
    {
        result.push_back(array[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
        array[i] = result[i - low];

    return count;
    
}

int merge_sort(std::vector<int>& array, int low, int high) {
    int count = 0;
    if (low >= high)
        return count;

    int mid = (low + high) / 2;

    count += merge_sort(array, low, mid);
    count += merge_sort(array, mid + 1, high);
    count += merge(array, low, mid, high);
    return count;
}

int numberOfInversions(std::vector<int>& a, int n) {
    return merge_sort(a, 0, a.size() - 1);
    
}
