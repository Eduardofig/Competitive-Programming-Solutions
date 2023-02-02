#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m, k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
bool has[MXN]{};
vector<pair<int, int>> g[MXN];
 
void solve()
{
    bool found = false;
    int ans = INF;

    for(int u = 0; u < n; ++u) {
        if(has[u]) {
            for(auto &[v, w]: g[u]) {
                if(!has[v]) {
                    found = true;
                    ans = min(ans, w);
                }
            }
        }
    }

    cout << (found? ans: -1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int u, v, w;

        cin >> u >> v >> w;

        u--, v--;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for(int i = 0; i < k; i++) {
        int u;
        cin >> u;
        u--;
        has[u] = true;
    }

    solve();
}
