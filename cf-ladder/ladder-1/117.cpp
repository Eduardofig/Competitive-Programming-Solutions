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

int a, b;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    vector<int> ans = {b};

    while(b != a && b > 0) {
        if(b % 2 == 0) {
            b /= 2;
        } else if(b % 10 == 1) {
            b -= 1;
            b /= 10;
        } else {
            cout << "NO\n";
            return;
        }

        ans.push_back(b);
    }

    if(b == a) {
        cout << "YES\n" << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for(int i: ans) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    solve();
}
