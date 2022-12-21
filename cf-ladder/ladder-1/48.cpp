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
int a[MXN];
//string s;
 
void solve()
{
    int npos = 0;
    int tot = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > 0) {
            npos++;
        }
        if(a[i] != 0) {
            tot++;
        }
    }

    int target = (n / 2) + (n % 2);

    if(npos >= target) {
        cout << 1 << '\n';
    } else {
        if(tot - npos < target) {
            cout << 0 << '\n';
        } else {
            cout << -1 << '\n';
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
    solve();
}
