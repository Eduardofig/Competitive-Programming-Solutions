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
vector<int> v;
 
void solve()
{
    if(count(v.begin(), v.end(), 1) == 0) {
        cout << 0 << '\n';
        return;
    }

    int i = 0;

    while(v.back() == 0) {
        v.pop_back();
    }

    while(v[i] == 0) {
        i++;
    }

    n = v.size();

    ll ans = 1;

    while(i < n - 1) {
        i++;
        ll mul = 1;
        while(v[i] == 0 && i < n - 1) {
            mul++;
            i++;
        }
        ans *= mul;
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    solve();
}
