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
    ll best = -INF;

    for(int polsz = 3; polsz <= n; ++polsz) {
        if((n - polsz) % polsz == 0) {
            int skip = (n - polsz) / polsz;
            //cout << skip << '\n';

            for(int st = 0; st <= skip; ++st) {
                ll tot = 0;
                for(int i = st; i < n; i += skip + 1) {
                    //cout << a[i % n] << '\n';
                    tot += a[i % n];
                }
                best = max(best, tot);
            }
        }
    }

    cout << best << '\n';
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
