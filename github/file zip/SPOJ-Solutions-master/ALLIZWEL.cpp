/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int r, c;
char matrix[105][105];
bool visited[105][105];
string input = "ALLIZZWELL"; 

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c);
}
int ans = 0;
void solve(int x, int y, int len){
    
    if(len == 10){
        ans = 1;
        return;
    }
    // cout << x << ' ' << y << sp << input[len] << endl;
    char toSearch = input[len];
    for(int i = 0;i < 8; i++){
            int tempX = x+dx[i];
            int tempY = y+dy[i];
            if(isValid(tempX,tempY) && !visited[tempX][tempY] && matrix[tempX][tempY] == toSearch){
                visited[tempX][tempY] = 1;
                solve(tempX, tempY, len+1);
                visited[tempX][tempY] = 0;
            }
    }
}


int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        FOR(i,r){
            FOR(j,c){
                cin >> matrix[i][j];
            }
        }
        int flag = 1;
        ans = 0;
        FOR(i,r){
            FOR(j,c){
                if(matrix[i][j] == 'A'){
                    FILL(visited, 0);
                    visited[i][j] = 1;
                    solve(i,j,1);
                    if(ans){
                        cout << "YES" << endl;
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 0)
                break;
        }
        if(flag)
            cout << "NO" << endl;
    }
    return 0;
}
