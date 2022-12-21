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

int a, b, c;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int sz = a * c;

    int high = sz / b;

    int low = 0;

    while(high > low) {
        int mid = low + (high - low) / 2;

        int has = mid * b;

        bool check = true;
        for(int t0 = 1; t0 <= c; ++t0) {
            if(has + t0 * b < a * t0) {
                check = false;
            }
        }

        if(check) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << high << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b >> c;
    solve();
}
