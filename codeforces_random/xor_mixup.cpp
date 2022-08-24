#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for(int i = 0; i < n; ++i) {
            int cum = 0;
            for(int j = 0; j < n; ++j) {
                if(j != i) {
                    cum ^= arr[j];
                }
            }
            if(cum == arr[i]) {
                cout << arr[i] << '\n';
                break;
            }
        }
    }
}
