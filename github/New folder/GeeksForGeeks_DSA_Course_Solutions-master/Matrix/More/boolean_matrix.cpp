/**
 * Space optimized version.
 * First one do not use flags.
 * Second one use flags, and first row
 * and column as auxilliary arrays.
 */
#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
#define R 1

int main(){
    int t, r, c, num[MAX][MAX];
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> num[i][j];

                if(num[i][j] == R){
                    num[i][0] = R;
                    num[0][j] = R;
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(num[i][0] == R || num[0][j] == R){
                    cout << "1" << " ";
                }else{
                    cout << "0" << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}


/**
#include<bits/stdc++.h>
using namespace std;
#define R 1
#define MAX 1001

void modifyMatrix(int num[][MAX], int r, int c);
void printMatrix(int num[][MAX], int r, int c);

int main(){
    int t, r, c, num[MAX][MAX];
    cin >> t;
    while(t--){
        cin >> r >> c;
        // input
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> num[i][j];
            }
        }
        modifyMatrix(num, r, c);
        printMatrix(num, r, c);
    }
    return 0;
}

void modifyMatrix(int num[][MAX], int r, int c){
    bool row_flag = false; 
    bool col_flag = false; 
  
    // updating the first row and col if 1 
    // is encountered 
    for (int i=0; i<r; i++){ 
        for (int j=0; j<c; j++){ 
            // if first row has any 1/0, then flag becomes true
            if (i == 0 && num[i][j] == R) 
                row_flag = true; 
  
            // if first column has any 1/0, then flag becomes true
            if (j == 0 && num[i][j] == R) 
                col_flag = true; 

            // using first row and first column as auxilliary arrays
            if (num[i][j] == R){
                num[0][j] = R; 
                num[i][0] = R; 
            } 
        } 
    } 
  
    // Modify the input matrix num[] using the 
    // auxilliary arrays
    for(int i=1; i<r; i++){ 
        for(int j=1; j<c; j++){  
            if (num[0][j] == R || num[i][0] == R){ 
                num[i][j] = R;
            } 
        }
    }

    // modify first row if there was any 1/0
    if (row_flag == true) { 
        for (int i=0; i<c; i++) { 
            num[0][i] = R; 
        } 
    } 
  
    // modify first col if there was any 1/0
    if (col_flag == true){ 
        for (int i=0; i<r; i++) { 
            num[i][0] = R; 
        } 
    } 
}

void printMatrix(int num[][MAX], int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
}
*/