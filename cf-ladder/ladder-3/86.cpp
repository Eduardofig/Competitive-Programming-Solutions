#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n;
int l[MXN];
pair<int, int> mn[MXN], mx[MXN];
bool asc[MXN]{};
//int a[MXN];
//int b[MXN];
vector<int> s[MXN];

void solve()
{
    ll ans = 0;

    for(int i = 0; i < n; ++i) {
        mn[i] = {*min_element(s[i].begin(), s[i].end()), i};
        mx[i] = {*max_element(s[i].begin(), s[i].end()), i};
    }

    for(int i = 0; i < n; i++) {
        int prefmn = INF;
        for(int num: s[i]) {
            if(prefmn < num) {
                asc[i] = true;
            }

            prefmn = min(prefmn, num);
        }
        
        if(asc[i]) {
            mn[i].first = -INF;
            mx[i].first = INF;
        } 
    }

    sort(mx, mx + n);

    for(int i = 0; i < n; i++) {
        int pos = mx[i].second;

        mn[pos].second = i;
    }

    sort(mn, mn + n);

    for(int i = 0; i < n; ++i) {
        int idx = upper_bound(mx, mx + n, pair<int, int>{mn[i].first, INF}) - mx;
        int pairs = n - idx;

        ans += max(pairs, 0);
    }
    cout << ans << '\n';
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i];
        s[i].resize(l[i]);

        for(int &it: s[i]) {
            cin >> it;
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
