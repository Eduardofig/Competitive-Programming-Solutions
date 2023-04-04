#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m, s;
//int a[MXN];
//int b[MXN];
//string s;

struct unionfind_partial
{
    vector<int> par, sz, time;
    
    unionfind_partial(int n)
    {
        par.resize(n);
        sz.resize(n);
        time.resize(n);
    
        for(int u = 0; u < n; u++) {
            par[u] = u;
            sz[u] = 1;
            time[u] = 0;
        }
    }
    
    int find(int u, int t)
    {
        if(par[u] == u || time[u] < t) {
            return u;
        }

        return find(par[u], t);
    }
    
    void unite(int u, int v, int t)
    {
        u = find(u, t);
        v = find(v, t);
    
        if(u != v) {
            if(sz[u] > sz[v]) {
                swap(u, v);
            }

            par[u] = v;
            time[u] = t;
            sz[v] += sz[u];
        }

    }
};

vector<tuple<int, int, int>> br;
vector<pair<int, int>> qu;

void solve()
{

    sort(br.begin(), br.end(), [](const auto &a, const auto &b) {
            return get<2>(a) > get<2>(b);
            });


    unionfind_partial ufp(MXN);

    for(auto &[u, v, w]: br) {
        // cout << w << '\n';
        ufp.unite(u, v, w);
    }

    for(auto &[u, v]: qu) {
        int high = MXN;
        int low = 0;

        while(high > low) {
            int mid = low + (high - low) / 2;

            // cout << mid << '\n';

            if(ufp.find(u, mid) != ufp.find(v, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << high - 1 << '\n';
    }
}

void read()
{
    cin >> n >> m >> s;
    br.resize(m);

    for(auto &[u, v, w]: br) {
        cin >> u >> v >> w;
    }

    qu.resize(s);

    for(auto &[u, v]: qu) {
        cin >> u >> v;
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
