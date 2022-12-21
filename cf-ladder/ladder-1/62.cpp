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

int n;
//int k;
int par[MXN];
//int b[MXN];
//string s;
vector<int> g[MXN];
int max_depth = 0;
bool vis[MXN];

void dfs(int curr, int depth)
{
    max_depth = max(max_depth, depth);
    if(!vis[curr]) {
        vis[curr] = true;

        for(int neigh: g[curr]) {
            dfs(neigh, depth + 1);
        }
    }
}
 
void solve()
{
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; ++i) {
        if(par[i] == -1) {
            dfs(i, 1);
        }
    }
    cout << max_depth << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int to = i;
        cin >> par[i];
        if(par[i] != -1) {
            par[i]--;
            int from = par[i];

            g[from].push_back(to);
        }
    }
    solve();
}
