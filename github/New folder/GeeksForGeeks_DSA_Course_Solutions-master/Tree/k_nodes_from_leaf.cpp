#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 10000

struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int printKDistantfromLeaf(Node* node, int k);
void insert(struct Node *root,int n1,int n2,char lr){
    if(root==NULL)
    return;
    if(root->key==n1) {
        switch(lr) {
        case 'L': root->left=new Node(n2);
                break;
        case 'R': root->right=new Node(n2);
                break;
        }
    }
    else {
        insert(root->left,n1,n2,lr);
        insert(root->right,n1,n2,lr);
    }
 }

int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--) {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--) {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL) {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else {
            insert(root,n1,n2,lr);
        }
    }
    cin>>k;
    cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}// } Driver Code Ends
//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/

int countt = 0;

// This function finds K distant nodes
void findKDistantNodes(Node* root, int path[], bool visited[], int pathlen, int k){
    
    if(root == NULL)
        return;
    
    path[pathlen] = root->key;
    visited[pathlen] = false;
    pathlen++;
    
    //if it is a leaf then print the k distant node from the leaf if it hasn't been printed already
    if(root->left == NULL && root->right == NULL && (pathlen-k-1) >= 0 && visited[pathlen-k-1] == false){
        //cout << path[pathlen-k-1] << " ";
        countt++;
        visited[pathlen-k-1] = true;
        return;
    }
    
    findKDistantNodes(root->left, path, visited, pathlen, k);
    findKDistantNodes(root->right, path, visited, pathlen, k);
}

//This function returns the count of the total distinct nodes that are at a 
//distance k from leaf nodes.

int printKDistantfromLeaf(Node* root, int k)
{
    // we declare two arrays - path[] to store node values
    // and visited[] to keep track of visited nodes
    countt = 0; //reset
    int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    findKDistantNodes(root, path, visited, 0, k);
    return countt;
}