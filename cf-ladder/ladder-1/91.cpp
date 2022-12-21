#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 3e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m;
//int k;
int a[MXN];
int q[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(a, a + n);
    reverse(a, a + n);

    ll sum = accumulate(a, a + n, 0LL);

    for(int i = 0; i < m; ++i) {
        int j = q[i] - 1;

        if(j > n - 1) {
            cout << sum;
        } else {
            cout << sum - a[j] << '\n';
        }
    }
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
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> q[i];
    }
    solve();
}
