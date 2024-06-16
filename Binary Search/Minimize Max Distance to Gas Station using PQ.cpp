double minimiseMaxDistance(vector<int> &arr, int k)
{
	
	int n = arr.size();
	vector<int> how_many(n-1,0);

	priority_queue<pair<long double, int>> pq;
	for(int i=0;i<n-1;i++)
		pq.push({arr[i+1]-arr[i],i});

	for(int gas_stations=1;gas_stations<=k;gas_stations++)
	{
		auto top_element = pq.top();
		pq.pop();

		int current_section_index = top_element.second;
		how_many[current_section_index]++;

		long double initial_difference = arr[current_section_index+1] - arr[current_section_index];
		long double current_section_length = initial_difference/ (long double)(how_many[current_section_index]+1);
		pq.push({current_section_length,current_section_index});
	}

	return pq.top().first;
}
