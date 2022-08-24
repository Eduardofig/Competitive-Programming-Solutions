#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e3 + 3;
const int INF = 0x3f3f3f3f;

int n;
int a[MXN];

void solve()
{
    auto check = [](int days) {
        for(int i = 1; i < n; ++i) {
            if(days > a[i] && days > a[i - 1]) {
                return false;
            }
        }
        return true;
    };

    int high = min(a[0], a[n - 1]), low = 1;
    while(high > low) {
        int mid = high + (low - high) / 2;

        if(check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << high << '\n';
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
