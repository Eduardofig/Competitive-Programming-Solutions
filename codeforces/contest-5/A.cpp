#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll n, t;

void solve()
{
    ll base = n / 3, h1, h2, h3;

    if(n % 3 == 1) {
        h1 = base + 2;
        h2 = base;
        h3 = base - 1;
    } else if(n % 3 == 2) {
        h1 = base + 2;
        h2 = base + 1;
        h3 = base - 1;
    } else {
        h1 = base + 1;
        h2 = base;
        h3 = base - 1;
    }

    cout << h2 << " " << h1 << " " << h3 << '\n';

}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        solve();
    }
}
