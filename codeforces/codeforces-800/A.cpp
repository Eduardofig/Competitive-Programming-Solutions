#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll a, b;

void solve()
{
    ll diff = max(a, b) - min(a, b);

    for(int i = 0; i < min(a, b); ++i) {
        if(a > b) {
            cout << '0' << '1';
        } else {
            cout << '1' << '0';
        }
    }

    if(a < b) {
        for(int i = 0; i < diff; ++i) {
            cout << '1';
        }
    } else {
        for(int i = 0; i < diff; ++i) {
            cout << '0';
        }
    }

    cout << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        solve();
    }
}
