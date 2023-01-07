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
//int b[MXN];
//string s;
 
void solve()
{
    vector<int> b(a, a + n);
    sort(b.rbegin(), b.rend());

    multiset<int> ms;

    for(int i = 0; i < k; ++i) {
        ms.insert(b[i]);
    }

    cout << accumulate(ms.begin(), ms.end(), 0) << '\n';
    
    int m = ms.size();
    int prev = 0;
    int cnt = 0;
    for(int i = 0; i < n && cnt < m - 1; ++i) {
        auto it = ms.find(a[i]);

        if(it != ms.end()) {
            ms.erase(it);
            cout << i + 1 - prev << ' ';
            prev = i + 1;
            cnt++;
        }
    }
    cout << n - prev << '\n';
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
    solve();
}
