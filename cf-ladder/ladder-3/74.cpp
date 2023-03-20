#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 3e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n;
int x[MXN];
//int b[MXN];
//string s;

void solve()
{
    sort(x, x + n);

    /*
    ll pref[n + 1];

    pref[0] = 0;

    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + x[i];
    }

    ll best, best_sum = INF;
    for(int i = 0; i < n; i++) {
        ull sum = (i - (n - i - 1)) * x[i] - pref[i] + (pref[n] - pref[i + 1]);
        //cout << i << ' ' << sum << '\n';

        if(sum < best_sum) {
            best_sum = sum;
            best = x[i];
        }
    }
    */
    cout << x[(n - 1) / 2] << '\n';
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
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
