#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll n, t;
const int MXN = 5e4 + 3;
ll a[MXN], b[MXN];

void solve()
{
    for(int j = 0; j < n; ++j) {
        if(b[j] > 0) {
            ll diff = a[j] - b[j];

            if(diff < 0) {
                cout << "NO\n";
                return;
            }

            for(int i = 0; i < n; ++i) {
                if(a[i] - b[i] != diff && !(b[i] == 0 && a[i] - b[i] <= diff) || a[i] < b[i]) {
                    cout << "NO\n";
                    return;
                }
            }
            
            break;
        }
    }
    cout << "YES\n";

}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for(int j = 0; j < n; ++j) {
            cin >> b[j];
        }
        solve();
    }
}
