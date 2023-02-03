class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    unordered_set<int> s;
	    
	    s.insert(arr[0]);
	    
	    for(int i=1;i<n;i++) {
	        int diff = x - arr[i];
	        
	        if(s.find(diff) != s.end()) {
	            return true;
	        }
	        
	        s.insert(arr[i]);
	    }
	    
	    return false;
	}
};