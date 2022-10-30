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
//int b[MXN];
//string s;
 
void solve()
{
    int tot = 0;
    int ans = 0;

    for(int i = 0; i < n; ++i) {
        int tmp = 1;
        for(int j = i; j < n; ++j) {
            if(j > i && a[j] != a[j - 1]) {
                tmp++;
            }
            ans += tmp;
        }
    }


    for(int q = 0; q < m; ++q) {
        int i, x;
        cin >> i >> x;

        if(i - 1 > 0) {
            if(a[i] == a[i - 1] && x != a[i]) {
                int r = i, l = i - 1;
                ans += l * (n - r);
            } else if(a[i] != a[i - 1] && x == a[i - 1]) {
                int r = i, l = i - 1;
                ans -= l * (n - r);
            }
        }

        if(i + 1 < n) {
            if(a[i] == a[i + 1] && x != a[i]) {
                int r = i + 1, l = i;
                ans += l * (n - r);
            } else if(a[i] != a[i + 1] && x == a[i + 1]) {
                int r = i + 1, l = i;
                ans -= l * (n - r);
            }
        }


        cout << ans << '\n';
        a[i] = x;
    }
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
    solve();
}
