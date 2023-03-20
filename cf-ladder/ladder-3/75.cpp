#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 5e2 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n;
//int a[MXN];
//int b[MXN];
//string s;

ll grid[MXN][MXN];

void solve()
{
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }

    ll sumi[n];
    memset(sumi, 0, sizeof sumi);

    ll ti, tj;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                ti = i;
                tj = j;
            }

            sumi[i] += grid[i][j];
        }
    }

    ll ans;
    if(ti == 0) {
        ans = sumi[1] - sumi[ti];
    } else {
        ans = sumi[0] - sumi[ti];
    }

    if(ans <= 0) {
        cout << "-1\n";
        return;
    }

    grid[ti][tj] = ans;


    ll d1{}, d2{};
    ll sumj[n];

    memset(sumi, 0, sizeof sumi);
    memset(sumj, 0, sizeof sumj);

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            sumi[i] += grid[i][j];
            sumj[j] += grid[i][j];

            if(i == j) {
                d1 += grid[i][j];
            }

            if(i + j == n - 1) {
                d2 += grid[i][j];
            }
        }
    }

    set<ll> s;

    s.insert(d1);
    s.insert(d2);

    for(ll i = 0; i < n; i++) {
        s.insert(sumi[i]);
        s.insert(sumj[i]);
    }

    if(s.size() == 1) {
        cout << ans << '\n';
        return;
    }

    cout << "-1\n";
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
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
