int lcs(int m, int n, string s1, string s2){
    int grid[m+1][n+1], result = 0;
    
    // populate the entire grid with zeros
    // the intent here is to fill the first row and first column with zeros
    memset(grid, 0, sizeof(grid));
    
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(s1[i-1] == s2[j-1]) { //if they match
                grid[i][j] = grid[i-1][j-1] + 1;
                result = max(result, grid[i][j]);
            }else{ 
                //if they don't match, 
                //pick the larger of top and left neighbours
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
    return result;
}

/**
 * if characters don't match we pick the larger of top and left neighbours,
 * and update the current cell.
 * when characters match we know that the common characters total count value 
 * is stored in the diagonal cell (previous current cell)
 * so we fetch it and add 1 to it
 * **/