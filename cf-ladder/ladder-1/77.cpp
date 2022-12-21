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
pair<int, int> a[MXN];
 
void solve()
{
    reverse(a, a + n);
    bool changed = false;
    for(int i = 0; i < n; ++i) {
        if(a[i].first != a[i].second) {
            changed = true;
        }
    }

    if(changed) {
        cout << "rated\n";
    } else {
        if(is_sorted(a, a + n)) {
            cout << "maybe\n";
        } else {
            cout << "unrated\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    solve();
}
