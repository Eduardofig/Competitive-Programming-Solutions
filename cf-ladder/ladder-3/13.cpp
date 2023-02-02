#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e6 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;

int smli[MXN];
int bgi[MXN];
int cnt[MXN];

 
void solve()
{
    memset(smli, INF, sizeof smli);
    memset(bgi, 0, sizeof smli);

    int best = 0;
    for(int i = 0; i < n; ++i) {
        smli[a[i]] = min(smli[a[i]], i);
        bgi[a[i]] = max(bgi[a[i]], i);
        cnt[a[i]]++;
        best = max(best, cnt[a[i]]);
    }

    int len = INF;
    int l = -1, r = -1;
    for(int i = 0; i < n; ++i) {
        int new_len = bgi[a[i]] - smli[a[i]];
        if(cnt[a[i]] == best && new_len < len) {
            len = new_len;
            l = smli[a[i]];
            r = bgi[a[i]];
        }
    }

    cout << l + 1 << ' ' << r + 1 << '\n';
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
