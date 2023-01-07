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
    int n25 = 0, n50 = 0;

    for(int i = 0; i < n; ++i) {
        if(a[i] == 25) {
            n25++;
        } else if(a[i] == 50) {
            if(n25 == 0) {
                cout << "NO\n";
                return;
            } else {
                n25--;
                n50++;
            }
        } else {
            if(n25 >= 1 && n50 >= 1) {
                n25--;
                n50--;
            } else if(n25 >= 3) {
                n25 -= 3;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
