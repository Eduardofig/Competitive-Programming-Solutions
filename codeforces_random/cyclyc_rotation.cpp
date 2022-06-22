#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e7;
int n, arr1[MXN], arr2[MXN];

void solve()
{
    int i = 0, j = n - 1, k = 0, l = n - 1;

    while(true) {
        if(i == j) {
            if(arr1[i] == arr2[k]) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }

            return;
        }

        if(arr1[i] == arr2[k]) {
            i++;
            k++;
        } else {
            if(arr1[i] == arr1[j] && 
               arr2[l] == arr1[i] &&
               arr2[l] == arr2[l - 1]) {
                i++;
                j--;
                l -= 2;
            } else if(arr1[j] == arr2[l]) {
                j--;
                l--;
            } else {
                cout << "no\n";
                return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> arr1[j];
        }
        for(int j = 0; j < n; ++j) {
            cin >> arr2[j];
        }
        solve();
    }
}
