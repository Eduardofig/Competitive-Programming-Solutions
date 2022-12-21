#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 103;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
//int a[MXN];
//int b[MXN];
int grid[MXN][MXN];
 
void solve()
{
    vector<int> cars;
    int ans = 0;
    for(int car = 0; car < n; ++car) {
        bool good = true;

        for(int i = 0; i < n; ++i) {
            if(grid[i][car] == 3 || grid[i][car] == 2) {
                good = false;
            }
        }

        for(int j = 0; j < n; ++j) {
            if(grid[car][j] == 3 || grid[car][j] == 1) {
                good = false;
            }
        }


        if(good) {
            ans++;
            cars.push_back(car);
        }
    }

    cout << ans << '\n';
    for(int car: cars) {
        cout << car + 1 << ' ';
    }
    if(cars.size() > 0) {
        cout << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    solve();
}
