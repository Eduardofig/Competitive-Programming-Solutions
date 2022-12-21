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
    for(int a = n; a >= 0; a--) {
        if(7 * a <= n && (n - 7 * a) % 4 == 0) {
            int b = (n - 7 * a) / 4;

            for(int i = 0; i < b; ++i) {
                cout << '4';
            }

            for(int i = 0; i < a; ++i) {
                cout << '7';
            }

            cout << '\n';

            return;
        }
    }

    cout << "-1\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}
