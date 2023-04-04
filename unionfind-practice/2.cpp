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
//int a[MXN];
//int b[MXN];
//string s;

vector<int> em[MXN];

struct unionfind
{
    vector<int> par, sz;
    
    unionfind(int n)
    {
        par.resize(n);
        sz.resize(n);
    
        for(int u = 0; u < n; u++) {
            par[u] = u;
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
    
        if(sz[u] > sz[v]) {
            swap(u, v);
        }
    
        par[u] = v;
        sz[v] += sz[u];
    }
};

set<int> lang;

void solve()
{
    if(lang.empty()) {
        cout << n << '\n';
        return;
    }

    unionfind uf(MXN);

    for(int i = 0; i < n; i++) {
        for(int j : em[i]) {
            uf.unite(i, j + n);
        }
    }

    set<int> cmp;

    for(int i = 0; i < n; i++) {
        cmp.insert(uf.find(i));
    }

    cout << cmp.size() - 1 << '\n';
}

void read()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        em[i].resize(k);

        for(int &j: em[i]) {
            cin >> j;
            lang.insert(j);
        }
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
