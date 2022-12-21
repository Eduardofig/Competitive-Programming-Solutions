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

int n, d;
//int k;
//int a[MXN];
//int b[MXN];
string s;
 
void solve()
{
    int ans = 0;
    for(int i = 0; i < n - 1;) {
        bool found = false;
        for(int j = min(i + d, n - 1); j > i; --j) {
            if(s[j] == '1') {
                i = j;
                ans++;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> d;
    cin >> s;
    solve();
}
