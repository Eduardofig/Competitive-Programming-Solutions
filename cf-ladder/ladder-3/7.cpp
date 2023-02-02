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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    bool vis[n];
    memset(vis, false, sizeof vis);

    sort(a, a + n);
    reverse(a, a + n);

    bool found = true;
    int curr = -1;

    int ans = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    ans = 0;
    for(int i = 0; i < n; ++i) {
        if(!pq.empty() && pq.top() > a[i]) {
            ans++;
            pq.pop();
        }
        pq.push(a[i]);
    }

    cout << ans << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
