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
int ans = 0;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
vector<string> grid(8);
vector<bool> primary_diag(20, true), second_diag(20, true), vert(8, true), hor(8, true);

void unfill(int i, int j)
{
    vert[i] = true;
    hor[j] = true;
    primary_diag[8 + i - j - 1] = true;
    second_diag[i + j] = true;
}

void fill(int i, int j)
{
    vert[i] = false;
    hor[j] = false;
    primary_diag[8 + i - j - 1] = false;
    second_diag[i + j] = false;
}

bool allowed(int i, int j)
{
    return vert[i] &&
        hor[j] &&
        primary_diag[8 + i - j - 1] &&
        second_diag[i + j] &&
        grid[i][j] == '.';
}
 
void recurse(int i)
{
    if(i == 8) {
        ans++;
        return;
    }

    for(int j = 0; j < 8; ++j) {
        if(allowed(i, j)) {
            fill(i, j);
            recurse(i + 1);
            unfill(i, j);
        }
    }
}

void solve()
{
    recurse(0);
    cout << ans << '\n';
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
