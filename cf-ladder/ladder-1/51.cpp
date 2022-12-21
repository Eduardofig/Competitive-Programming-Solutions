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
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    set<int> se;
    for(int i = 0; i < n; ++i) {
        se.insert(a[i]);
    }

    int ans = 0;
    while(!se.empty()) {
        ans++;
        int curr = *(se.begin());

        for(int i = curr; i <= 100; i += curr) {
            if(se.find(i) != se.end()) {
                se.erase(i);
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

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
