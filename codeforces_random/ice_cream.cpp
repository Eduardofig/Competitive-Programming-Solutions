#include <bits/stdc++.h>

using namespace std;

int x, y, n, t;

void solve()
{
    cout << min(n % (x + y), x)*3 + (n/(x + y))*x*3 << endl;
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> x >> y >> n;
        solve();
    }
}
