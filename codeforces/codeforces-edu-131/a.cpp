#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e4 + 3;
const int INF = 0x3f3f3f3f;

int n;
//int arr[MXN];
void solve()
{
    int cnt{}, num;
    for(int i = 0; i < 4; ++i) {
        cin >> num;
        if(num == 1) {
            cnt++;
        }
    }

    cout << (cnt > 0? (cnt > 3? 2: 1): 0) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
