#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e9 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

ll n, g, b;
//int a[MXN];
//int b[MXN];
//string s;

bool check(ll m)
{
    ll tot = (m / (g + b)) * g + min(m % (g + b), g);

    return tot >= ((n / 2) + (n % 2));
}

void solve()
{
    ll low = n, high = LONG_LONG_MAX;

    while(high > low) {
        ll mid = low + (high - low) / 2;

        if(check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << high << '\n';
}

void read()
{
    cin >> n >> g >> b;
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
