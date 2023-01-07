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

int k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
bool is_perfect(int x)
{
    int sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum == 10;
}

void solve()
{
    int curr = 0;
    for(int x = 0; x <= 211111111; ++x) {
        if(is_perfect(x)) {
            curr++;
            if(curr == k) {
                cout << x << '\n';
                return;
            }
        }
    }

    cout << (ll)1111111111 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> k;
    solve();
}
