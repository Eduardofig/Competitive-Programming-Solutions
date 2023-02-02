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
vector<pair<int, string>> v;
 
void solve()
{
    int curr = 0;

    for(const auto &[x, dir]: v) {
        if(dir == "North") {
            if(curr - x >= 0) {
                curr -= x;
            } else {
                cout << "NO\n";
                return;
            }
        } else if(dir == "South") {
            if(curr + x <= 20000) {
                curr += x;
            } else {
                cout << "NO\n";
                return;
            }

        } else if(curr == 0 || curr == 20000) {
            cout << "NO\n";
            return;
        }
    }

    if(curr == 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    v.resize(n);

    for(auto &[x, dir]: v) {
        cin >> x >> dir;
    }
    solve();
}
