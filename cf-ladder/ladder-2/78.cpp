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
    int j = n - 1;

    ll ans = 0;

    ll sum1 = 0, sum2 = 0;

    for(int i = 0; i < n; ++i) {
        sum1 += a[i];
        while(sum2 < sum1 && j > i) {
            sum2 += a[j];
            if(j > i + 1) {
                j--;
            } else {
                break;
            }
        }
        if(sum1 == sum2) {
            ans = max(ans, sum1);
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
