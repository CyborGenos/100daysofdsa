#include<bits/stdc++.h>
using namespace std;

// int coinChange(vector<int>& coins, int amount){
//     int dp[amount+1];
//     dp[0] = 0;
    
//     for(int i=1; i<=amount; i++){
//         dp[i]=INT_MAX-1;
//         for(int j=0; j<coins.size(); i++){
//             if(coins[j]<=i){
//                 dp[i] = min(dp[i], dp[i-coins[j]]+1);
//             }
//         }
//     }
//     // return dp[amount];
//     return dp[amount] == INT_MAX ? -1 : dp[amount];
// }

int coinChange(vector<int> &coins, int n)
{
    // creating the base dp array, with first value set to 0
    int dp[++n];
    dp[0] = 0;
    // more convenient to have the coins sorted
    sort(begin(coins), end(coins));
    // populating our dp array
    for (int i = 1; i < n; i++)
    {
        // setting dp[0] base value to 1, 0 for all the rest
        dp[i] = INT_MAX;
        for (int c : coins)
        {
            if (i - c < 0)
                break;
            // if it was a previously not reached cell, we do not add use it
            if (dp[i - c] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }
    return dp[--n] == INT_MAX ? -1 : dp[n];
}

int main(){
    vector<int> coins = {1,2,5};
    cout<<1<<endl;
    cout<<coinChange(coins, 11);
    return 0;
}