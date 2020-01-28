//双端bfs 很厉害 每次phead都指向size小的dict,这里没有用queue,用了set，然后iterator遍历
//temp作为要加入的新的string集（用queue遍历的话就是要新加入queue的元素集合），直接与phead所指向的直接swap就行
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end()),head,tail,*phead,*ptail;
        if(dict.find(endWord)==dict.end())
            return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder=2;
        while(!head.empty()&&!tail.empty())
        {
            if(head.size()<tail.size())
            {
                phead=&head;
                ptail=&tail;
            }
            else
            {
                phead=&tail;
                ptail=&head;
            }
            unordered_set<string>temp;
            for(auto it=phead->begin();it!=phead->end();it++)
            {
                string word=*it;
                for(int i=0;i<word.size();i++)
                {
                    char t=word[i];
                    for(int j=0;j<26;j++)
                    {
                        word[i]='a'+j;
                        if(ptail->find(word)!=ptail->end())
                            return ladder;
                        if(dict.find(word)!=dict.end())
                        {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i]=t;
                }
            }
            ladder++;
            //swap(temp,*phead);
            phead->swap(temp);
        }
        return 0;

        
        
    }
};
//非常直接的dfs，diff=1，那么可以转换，加入队列，vis表示wordList中的单词有没有用过
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=1;
        vector<int>vis(wordList.size(),0);
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            ans++;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string tmp=q.front();
                q.pop();
                for(int j=0;j<wordList.size();j++)
                {
                    if(vis[j]==0)
                    {
                        int diff=0;
                        for(int k=0;k<tmp.size();k++)
                        {
                            if(tmp[k]!=wordList[j][k])
                                diff++;
                        }
                        if(diff==1)
                        {
                            if(wordList[j]==endWord)
                                return ans;
                            vis[j]=1;
                            q.push(wordList[j]);
                        }
                    }
                    
                }
            }
        }
        return 0;
    }
};
//another bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        queue<string>todo;
        todo.push(beginWord);
        int ret=1;
        while(!todo.empty())
        {
            int len=todo.size();
            for(int i=0;i<len;i++)
            {
                string word=todo.front();
                todo.pop();
                if(word==endWord)
                    return ret;
                dict.erase(word);
                for(int j=0;j<word.size();j++)
                {
                    char c=word[j];
                    for(int k=0;k<26;k++)
                    {
                        word[j]='a'+k;
                        if(dict.find(word)!=dict.end())
                        {
                            todo.push(word);
                        }
                    }
                    word[j]=c;
                }
            }
            ret++;
        }
        return 0;
    }
};