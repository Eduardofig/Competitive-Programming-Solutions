#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 54;
const int INF = 0x3f3f3f3f;

int n;
int arr[MXN];
 
void solve()
{
    if((n & 1) == 1) {
        cout << "Mike\n";
        return;
    }

    auto it = min_element(arr, arr + n);
    if(((it - arr) & 1) == 0) {
        cout << "Joe\n";
        return;
    }
    cout << "Mike\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
