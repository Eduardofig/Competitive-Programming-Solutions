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
int b[MXN];
//string s;
 
void solve()
{
    int tot = accumulate(b, b + n, 0);

    vector<int> diff;

    for(int i = 0; i < n; ++i) {
        diff.push_back(b[i] - a[i]);
    }
    sort(diff.rbegin(), diff.rend());

    for(int i = 0; i < k; ++i) {
        tot -= diff[i];
    }

    for(int i = k; i < n && diff[i] > 0; ++i) {
        tot -= diff[i];
    }

    cout << tot << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    solve();
}
