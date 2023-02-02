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
//

set<int> g[MXN];
bool vis[MXN]{};
set<int> em[MXN];

bool analf = true;

void bfs(int st)
{
    queue<int> q;

    q.push(st);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = true;

        for(int v: g[u]) {
            if(!vis[v]) {
                q.push(v);
            }
        }
    }
}
 
void solve()
{
    int ans = 0;
    for(int u = 0; u < n; ++u) {
        if(!vis[u]) {
            bfs(u);
            ans++;
        }
    }

    cout << max(ans - 1 + analf, 0) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        for(int j = 0; j < k; ++j) {
            analf = false;

            int x;
            cin >> x;

            x--;

            em[i].insert(x);
        }
    }

    for(int u = 0; u < n; ++u) {
        for(int l: em[u]) {
            for(int v = u + 1; v < n; ++v) {
                if(em[v].find(l) != em[v].end()) {
                    g[u].insert(v);
                    g[v].insert(u);
                }
            }
        }
    }

    solve();

}
