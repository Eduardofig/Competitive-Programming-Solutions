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
vector<tuple<char, int, int>> qu;
//int a[MXN];
//int b[MXN];
//string s;

template<typename T>
void mini(T &a, T b)
{
    a = min(a, b);
}

template<typename T>
void maxi(T &a, T b)
{
    a = max(a, b);
}

struct unionfind
{
    vector<int> par, sz, mn;

    unionfind(int n)
    {
        par.resize(n);
        sz.resize(n);
        mn.resize(n);

        for(int u = 0; u < n; u++) {
            par[u] = u;
            sz[u] = 1;
            mn[u] = p[u];
        }
    }

    pair<int, int> find(int u)
    {
        if(par[u] == u) {
            return {u, mn[u]};
        }

        const auto &[parent, pmn] = find(par[u]);

        par[u] = parent;
        mini(mn[u], pmn);

        return {par[u], mn[u]};
    }


    void unite(int u, int v)
    {
        par[v] = u;
    }
};

void solve()
{
    unionfind uf(MXN);

    for(auto &[op, u, v]: qu) {
        // cout << op << ' ';
        if(op == '+') {
            uf.unite(u, v);
        } else {
            cout << uf.find(u).second << '\n';
        }
    }
}

void read()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    qu.resize(m);

    for(auto &[op, u, v]: qu) {
        cin >> op >> u;
        u--;
        if(op == '+') {
            cin >> v;
            v--;
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
