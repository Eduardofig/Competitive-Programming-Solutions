#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1000;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
int grid[100][100];
 
void solve()
{
    int di[] = {1, 0, -1, 0, 0};
    int dj[] = {0, 1, 0, -1, 0};

    int sum;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            sum = 1;

            for(int k = 0; k < 5; ++k) {
                int nexti = i + di[k];
                int nextj = j + dj[k];

                if(nexti >= 0 && nexti < 3 && nextj >= 0 && nextj < 3) {
                    sum += grid[nexti][nextj];
                }
            }

            cout << sum % 2;

        }
        cout << '\n';
    }

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    memset(grid, 0, sizeof grid);
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> grid[i][j];
        }
    }

    solve();
}
