/* 
   First check if the current number is greater than largest,
   if so, assign the second_largest as largest and largest as current_element
   if current element if less than largest but greater than second_largest,
   then assign second largest as current element.
*/
  
int print2largest(int array[], int n) 
	{
	    int largest = -1;
	    int second_largest = -1;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(array[i] > largest)
	        {
	            second_largest = largest;
	            largest = array[i];
	        }
	        else if(array[i] < largest)
	        {
	            if(array[i] > second_largest)
	                second_largest = array[i];
	        }
	    }
	    return second_largest;
	}
