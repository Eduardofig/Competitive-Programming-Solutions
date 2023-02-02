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

int n, r;
set<int> se;
//int k;
//int b[MXN];
//string s;
 
void solve()
{
    vector<int> v(se.begin(), se.end());
    n = v.size();

    int i = n;

    while((n - i) * r < v[i - 1] && i > 0) {
        i--;
    }

    cout << n - i << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        se.clear();

        cin >> n >> r;
        for(int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            se.insert(num);
        }
        solve();
    }
}
