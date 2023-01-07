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

int n, m;
//int k;
int a[MXN];
int b[MXN];
//string s;
 
void solve()
{
    int i = 0;
    int j = 0;

    int sa = 0;
    int sb = 0;
    int ans = 0;

    while(i < n && j < m) {
        if(sa != sb) {
            while(sa < sb) {
                sa += a[i++];
            } 

            while(sb < sa) {
                sb += b[j++];
            } 

        } else {
            sa = a[i++];
            sb = b[j++];
            ans++;
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    solve();
}
