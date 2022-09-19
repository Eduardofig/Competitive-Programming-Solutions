#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
vector<pair<pair<int, int>, int>> players;
vector<int> g[MXN];
vector<int> ans;
int vis[MXN];

void bfs(int st)
{
    memset(vis, false, sizeof vis);
    queue<int> q;
    q.push(st);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        vis[curr] = true;
        ans[curr] = 1;

        for(int neigh: g[curr]) {
            if(!vis[neigh]) {
                q.push(neigh);
            }
        }
    }
}
 
void solve()
{
    sort(players.begin(), players.end(), [](auto a, auto b) {
        return a.first.first > b.first.first;
    });

    int k = players.front().second;

    for(int i = 0; i < n - 1; ++i) {
        int to = players[i].second;
        int from = players[i + 1].second;

        g[from].push_back(to);
    }

    sort(players.begin(), players.end(), [](auto a, auto b) {
        return a.first.second > b.first.second;
    });

    for(int i = 0; i < n - 1; ++i) {
        int to = players[i].second;
        int from = players[i + 1].second;

        g[from].push_back(to);
    }

    bfs(k);

    for(int i: ans) {
        cout << i;
    }
    cout << '\n';
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
        players.resize(n);
        ans.resize(n, 0);

        for(int i = 0; i < n; ++i) {
            cin >> players[i].first.first;
        }
        for(int i = 0; i < n; ++i) {
            cin >> players[i].first.second;
            players[i].second = i;
        }
        solve();
    }
}
