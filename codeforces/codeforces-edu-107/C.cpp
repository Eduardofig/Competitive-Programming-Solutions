#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 3e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
int q;
int c[MXN];
int t[MXN];
//string s;
 
void solve()
{
    int best_c[51];
    memset(best_c, -1, sizeof best_c);

    for(int i = 0; i < n; ++i) {
        if(best_c[c[i]] == -1) {
            best_c[c[i]] = i;
        }
    }

    for(int i = 0; i < q; ++i) {
        cout << best_c[t[i]] + 1 << ' ';

        for(int j = 1; j <= 50; ++j) {
            if(best_c[t[i]] > best_c[j]) {
                ++best_c[j];
            }
        }

        best_c[t[i]] = 0;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for(int i = 0; i < q; ++i) {
        cin >> t[i];
    }
    solve();
}
