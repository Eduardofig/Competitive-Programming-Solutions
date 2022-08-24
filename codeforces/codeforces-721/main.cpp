#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
vector<int> g[MXN];
bool vis[MXN];

void dfs(int curr, int mex)
{
    for(int neigh: g[curr]) {
        dfs(neigh, mex);
    }
}

void solve()
{
    memset(vis, false, sizeof vis);

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;

        //reset
        for(int i = 0; i < MXN; ++i) {
            g[i].clear();
        }

        for(int i = 0; i < n; ++i) {
            int from, to;
            cin >> from >> to;
            from--; to--;
            g[from].push_back(to);
        }

        solve();
    }
}
