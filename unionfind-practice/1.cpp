#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m, q;
//int a[MXN];
//int b[MXN];
//string s;

map<string, int> mp;
int curr = 0;

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

vector<tuple<int, int, int>> rel;
vector<pair<int, int>> qu;

const int OFFSET = 1e5 + 1;

void solve()
{
    unionfind uf(2 * MXN);
    for(auto &[type, u, v] : rel) {
        if(type == 1) {
            if(uf.find(u + OFFSET) == uf.find(v) || uf.find(u) == uf.find(v + OFFSET)) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                uf.unite(u, v);
                uf.unite(u + OFFSET, v + OFFSET);
            }

        } else {
            if(uf.find(u) == uf.find(v) || uf.find(u + OFFSET) == uf.find(v + OFFSET)) {
                cout << "NO\n";
            } else {
                cout << "YES\n";

                uf.unite(u + OFFSET, v);
                uf.unite(u, v + OFFSET);
            }

        }
    }

    for(auto &[u, v] : qu) {
        if(uf.find(u) == uf.find(v) || uf.find(u + OFFSET) == uf.find(v + OFFSET)) {
            cout << 1;
        } else if(uf.find(u + OFFSET) == uf.find(v) || uf.find(v + OFFSET) == uf.find(u)) {
            cout << 2;
        } else {
            cout << 3;
        }
        cout << '\n';
    }
}

void read()
{
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        mp[s] = i;
    }

    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;

        string a, b;

        cin >> a >> b;

        int u = mp[a];
        int v = mp[b];

        rel.emplace_back(type, u, v);
    }

    for(int i = 0; i < q; i++) {
        string a, b;

        cin >> a >> b;

        int u = mp[a];
        int v = mp[b];

        qu.emplace_back(u, v);
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
