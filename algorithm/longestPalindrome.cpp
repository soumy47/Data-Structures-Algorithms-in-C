#include<bits/stdc++.h>
using namespace std;
 string solve(string s, int i, int j)
    {
        int n = s.size();
        while(i>=0  && j < n)
        {
            if(s[i] == s[j])
            {
                i--;
                j++;
            }
            else
                break;
        }
        
        return s.substr(i+1, j - i - 1);
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        string ans;
        int ans_len = 0;
        for(int i =0; i<n ; i++)
        {
            string odd = solve(s, i, i);
            int len1 = odd.size();
            
            if(ans_len < len1){
                ans_len = len1;
                ans = odd;
            }

            string even  = solve(s, i,i + 1);
            int len2 = even.size();
            
            if(ans_len < len2)
            {
                ans_len  = len2;
                ans = even;
            }
        }
        return ans;
    }


int main()
{
  string s;
  cin>>s;
  
  cout<<"The longest Palindromic substring  : "<<longestPalindrome(string s);
  return 0;
}
