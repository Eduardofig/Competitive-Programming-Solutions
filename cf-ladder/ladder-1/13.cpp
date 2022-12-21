#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e3 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    map<int, int> cnt;
    for(int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] != 0) {
            if(cnt[a[i]] > 2) {
                cout << -1 << '\n';
                return;
            }
            ans += cnt[a[i]] / 2;
            cnt[a[i]] = 0;
        }
    }

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
