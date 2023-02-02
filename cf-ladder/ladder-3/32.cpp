#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e3 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
ll M[MXN][MXN];
 
void solve()
{
    for(int i = 0; i < n; ++i) {
        int j1 = 0;

        while(M[i][j1] == 0) {
            j1++;
        }

        int j2 = j1 + 1;

        while(M[i][j2] == 0) {
            j2++;
        }

        cout << (ll)sqrt<ll>(M[i][j1] * M[i][j2] / M[j1][j2]) << ' ';
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
        for(int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }
    solve();
}
