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
    if(a[n - 1] == 15) {
        cout << "DOWN\n";
        return;
    }

    if(a[n - 1] == 0) {
        cout << "UP\n";
        return;
    }

    if(n == 1) {
        cout << "-1\n";
        return;
    }

    cout << (a[n - 1] > a[n - 2]? "UP\n": "DOWN\n");
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
