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

int k;
//int k;
//int a[MXN];
//int b[MXN];
string s;
 
void solve()
{
    sort(s.begin(), s.end());

    int ans = 0;

    int sum = 0;

    for(char c: s) {
        sum += c - '0';
    }

    int diff = k - sum;

    for(char c: s) {
        if(diff > 0) {
            ans++;
            diff -= 9 - (int)(c - '0');
        } else {
            cout << ans << '\n';
            return;
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


    cin >> k >> s;
    solve();
}
