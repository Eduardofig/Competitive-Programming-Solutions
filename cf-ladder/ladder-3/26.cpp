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

int n, s;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(a, a + n);

    int mid = n / 2;

    if(s == a[mid]) {
        cout << 0 << '\n';
        return;
    }

    if(s < a[mid]) {
        ll ans = 0;
        for(int i = 0; i <= mid; ++i) {
            if(s < a[i]) {
                ans += a[i] - s;
            }
        }
        cout << ans << '\n';
        return;
    } 

    ll ans = 0;
    for(int i = mid; i < n; ++i) {
        if(s > a[i]) {
            ans += s - a[i];
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
