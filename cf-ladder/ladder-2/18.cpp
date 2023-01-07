#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;

void solve()
{
    int cnt[5]{};

    for(int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    int ans = cnt[4];

    int curr = min(cnt[3], cnt[1]);

    ans += curr;

    cnt[3] -= curr;
    cnt[1] -= curr;

    ans += cnt[3];

    ans += cnt[2] / 2;

    cnt[2] %= 2;

    cnt[1] -= min({cnt[1], cnt[2] * 2});

    ans += cnt[2];

    ans += cnt[1] / 4 + (cnt[1] % 4 > 0);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
