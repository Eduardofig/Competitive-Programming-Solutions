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
int k;
int a[MXN];
int t[MXN];
//string s;
 
void solve()
{
    int pref[n + 1];
    pref[0] = 0;

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += a[i] * t[i];
        pref[i + 1] = pref[i] + a[i] * (t[i] ^ 1);
    }

    int best = 0;

    for(int i = 0; i < n + 1; ++i) {
        best = max(best, pref[i] - pref[max(i - k, 0)]);
    }

    ans += best;
    cout << ans << '\n';

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    solve();
}
