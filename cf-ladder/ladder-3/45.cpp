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
 
void solve()
{
    int arr[n + 7];
    memset(arr, -1, sizeof arr);

    int curr = 1;

    for(int i = 2; i <= n; ++i) {
        if(arr[i] == -1) {
            arr[i] = curr;
            for(int j = i; j <= n; j += i) {
                arr[j] = curr;
            }
            curr++;
        }
        cout << arr[i] << ' ';
    }

    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}
