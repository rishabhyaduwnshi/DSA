

double minimiseMaxDistance(vector<int> &arr, int k)
{
	
	int n = arr.size();
	vector<int> how_many(n-1,0);


	for(int gas_stations=1;gas_stations<=k;gas_stations++)
	{
		long double max_section = -1;
		int max_index = -1;

		for(int spaces=0;spaces<n-1;spaces++)
		{
			long double difference = (arr[spaces+1] - arr[spaces]);
			long double section_length = (difference/(long double)(how_many[spaces]+1));

            if (section_length > max_section) 
			{
                max_section = section_length;
				max_index = spaces;
            }
        }

		how_many[max_index]++;
	}

	long double max_answer = -1;
	for(int spaces=0;spaces<n-1;spaces++)
	{
		long double difference = (arr[spaces+1]-arr[spaces]);
		long double section_length = (difference/(long double) (how_many[spaces]+1));
		max_answer = max(section_length,max_answer);
	}

	return max_answer;
}
