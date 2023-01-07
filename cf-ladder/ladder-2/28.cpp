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
int k;
int a[MXN];
//int b[MXN];
string s;
int target;
 
void solve()
{
    sort(a, a + n);

    int ans1 = lower_bound(a, a + n, target) - a;
    int ans2 = upper_bound(a, a + n, target) - a;

    ans1 = ans1 + (ans1 / k) * 5 + 1;
    ans2 = ans2 + ((ans2 - 1) / k) * 5;

    cout << ans1 << ' ' << ans2 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> s;
        a[i] = s.size();
    }

    cin >> s;
    target = s.size();
    solve();
}
