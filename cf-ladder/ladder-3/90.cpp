#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, k;
int a[MXN];
//int b[MXN];
//string s;

void solve()
{
    vector<pair<int, int>> diff;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i] / 10;
        if(a[i] < 100) {
            diff.emplace_back(10 - (a[i] % 10), i);
        }
    }

    sort(diff.begin(), diff.end());

    for(int i = 0; i < diff.size() && k >= diff[i].first; i++) {
        if(diff[i].first > 0) {
            k -= diff[i].first;
            a[diff[i].second] += diff[i].first;
            ans++;
        }
    }

    for(int i = 0; i < n && k > 0; i++) {
        int dec = min(100 - a[i], k);

        k -= dec;
        ans += dec / 10;
    }

    cout << ans << '\n';
}

void read()
{
    cin >> n >> k;
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
