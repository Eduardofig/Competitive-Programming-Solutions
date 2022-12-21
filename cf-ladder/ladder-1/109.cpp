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

int n, t;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
vector<int> g[MXN];
vector<bool> vis(MXN, false);

void dfs(int curr)
{
    vis[curr] = true;
    for(int neigh: g[curr]) {
        if(!vis[neigh]) {
            dfs(neigh);
        }
    }
}
 
void solve()
{
    dfs(0);

    if(vis[t - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> t;
    for(int i = 0; i < n; ++i) {
        int from = i;

        int to;
        cin >> to;
        to += i;

        g[from].push_back(to);
    }
    solve();
}
