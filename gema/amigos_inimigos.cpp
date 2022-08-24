#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[MXN];
int color[MXN];

int bfs(int s)
{
    color[s] = 0;
    queue<int> q;
    q.push(s);

    array<int, 2> ans{};

    while(!q.empty()) {
        int curr = q.front();
        ans[color[curr]]++;
        q.pop();

        for(int neigh: g[curr]) {
            if(color[neigh] == -1) {
                color[neigh] = color[curr] ^ 1;
                q.push(neigh);
            } else if(color[neigh] == color[curr]) {
                return -1;
            }
        }
    }


    return max(ans[0], ans[1]);
}
 
void solve()
{
    memset(color, -1, sizeof color);

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(color[i] == -1) {
            int res = bfs(i);
            if(res == -1) {
                cout << -1 << '\n';
                return;
            } else {
                ans += res;
            }
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve();
}
