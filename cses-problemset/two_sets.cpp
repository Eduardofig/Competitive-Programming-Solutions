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
    if((n / 2 + n % 2) % 2 == 1) {
        cout << "NO\n";
    } else {
        int new_n = n % 2 == 1? n - 1: n;
        vector<int> a, b;
        for(int i = 1; i < new_n / 2; i += 2) {
            a.push_back(i + 1);
            a.push_back(new_n - i);
        }
        for(int i = 0; i < new_n / 2; i += 2) {
            b.push_back(i + 1);
            b.push_back(new_n - i);
        }

        if(n % 2 == 1) {
            a.push_back(n);
        }

        cout << "YES\n";
        cout << a.size() << '\n';
        for(int i: a) {
            cout << i << ' ';
        }
        cout << '\n';

        cout << b.size() << '\n';
        for(int i: b) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    solve();
}
