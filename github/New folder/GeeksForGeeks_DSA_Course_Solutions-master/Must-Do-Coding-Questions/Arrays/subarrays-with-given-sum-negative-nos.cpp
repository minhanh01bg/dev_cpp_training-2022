// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1

// Editorial: https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/


class Solution
{
  public:
    int subArraySum(int arr[], int n, int sum)
    {
        // we have to use both hashing and prefix sum technique to solve this problem.
        // the idea is to store the prefix sum for every position in a hashmap
        // and add the count of their occurences as the corresponding value
    	unordered_map<int, int> m;
    	int count = 0, currsum = 0;
    	
    	for(int i=0;i<n;i++) {
    	    
    	    currsum += arr[i]; // get current sum
    	    
    	    // if current sum is equal to the given sum
    	    if(currsum == sum) {
    	        count++;
    	    }
    	    
    	    // currsum exceeds sum by (currsum - sum)
    	    // So, find the number of subarrays having sum equal to (currsum - sum)
    	    // and add that count 
    	    if(m.count(currsum - sum) != 0) {
    	        count += m[currsum - sum];
    	    }
    	    
    	    // add respective count to prefix sum
    	    m[currsum]++;
    	}
    	
    	return count;
    	
    	/**
         * Example: 
         * n = 6
         * arr = [9 4 20 3 10 5]
         * sum = 33
         * answer = 2 i.e. [9 4 20] and [20 3 10]
         * 
         * prefix sum array = [9 13 33 36 46 51]
         * 
         * when currsum = 46 then (currsum - sum) = 13
         * 13 is then present in the hashmap and its count is 1 due to [9 4]
         * So, if we remove [9 4] = 13 from [9 4 20 3 10] = 46, we get [20 3 10] = 33
         * which is our given sum
         * 
         * This way we use prefix sum and hashing techniques to solve this problem
         * **/
    }
};