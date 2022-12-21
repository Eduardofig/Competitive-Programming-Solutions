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

int n, b, d;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int ans = 0;
    int curr_sum = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= b) {
            curr_sum += a[i];
            if(curr_sum > d) {
                ans++;
                curr_sum = 0;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> b >> d;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
