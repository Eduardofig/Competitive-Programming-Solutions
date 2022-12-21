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

ull k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int low = 0, high = 10 * k;

    while(high > low) {
        int mid = low + (high - low) / 2;

        ull cubes = 0;

        for(int i = 1; i <= mid; ++i) {
            cubes += ((1 + i) * i) / 2;
        }

        if(cubes > k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << high - 1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> k;
    solve();
}
