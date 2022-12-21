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

int n, k;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int tot = 0;
    int bran = 0;

    for(int i = 0; i < n; ++i) {
        tot += a[i];
        bran += min(8, tot);
        tot -= min(8, tot);
        
        if(bran >= k) {
            cout << i + 1 << '\n';
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

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
