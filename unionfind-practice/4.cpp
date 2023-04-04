#include <bits/stdc++.h>

using namespace std;

using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;

const int MXN = 5e6 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

int n, k;
//int a[MXN];
//int b[MXN];
//string s;

vector<tuple<int, int, int>> op;

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

        if(u == v) {
            return;
        }

        if(sz[u] > sz[v]) {
            swap(u, v);
        }

        par[u] = v;
        sz[v] += sz[u];
    }

};

const int OFFSET = 1e6;

int next(int x) {
    return x + OFFSET + 10;
}

int prev(int x) {
    return x + 2 * OFFSET + 20;
}

void solve()
{
    unionfind uf(MXN);

    const auto same = [&uf](int x, int y) {
        return uf.find(x) == uf.find(y);
    };

    // int piece = 1;
    int ans = 0;
    // set<int> pieces;

    for(auto &[d, x, y]: op) {

        if(x > n || y > n) {
            ans++;
            // pieces.insert(piece++);
            continue;
        }

        if(d == 1) {
            if(same(prev(x), y) || same(prev(y), x) || same(prev(x), next(y)) || same(prev(y), next(x)) ||
                    same(x, next(y)) || same(y, next(x))) {
                ans++;
                // pieces.insert(piece++);
                continue;
            } 


            uf.unite(x, y);
            uf.unite(next(x), next(y));
            uf.unite(prev(x), prev(y));
        } else {
            if(same(x, y) || same(prev(x), prev(y)) || same(next(x), next(y)) || same(next(y), x) || 
                    same(prev(x), y) || same(next(x), prev(y))) {
                ans++;
                // pieces.insert(piece++);
                continue;
            } 

            uf.unite(prev(y), x);
            uf.unite(y, next(x));
            uf.unite(prev(x), next(y));
        }
        // piece++;
    }

    // cout << "The false pieces are ";
    // int last = *max_element(pieces.begin(), pieces.end());
    // for(int p: pieces) {
    //     cout << (p == last? "and the ": "the ") << p << "th" << (p == last? " ones.\n": ", ");
    // }



    cout << ans << '\n';
}

void read()
{
    cin >> n >> k;
    op.resize(k);

    for(auto &[d, x, y]: op) {
        cin >> d >> x >> y;
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
