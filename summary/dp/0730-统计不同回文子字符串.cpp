class Solution {
public:
    vector<int> find_sub(int i, int j, string& s){
        // i      k  mn l      j
        // a...................a  return [-1,-1] case B
        // a.........a.........a  return [m,m]   case C
        // a........ aa........a  return [m,n]   case D
        // a......a.....a......a  return [k,l]   case E
        char c = s[i];
        i++; j--;
        while(i<=j && s[i]!=c)  ++i;
        while(i<=j && s[j]!=c)  --j;
        if(i>j) return vector<int>({-1,-1});
        return vector<int>({i,j});
    }
    
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        
        //dp[i][j] is the number of palindromes in S from i to j, including empty string ""
        vector<vector<long>> dp(n,vector<long>(n,0)); 
        for(int i=0; i<n; ++i) dp[i][i] = 2;  //dp("a") = ("",a)
        for(int i=0; i<n-1; ++i) dp[i][i+1] = 3; //dp("aa") = ("",a,aa)  dp("ab") = ("",a,b)

        for(int len=2; len<n; ++len){
            for(int i=0; i+len<n; ++i){
                int j = i+len;
                if(S[i] != S[j]){
                    dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % 1000000007;
                    // e.g.  dp("abc") = dp("ab") + dp("bc") - dp("b")
                    //      ["",a,b,c] = ("",a,b) + ("",b,c) - ("",b)
                    
                    //printf("case A: dp[%d][%d] = %d\n",i,j,dp[i][j]);
                }
                else{
                    vector<int> v = find_sub(i,j,S);
                    if(v[0] == -1){
                        dp[i][j] = (dp[i+1][j-1] * 2 + 1) % 1000000007;
                        // e.g.  dp("abca") = dp("bc") + {a+dp("bc")+a} + 1
                        //      ["",a,b,c,aa,aba,aca] = ("",b,c) + (aa,aba,aca) + (a)
                        
                        // printf("case B: dp[%d][%d] = %d\n",i,j,dp[i][j]);
                    }
                    else if(v[1] == v[0]){
                        dp[i][j] = (dp[i+1][j-1] * 2) % 1000000007;
                        // e.g.  dp("abaca") = dp("bac") + {a+dp("bac")+a}
                        //      ["",a,b,c,aa,aaa,aba,aca] = ("",a,b,c) + (aa,aaa,aba,aca)
                        
                        //printf("case C: dp[%d][%d] = %d\n",i,j,dp[i][j]);
                    }
                    else if(v[1]-v[0]==1){
                        dp[i][j] = (dp[i+1][j-1] * 2 - 1) % 1000000007;
                        // e.g.  dp("abaaca") = dp("baac") + {a+dp("baac")+a} - 1
                        //      ["",a,b,c,aa,aaa,aba,aca,aaaa] = ("",a,b,c,aa) + (aa,aaa,aba,aca,aaaa) - (aa)
                        
                        //printf("case D: dp[%d][%d] = %d\n",i,j,dp[i][j]);
                    }
                    else{
                        dp[i][j] = (dp[i+1][j-1] * 2 - dp[v[0]+1][v[1]-1]) % 1000000007;
                        // e.g.  dp("abadaca") = dp("badac") + {a+dp("badac")+a} - {a+dp("d")+a}
                        //       ["",a,b,c,d,aa,aaa,aba,aca,ada,aaaa,aadaa] = 
                        //       ("",a,b,c,d,aa,ada) + (aa,aaa,aba,aca,ada,aaaa,aadaa)-(aa,ada)  //dp("d") = ("",d)
                        
                        //printf("case E: dp[%d][%d] = %d\n",i,j,dp[i][j]);
                    }
                }
            }
        }
        
        long ans = dp[0][n-1]-1; //empty string not counted
        return (ans<0)? ans+1000000007 : ans;
    }
    
    
};