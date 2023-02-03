#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2, int m, int n) {
    int grid[m+1][n+1], result = 0, endindex;
    
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i == 0 || j == 0) {
                grid[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) { //if they match

                grid[i][j] = grid[i-1][j-1] + 1; //top-left element + 1
                //result = max(result, grid[i][j]);

                //update result if we find a greater substring
                //and also store the endindex
                if(grid[i][j] > result) {
                    result = grid[i][j];
                    endindex = i; //1-based index
                }
            }
            else{ //if they don't match
                grid[i][j] = 0;
            }
        }
    }

    // time & space complexity = O(m * n)
    
    //we're storing the value of i in endindex, so we need to find the substring in s1.
    //result stores the length of the longest common substring
    //so (endindex of the LCS - length of the LCS) will give the starting pos of LCS 

    //cout << s1.substr(endindex - result, result) << endl;
    //substr(startpos, length)

    return result;
}

int main() {
    int t, m, n;
	string s1, s2;
	
	cin >> t;
	
	while(t--) {
	    cin >> m >> n;
	    cin >> s1;
	    cin >> s2;
	    
	    cout << longestCommonSubstring(s1, s2, m, n) << endl;
	}
	
	return 0;
}