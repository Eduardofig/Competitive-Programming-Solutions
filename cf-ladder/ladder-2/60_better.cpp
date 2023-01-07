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
//int b[MXN];
//string s;
vector<pair<int, int>> obs;
vector<pair<int, int>> vs;

void solve()
{
    ll xt = 0;
    ll yt = 0;

    for(auto &[x, y]: obs) {
        xt += x;
        yt += y;
    }

    for(auto &[a, b]: vs) {
        xt += a;
        yt += b;
    }

    cout << xt / n << ' ' << yt / n << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    vs.resize(n);
    obs.resize(n);
    for(auto &[x, y]: obs) {
        cin >> x >> y;
    }

    for(auto &[a, b]: vs) {
        cin >> a >> b;
    }

    solve();
}
