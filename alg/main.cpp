#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e5;
long long int arr[MXN], inversions = 0;

void merge(int st, int e)
{
    bool flag = true;
    while(flag) {
        flag = false;

        for(int i = st + 1; i <= e; ++i) {
            if(arr[i] < arr[i - 1]) {
                flag = true;

                swap(arr[i], arr[i - 1]);
                inversions++;
            }
        }
    }
}

void solve_rec(int st, int e) {
    if (st == e) return;

    int mid = (st + e)/2;

    solve_rec(st, mid);
    solve_rec(mid + 1, e);

    merge(st, e);
}

void solve(int n)
{
    if(n == 0) exit(0);

    for(int i = 0; i < n; ++i) cin >> arr[i];

    inversions = 0;
    solve_rec(0, n - 1);

    cout << inversions << endl;
}

int main()
{
    int n;
    while(cin >> n) solve(n);
}
