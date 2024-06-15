int allocate_books(const vector<int>& arr, int allowed_pages) 
{
    int student_count = 1;
    int pages_taken = 0;

    for(int pages : arr) 
    {
        if(pages + pages_taken <= allowed_pages) 
        {
            pages_taken += pages;
        } 
        else 
        {
            student_count++;
            pages_taken = pages;
        }
    }
    
    return student_count;
}

int findPages(const vector<int>& arr, int n, int m) 
{
    if(m > n)
        return -1;
    
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int answer = INT_MAX;

    while(start <= end) 
    {
        int mid = (start+end) / 2;
        int current_students = allocate_books(arr, mid);
        
        if(current_students <= m) 
        {
            answer = min(answer, mid);
            end = mid - 1;
        } 
        else 
        {
            start = mid + 1;
        }
    }

    return answer;
}
