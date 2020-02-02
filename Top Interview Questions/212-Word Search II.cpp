//helper(ret,board,node,x+1,y);
//helper(ret,board,node,x-1,y); 这两个顺序换一下就会报错
//用trie保存所有word trie做修改 str表示该点点word 方便加入ret
//trie 作为参数 代替string 如果is_word为true 那么该单词就是了
class Trie {
public:
    Trie(){
    }
    void insert(string word) {
        Trie *node=this;
        for(int i=0;i<word.size();i++)
        {
            if(!node->next[word[i]-'a'])
            {
                node->next[word[i]-'a']=new Trie();    
            }
            node=node->next[word[i]-'a'];
        }
        node->is_word=true;  
        node->str=word;
    }
    void exist(vector<vector<char>>& board,vector<string>&ret) {
        Trie *node=this;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                helper(ret,board,node,i,j);
            }
        }
        
    }
    void helper(vector<string>& ret,vector<vector<char>>& board,Trie* node,int x,int y)
    {
        if(node->is_word==true){
            node->is_word=false;
            ret.push_back(node->str);
            return;
        }
        if(x<0||x==board.size()||y<0||y==board[x].size())return;
        if(board[x][y]=='#'||node->next[board[x][y]-'a']==nullptr)return;
        node=node->next[board[x][y]-'a'];
        char temp=board[x][y];
        board[x][y]='#';
        helper(ret,board,node,x+1,y);
        helper(ret,board,node,x-1,y);
        helper(ret,board,node,x,y+1);
        helper(ret,board,node,x,y-1);
        board[x][y]=temp;
    }
private:
    array<Trie*,26>next{};
    bool is_word=false;
    string str="";
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *node=new Trie();
        for(auto word:words)
        {
            node->insert(word);
        }
        vector<string>ret;
        node->exist(board,ret);
        return ret;
    }
    
};