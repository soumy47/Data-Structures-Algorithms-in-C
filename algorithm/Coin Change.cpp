Problem : You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
            
        int n = coins.size();
        
        int dp[n + 1][amount + 1];
            
        //dp[no_of_coins][amount]
        
        for(int i = 0; i <= amount ; i++)
        {
            dp[0][i] = INT_MAX - 1;  // coins = 0
        }
        
        for(int i = 0; i <= n ; i++)
        {
            dp[i][0] = 0;  // amount = 0
        }
        
        for(int j =1; j <= amount; j++)
        {
            if(j % coins[0] == 0)
            {
                dp[1][j] = j / coins[0];
            }
            else {
                dp[1][j] = INT_MAX - 1;
            }
        }
        for(int i = 2; i <= n ; i++)//no of coins
        {
            for(int j = 1; j <= amount; j++) //amount
            {
                if( coins[i - 1] <= j )
                    dp[i][j] = min( 1 + dp[i][j - coins[i - 1]], dp[i -1][j]);
                else
                    dp[i][j] = dp[i -1][j];
            }
        }
        if(dp[n][amount] == INT_MAX  || dp[n][amount] == INT_MAX - 1)
            return -1;
        return dp[n][amount];
    }
    
    int main()
    {
      int n;
      cin>>n;
      
      int coins[n];
      for(int i =0; i< n ; i++)
      {
        cin>>coins[i];
      }
      
      int amount;
      cin>>amount;
      cout<<"The minimum coins required : "<<coinChange(coins, amount) ;
      return 0;
    }
    
