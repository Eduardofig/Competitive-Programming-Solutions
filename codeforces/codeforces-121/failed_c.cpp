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
vector<string> v;
int val[MXN];
vector<vector<int>> starts(26, vector<int>());
vector<string> names;
vector<int> g[MXN];
int ans = 0;

int len[MXN] = { -1 };

void dfs(int curr, int start)
{
    for(int neigh: g[curr]) {
        len[neigh] = max(len[neigh], len[curr] + (int)names[neigh].size());
        if(len[neigh] == -1) {
            dfs(neigh, start);
        }
    }
}

void solve()
{
    for(int i = 0; i < n; ++i) {
        len[i] = names[i].size();
        dfs(i, i);
        for(int neigh: g[i]) {
            ans = max(ans, len[neigh]);
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        names.push_back(s);
        starts[s.front() - 'a'].push_back(i);
    }

    for(int from = 0; from < n; ++from) {
        for(int to: starts[names[from].back() - 'a']) {
            if(from !=  to) {
                g[from].push_back(to);
            }
        }
    }

    solve();
}
