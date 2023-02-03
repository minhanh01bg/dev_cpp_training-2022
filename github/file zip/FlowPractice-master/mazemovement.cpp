#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <iterator>

using namespace std;


/**
 * This piece of code is taken from https://cp-algorithms.com/graph/dinic.html
 * 0-indexing
 */
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
};

struct Dinic 
{
    static const long long flow_inf = 1e18;
public:
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

	Dinic()
	{
		
	}
    
    Dinic(int n, int s, int t){
		this->n = n;
		this->s = s;
		this->t = t;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge{v, u, cap,0});
        edges.push_back(FlowEdge{u, v, 0, 0});
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
    
    void printResult()
    {
		for (auto it=edges.begin(); it!=edges.end(); it++)
		//if ((*it).flow>0)
		{
			cout << (*it).v+1 << ' ' << (*it).u+1 << ' ' << (*it).cap << ' ' << (*it).flow << '\n';
		}
	}
} G;
const int maxn = 1000;
int n;
int a[maxn+1];

int gcd(int x,int y)
{
	if (x%y==0) return y;
	else return gcd(y,x%y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	int mini = 1;
	int maxi = 1;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		if (a[i]<a[mini]) mini = i;
		if (a[i]>a[maxi]) maxi = i;
	}
	G = Dinic(n,mini-1,maxi-1);
	
	for (int i=1; i<=n; i++)
	for (int j=i+1; j<=n; j++)
	{
		int f=gcd(a[i],a[j]);
		if (f>1)
		{
			G.add_edge(i-1,j-1,f);
			G.add_edge(j-1,i-1,f);
		}
	}
	
	cout << G.flow() << '\n';
	return 0;
}
