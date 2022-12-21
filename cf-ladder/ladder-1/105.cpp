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
int a[MXN];
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 5) {
            cnt++;
        }
    }

    if(cnt == n) {
        cout << -1 << '\n';
        return;
    }

    if(cnt < 9) {
        cout << 0 << '\n';
        return;
    }

    for(int i = 0; i < cnt - (cnt % 9); ++i) {
        cout << 5;
    }

    for(int i = 0; i < n - cnt; ++i) {
        cout << 0;
    }
    cout << '\n';
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
