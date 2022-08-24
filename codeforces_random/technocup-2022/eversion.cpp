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
        int max = arr.back();
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(arr[i] > max) {
                ans++;
                max = arr[i];
            }
        }
        cout << ans << '\n';
    }
}
