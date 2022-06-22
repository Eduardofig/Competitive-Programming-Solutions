#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, x, y, ans, enemy, aux;
    cin >> n >> k >> x >> y;

    for(int i = 0; i < n; ++i) {
        cin >> aux;
        enemy = max(enemy, aux);
    }

    if(enemy > k * x) {
        ans = ((enemy - (k * x)) / y) + k;
        ans += ((enemy - (k * x)) % y) != 0;
    } else {
        ans = enemy / x;
        ans += (enemy % x) != 0;
    }

    cout << ceil(ans) << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
