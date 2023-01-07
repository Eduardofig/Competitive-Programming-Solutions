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
    int ans = -1;
    int best = INF;
    for(int t = 1; t < 115; ++t) {
        int cost = 0;
        for(int i = 0; i < n; ++i) {
            cost += min({abs(t + 1 - a[i]), abs(t - 1 - a[i]), abs(t - a[i])});
        }

        if(cost < best) {
            best = cost;
            ans = t;
        }
    }

    cout << ans << ' ' << best << '\n';
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
