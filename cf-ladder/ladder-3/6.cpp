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
ll tot = 0;
//int b[MXN];
//string s;
 
void solve()
{
    ll curr = 0;

    for(int i = 0; i < n; ++i) {
        curr += a[i];
        if(curr * 2 >= tot) {
            cout << i + 1 << '\n';
            return;
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
        tot += a[i];
    }
    solve();
}
