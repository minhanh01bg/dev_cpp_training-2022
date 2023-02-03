vector<int> SortBinaryArray(vector<int> ba)
{
    int j;
    
    j = ba[0] == 0 ? 1 : 0;
    
    for(int i=1;i<ba.size();i++) {
        if(ba[i] == 0) {
            swap(ba[j], ba[i]);
            j++;
        }
    }
    
    return ba;
}