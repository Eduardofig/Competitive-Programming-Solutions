#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
int p[MXN];
int high[MXN]{};
//int a[MXN];
//int b[MXN];
//string s;

int curr = 1;

struct unionfind
{
    vector<int> par, sz, mn, leader;
    
    unionfind(int n)
    {
        par.resize(n);
        sz.resize(n);
        mn.resize(n);
        leader.resize(n);
    
        for(int u = 0; u < n; u++) {
            par[u] = u;
            mn[u] = p[u];
            leader[u] = u;
            sz[u] = 1;
        }
    }
    
    int find(int u)
    {
        if(par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }
    
    void unite(int u, int v)
    {
        u = find(u);
        v = find(v);
    
        if(u == v) {
            return;
        }
    
        if(p[u] < p[v]) {
            swap(u, v);
        }

        par[u] = v;
        sz[v] += sz[u];

        if(high[u] > high[v]) {
            leader[v] = u;
        }

        if(leader[v] != u) {
            mn[v] = ::min(mn[v], mn[u]);
        }
    }

    int min(int u) 
    {
        return mn[find(u)];
    }
};

void solve()
{
    unionfind uf(MXN);
    for(int query = 0; query < m; query++) {
        char op;
        cin >> op;

        if(op == '+') {
            int i, j;
            cin >> i >> j;
            i--; j--;

            high[i] = high[j] + 1;

            uf.unite(i, j);
        } else {
            int i;
            cin >> i;
            i--;

            cout << uf.min(i) << '\n';
        }
    }
}

void read()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        cin >> p[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
