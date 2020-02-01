//关键是不会声明Trie *node=this;
//insert node=node->next[word[i]-'a']要放在外面 因为不管有没有创建Trie都要next

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(){
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node=this;
        for(int i=0;i<word.size();i++)
        {
            if(!node->next[word[i]-'a'])
            {
                node->next[word[i]-'a']=new Trie();    
            }
            
        }
        node->is_word=true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node=this;
        for(int i=0;i<word.size();i++)
        {
            if(!node->next[word[i]-'a'])
                return false;
            node=node->next[word[i]-'a'];
        }
        return node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node=this;
        for(int i=0;i<prefix.size();i++)
        {
            if(node->next[prefix[i]-'a']==nullptr)
                return false;
            else
                node=node->next[prefix[i]-'a'];
        }
        return true;
    }
private:
    array<Trie*,26>next{};
    bool is_word=false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */