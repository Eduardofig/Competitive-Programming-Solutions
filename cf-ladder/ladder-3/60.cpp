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

ull n, m, k;
//int a[MXN];
//int b[MXN];
//string s;
ull p[MXN];
 
void solve()
{
    ull dec = 0;
    ull ans = 0;
    int i = 0;
    
    while(i < m) {
        ans++;

        ull curr = p[i] - dec;
        ull page_lim = (curr / k) * k + (curr % k > 0) * k;
        ull new_dec = dec;

        while(p[i] - dec <= page_lim && i < m) {
            i++;
            new_dec++;
        }
        dec = new_dec;
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    solve();
}
