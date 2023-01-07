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
    int tot = accumulate(a, a + 5, 0);
    
    if(tot % 5 == 0 && tot > 0) {
        cout << tot / 5 << '\n';
        return;
    }

    cout << "-1\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for(int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    solve();
}
