#include <iostream>
using namespace std;

int n,k;
int pri[1005];
int dp[1005][2005] = {{0}};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1 ; i<=n ; i++)
        cin >> pri[i];
    for(int i=1 ; i<=2*k ; i++)
        dp[1][i] = -pri[1];
    for(int i=2 ; i<=n ; i++){
        for(int j=1 ; j<=2*k ; j++){
            if(j%2)
                dp[i][j] = max(dp[i-1][j-1] - pri[i] , dp[i-1][j]);
            else
                dp[i][j] = max(dp[i-1][j-1] + pri[i] , dp[i-1][j]);
        }
    }
    cout << dp[n][2*k] << "\n";
}

/*
3
2
2 4 1
*/
