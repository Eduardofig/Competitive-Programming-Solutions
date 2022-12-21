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
int s[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll a{}, b{};

    sort(s, s + n);
    
    for(int i = 0; i < n / 2; ++i) {
        a += s[i];
    }

    for(int i = n / 2; i < n; ++i) {
        b += s[i];
    }

    cout << a * a + b * b << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    solve();
}
