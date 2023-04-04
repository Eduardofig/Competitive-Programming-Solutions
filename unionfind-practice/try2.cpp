#include <bits/stdc++.h>

using namespace std;

using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

int n, k;
//int a[MXN];
//int b[MXN];
//string s;

vector<tuple<int, int, int>> op;

const int OFFSET = 1e5 + 2;

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



void solve()
{
    unionfind uf(MXN);

    int ans = 0;

    for(auto &[d, x, y]: op) {
        if(x > n || y > n) {
            ans++;
            continue;
        }

        int addrx = -1, addry = -1;

        for(int i = 0; i < 3; i++) {
            if(uf.find(i) == uf.find(x)) {
                addrx = i;
            }

            if(uf.find(i) == uf.find(y)) {
                addry = i;
            }
        }

        if(d == 1) {
            if(addry != -1 && addrx != -1 && addrx != addry) {
                ans++;
            } else {
                uf.unite(x, y);
            }
        } else {
            if(addrx == addry) {
                if(addrx != -1) {
                    ans++;
                    continue;
                } else {
                    uf.unite(x, 0);
                    uf.unite(y, 1);
                }
            } else {
                if(uf.find(x) == uf.find(y)) {
                    ans++;
                    continue;
                }

                if(addrx != -1 && addry != -1) {
                    if((addrx + 1) % 2 != addry) {
                        ans++;
                        continue;
                    }
                } else {
                    if(addrx == -1) {
                        uf.unite(x, (addry - 1 + 2) % 2);
                    } else {
                        uf.unite(y, (addrx + 1) % 2);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

void read()
{
    cin >> n >> k;
    op.resize(k);

    for(auto &[d, x, y]: op) {
        cin >> d >> x >> y;
        x += 3;
        y += 3;
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
