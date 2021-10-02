Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.

#include<bits/stdc++.h>
using namespace std;
int numOfPairs(vector<string>& nums, string target) {
        
        int n = nums.size(); 
        int count = 0;
        for(int i=0; i< n; i++)
        {
            for(int j =0; j<n ; j++)
            {
                if(i!=j)
                {
                    string ans = nums[i] + nums[j];
                    if(ans == target)
                        count++;
                }
            }
        }
        return count;
    }
    int main()
    {
      int n;
      cin>>;
      
      string arr[n];
      for(int i=0; i< n ; i++)
          cin>>a[i];
       string target;
       cin>>target;
       cout<<"The no. of distinct pairs :"<<numOfPairs(a, target);
      return 0;
    }
    
