#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e9 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, s, k;
set<int> closed;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

 
void solve()
{
    int i = s;
    int j = s;

    int d1 = INF, d2 = INF;
    while(closed.find(i) != closed.end()) {
        i++;
    }

    while(closed.find(j) != closed.end()) {
        j--;
    }

    if(i <= n) {
        d1 = i - s;
    }

    if(j >= 1) {
        d2 = s - j;
    }

    cout << min(d1, d2) << '\n';

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        closed.clear();
        cin >> n >> s >> k;
        for(int i = 0; i < k; ++i) {
            int floor;
            cin >> floor;

            closed.insert(floor);
        }
        solve();
    }
}
