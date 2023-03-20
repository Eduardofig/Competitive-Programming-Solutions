#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

ll n, h, k;
ll a[MXN];
//int b[MXN];
//string s;

void solve()
{
    ll curr = a[0];
    ll ans = 0;

    for(int i = 1; i < n; i++) {
        if(curr >= k) {
            ans += curr / k;
            curr %= k;
        }

        if(curr > 0 && curr + a[i] > h) {
            ans++;

            curr = a[i];
        } else {
            curr += a[i];
        }
    }

    ans += curr / k + (curr % k > 0);

    cout << ans << '\n';
}

void read()
{
    cin >> n >> h >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
