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
string grid[8];

map<char, int> mp = {
    {'q', 9},
    {'Q', -9},
    {'r', 5},
    {'R', -5},
    {'b', 3},
    {'B', -3},
    {'n', 3},
    {'N', -3},
    {'p', 1},
    {'P', -1},
    {'.', 0},
    {'K', 0},
    {'k', 0},
};
 
void solve()
{
    int sum = 0;

    for(int i = 0; i < 8; ++i) {
        for(char c: grid[i]) {
            sum += mp[c];
        }
    }

    if(sum == 0) {
        cout << "Draw\n";
    } else if(sum < 0) {
        cout << "White\n";
    } else {
        cout << "Black\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for(int i = 0; i < 8; ++i) {
        cin >> grid[i];
    }
    solve();
}
