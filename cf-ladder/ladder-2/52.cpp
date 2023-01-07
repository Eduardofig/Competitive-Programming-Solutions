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

ll n;
ll k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll high = 1, low = 1;
    
    for(int i = 0; i < n; ++i) {
        high = 2 * high + 1;
    }

    ll ans = n + 1;
    while(high > low) {
        ll mid = low + (high - low) / 2;

        if(mid == k) {
            cout << ans << '\n';
            return;
        }

        if(mid > k) {
            high = mid;
        } else {
            low = mid + 1;
        } 
        ans--;
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    solve();
}
