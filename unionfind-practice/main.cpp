#include <bits/stdc++.h>

#define For(i, n) for(int i = 0; i < (int)(n); ++i)
#define Forl(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define Fore(v, ...) for(auto &[__VA_ARGS__]: v)
#define All(x) (x).begin(), (x).end()
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
vector<int> p;
vector<tuple<char, int, int>> qu;
//int a[MXN];
//int b[MXN];
//string s;

int nxt()
{
    int x;
    cin >> x;
    return x;
}

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

    unionfind(int n): par(n), sz(n, 1), mn(n)
    {
        iota(All(par), 0);

        For(u, n) {
            if(u < p.size()) {
                mn[u] = p[u];
            }
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

    Fore(qu, op, u, v) {
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
    p.resize(nxt());
    qu.resize(nxt());

    generate(All(p), nxt);

    Fore(qu, op, u, v) {
        cin >> op;
        u = nxt() - 1;
        if(op == '+') {
            v = nxt() - 1;
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
