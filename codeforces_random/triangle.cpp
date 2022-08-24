#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int x[3], y[3];
        for(int i = 0; i < 3; ++i) {
            cin >> x[i] >> y[i];
        }

        int ans = 0;
        int height;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i != j) {
                    if(y[i] == y[j]) {
                        ans = abs(x[i] - x[j]);
                        height = 0;
                    }
                }
            }
        }

        for(int i = 0; i < 3; ++i) {
            if(y[i] > height) {
                ans = 0;
            }
        }
        cout << ans << '\n';
    }
}
