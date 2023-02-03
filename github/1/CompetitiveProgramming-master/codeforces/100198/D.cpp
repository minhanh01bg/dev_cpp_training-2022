#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

struct Edge {
    int u, v, c, f;
    int next;
};

struct MaxFlow {
    int n, s, t;
    vector< Edge > edges;
    vector<int> head, current, h, avail;
    vector<long long> excess;

    MaxFlow(int n) : n(n), head(n, -1), current(n, -1), h(n), avail(n), excess(n) {
        edges.clear();
    }

    int addEdge(int u, int v, int c, bool bi = false) {
        Edge xuoi = {u, v, c, 0, head[u]};
        head[u] = edges.size(); edges.push_back(xuoi);
        Edge nguoc = {v, u, bi ? c : 0, 0, head[v]};
        head[v] = edges.size(); edges.push_back(nguoc);
        return v == u ? head[u] - 1 : head[u];
    }

    long long getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        init();

        int now = 0;
        queue<int> qu[2];
        REP(x,n)
            if (x != s && x != t && excess[x] > 0)
                qu[now].push(x);
        
        globalLabeling();

        int cnt = 0;
        while (!qu[now].empty()) {
            while (!qu[1-now].empty()) qu[1-now].pop();

            while (!qu[now].empty()) {
                int x = qu[now].front(); qu[now].pop();
                while (current[x] >= 0) {
                    int p = current[x];
                    if (edges[p].c > edges[p].f && h[edges[p].u] > h[edges[p].v]) {
                        bool need = (edges[p].v != s && edges[p].v != t && !excess[edges[p].v]);
                        push(current[x]);
                        if (need) qu[1-now].push(edges[p].v);
                        if (!excess[x]) break;
                    }
                    current[x] = edges[current[x]].next;
                }
                
                if (excess[x] > 0) {
                    lift(x);
                    current[x] = head[x];
                    qu[1-now].push(x);
                    cnt++;
                    if (cnt == n) {
                        globalLabeling();
                        cnt=0;
                    }
                }
            }
            now = 1 - now;
        }
        return excess[t];
    }

private:
    void init() {
        REP(i,n) current[i] = head[i];

        int p = head[s];
        while (p >= 0) {
            edges[p].f = edges[p].c;
            edges[p^1].f -= edges[p].c;
            excess[edges[p].v] += edges[p].c;
            excess[s] -= edges[p].c;
            p = edges[p].next;
        }
        for(int v = 0; v < n; ++v) h[v] = 1;
        h[s] = n; h[t] = 0;
    }

    void push(int i) {
        long long delta = min(excess[edges[i].u], (long long) edges[i].c - edges[i].f);
        edges[i].f += delta; edges[i^1].f -= delta;
        excess[edges[i].u] -= delta;
        excess[edges[i].v] += delta;
    }

    void lift(int u) {
        int minH = 2 * n;
        int p = head[u];
        while (p>=0) {
            if (edges[p].c > edges[p].f)
                minH = min(minH, h[edges[p].v]);
            p = edges[p].next;
        }
        h[u] = minH + 1;
    }

    void globalLabeling() {
        REP(i,n) avail[i] = 1, h[i] = 0;
        h[s] = n; h[t] = 0;
        queue<int> q; q.push(t); avail[t] = false;

        while (!q.empty()) {
            int x = q.front(); q.pop();
            int p = head[x];
            while (p >= 0) {
                int pp = p^1;
                if (avail[edges[pp].u] && edges[pp].f < edges[pp].c) {
                    h[edges[pp].u] = h[x] + 1;
                    avail[edges[pp].u] = 0;
                    q.push(edges[pp].u);
                }
                p = edges[p].next;
            }
            if (q.empty() && avail[s]) {
                avail[s] = false;
                q.push(s);
            }
        }
        REP(x,n) current[x] = head[x];
    }
};

int n, m, L;
int res[300111];
int id[1511][1511];

int main() {
    ios :: sync_with_stdio(false);
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    while (cin >> n >> m >> L) {
        int start = -1, target = -1;
        REP(i,n) {
            int a; cin >> a;
            if (a == 1) start = i;
            else if (a == L) target = i;
        }
        MaxFlow flow(n);
        FOR(i,1,m) {
            int u, v, c; cin >> u >> v >> c;
            --u; --v;
            id[u][v] = i;
            res[i] = 0;
            flow.addEdge(u, v, c);
        }
        int t = flow.getMaxFlow(start, target);
//        DEBUG(t);

        for(auto e : flow.edges) {
            int u = e.u, v = e.v;
            if (!id[u][v]) {
                if (e.f > 0)
                    res[id[v][u]] -= e.f;
            }
            else {
                if (e.f > 0)
                    res[id[u][v]] += e.f;
            }
        }
        FOR(i,1,m) printf("%d\n", res[i]);
    }
}
