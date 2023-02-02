#include <bits/stdc++.h>

using namespace std;

int a[(int)1e7];
int n, s;

void solve()
{
    long long tot = 0;


    int i = 0;
    int mx = 0;
    while(tot + a[i] <= s && i < n) {
        mx = max(mx, a[i]);
        tot += a[i++];
    }

    if(i < n) {
        mx = max(mx, a[i]);
    }

    int prev = i;

    tot = -mx;

    i = 0;
    while(tot + a[i] <= s && i < n) {
        tot += a[i++];
    }

    if(i > prev) {
        cout << find(a, a + n, mx) - a + 1 << '\n';
        return;
    }
    
    cout << "0\n";

}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> s;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}
