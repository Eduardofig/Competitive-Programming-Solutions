#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e2 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;


vector<pair<int, int>> g[MXN];
int comp[MXN][MXN];
vector<pair<int, int>> querys;
int qu;

void bfs(int st, int col)
{
    queue<int> q;

    q.push(st);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(comp[col][u] == -1) {
            comp[col][u] = st;

            for(auto &[v, vcol]: g[u]) {
                if(comp[col][v] == -1 && vcol == col) {
                    q.push(v);
                }
            }
        }
    }

}

void solve()
{
    memset(comp, -1, sizeof comp);

    for(int col = 0; col < 100; col++) {
        for(int u = 0; u < n; ++u) {
            if(comp[col][u] == -1) {
                bfs(u, col);
            }
        }
    }

    for(auto &[u, v]: querys) {
        int ans = 0;
        for(int col = 0; col < 100; ++col) {
            if(comp[col][u] == comp[col][v]) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    cin >> qu;
    querys.resize(qu);

    for(auto &[u, v]: querys) {
        cin >> u >> v;

        u--;
        v--;
    }

    solve();
}
