#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));

    // base case
    dp[0][0] = (arr[0][0] == '.') ? 1 : 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '*') {
                dp[i][j] = 0; // trapped cell
            } else {
                if (i > 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                }
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
                }
            }
        }
    }

    cout << dp[n-1][n-1] << endl;

    return 0;
}
