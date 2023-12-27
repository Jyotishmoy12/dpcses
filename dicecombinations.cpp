#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void solve(){
    int n;
    cin>>n;
    vector<int>dp(n+1);
    // state
    // dp[i]= number of ways to make sum of i
    dp[0]=1; // number of ways to make sum of 0 is 1
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i>=j){
                //transition
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
}
int main(){
    solve();
}