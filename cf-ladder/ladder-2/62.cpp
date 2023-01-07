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
    int prefo[n + 1], prefe[n + 1];

    prefe[0] = 0;
    prefo[0] = 0;

    for(int i = 0; i < n; ++i) {
        int o = (i % 2 == 0) * a[i];
        int e = (i % 2 == 1) * a[i];

        prefe[i + 1] = prefe[i] + e;
        prefo[i + 1] = prefo[i] + o;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int se = prefe[i] + prefo[n] - prefo[i + 1];
        int so = prefo[i] + prefe[n] - prefe[i + 1];

        if(se == so) {
            ans++;
        }
    }
    cout << ans << '\n';
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
