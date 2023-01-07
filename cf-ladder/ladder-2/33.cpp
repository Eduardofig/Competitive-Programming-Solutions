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
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int tot = (n * (n + 1)) / 2;

    for(int i = 2; i * i <= tot; ++i) {
        if((tot % i) == 0) {
            cout << "Yes\n";
            cout << 1 << ' ' << i << '\n';
            cout << n - 1 << ' ';
            for(int j = 1; j <= n; ++j) {
                if(j != i) {
                    cout << j << ' ';
                }
            }
            cout << '\n';
            return;
        }
    }

    cout << "No\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}
