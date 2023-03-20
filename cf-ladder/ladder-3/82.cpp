#include <algorithm>
#include <bits/stdc++.h>
#include <future>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 100;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

int n, m;
int a[MXN];
int b[MXN];
string s[MXN];
int offset;

void solve()
{
    int evlen{}, cnt1{}, cnt0{};

    for(int i = 0; i < n; i++) {
        if(s[i].size() % 2 == 0) {
            evlen += s[i].size();
        }

        cnt1 += count(s[i].begin(), s[i].end(), '1');
        cnt0 += count(s[i].begin(), s[i].end(), '0');
    }

    evlen -= cnt1 - (cnt1 % 2);
    evlen -= cnt0 - (cnt0 % 2);

    int ans = n;

    sort(s, s + n, [](const string &a, const string &b) {
            return a.size() > b.size();
    });

    for(int i = 0; i < n; i++) {
        if(s[i].size() % 2 == 0 && evlen > 0) {
            ans--;
            evlen = max(int(evlen - s[i].size()), 0);
        }
    }

    cout << ans << '\n';
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
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
