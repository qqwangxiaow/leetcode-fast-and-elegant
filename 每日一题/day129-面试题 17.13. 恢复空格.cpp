//字典树优化dp
class Trie{
public:
    Trie():isword{false} {
        for(int i=0;i<26;i++)
        {
            this->next[i]=nullptr;
        }
    }
    void insert(string s)
    {
        Trie *cur=this;
        int len=s.size()-1;
        for(int i=len;i>=0;i--)
        {
            if(!cur->next[s[i]-'a'])
            {
                cur->next[s[i]-'a']=new Trie();
            }
            cur=cur->next[s[i]-'a'];
        }
        cur->isword=true;
    }

    bool search(string s)
    {
        Trie *cur=this;
        int len=s.size()-1;
        for(int i=len;i>=0;i--)
        {
            if(!cur->next[s[i]-'a'])
            {
                return false;
            }
            cur=cur->next[s[i]-'a'];
        }
        return cur->isword;
    }
    array<Trie*,26>next;
    bool isword;
};
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n=sentence.size();
        vector<int>dp(n+1,0);
        dp[0]=0;
        Trie *root=new Trie();
        for(auto &s:dictionary)
        {
            root->insert(s);
        }
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+1;
            Trie* curpos=root;
            for(int j=i;j>=1;j--)
            {
                int t=sentence[j-1]-'a';
                if(curpos->next[t]==nullptr)
                    break;
                else if(curpos->next[t]->isword)
                {
                    dp[i]=min(dp[i],dp[j-1]);
                }
                if(dp[i]==0)
                    break;
                curpos=curpos->next[t];
            }

        }
        return dp[n];


    }
};