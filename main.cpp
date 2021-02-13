#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e2;
int n;
long long dp[N][N],sum[N],ans;
bool poss[N][N];

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>dp[i][i];
        sum[i] = dp[i][i] + sum[i-1];
    }

    for(int i = 1;i<=n;i++) poss[i][i] = true;

    for(int l = 2;l<=n;l++){
        for(int i = 1;i<=n;i++){
            int j = i+l-1;
            if(j>n) continue;
            for(int k = i;k<j;k++){
                if(poss[i][k] && poss[k+1][j] && dp[i][k] == dp[k+1][j]){
                    dp[i][j] = sum[j] - sum[i - 1];
                    poss[i][j] = true;
                } else if(k != i){
                    for(int u = i;u<k;u++){
                        if(poss[i][u] && poss[u+1][k] && poss[k+1][j] && dp[i][u] == dp[k+1][j]){
                            dp[i][j] = sum[j] - sum[i - 1];
                            poss[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            ans = max(dp[i][j],ans);
        }
    }
    cout<<ans;

    return 0;
}
