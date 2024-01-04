#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1, vector<int>(b+1, 1e9));
    // dp[i][j]=min number of cuts to break a block
    // i*j into squares
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            // i height
            // j width
            if(i==j){
                // no further cut required
                dp[i][j]=0;
                continue;
            }
            // for making vertival cut
            for(int v=1;v<=i-1;v++){
                dp[i][j]=min(dp[i][j], dp[v][j]+dp[i-v][j]+1);
            }

            // cut at h-> horizontally so
            // we have [i][h] and [i][h-i] remianing
            for(int h=1;h<=j-1;h++){
                dp[i][j]=min(dp[i][j], dp[i][h]+dp[i][j-h]+1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
}
