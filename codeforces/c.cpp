#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
//int arr[MXN];
string a, b;
 
void solve()
{
    int ones_a = count(a.begin(), a.end(), '1');
    int ones_b = count(b.begin(), b.end(), '1');

    if(ones_a + (ones_a % 2) < ones_b) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b;
    solve();
}
