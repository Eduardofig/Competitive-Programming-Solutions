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
bool vis[(1 << 17)]{};

void print_num(int curr)
{
    for(int i = n - 1; i >= 0; --i) {
        cout << (bool) (curr & (1 << i));
    }
    cout << '\n';
}

void dfs(int curr)
{
    vis[curr] = true;
    print_num(curr);
    for(int i = 0; i < n; ++i) {
        int next = (curr ^ (1 << i));
        if(!vis[next]) {
            dfs(next);
        }
    }
}
 
void solve()
{
    memset(vis, false, sizeof vis);

    dfs(0);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}
