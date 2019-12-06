/*basic struct 
Trie *next[26]={};
bool isword=false;
using this pointer 
*/
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {   
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node=this;
        for(char ch:word)
        {
            ch-='a';
            if(!node->next[ch])
                node->next[ch]=new Trie();
            node=node->next[ch];
        }
        node->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node=this;
        for(char ch:word)
        {
            ch-='a';
            if(!node->next[ch])
                return false;
            node=node->next[ch];
        }
        return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node=this;
        for(char ch:prefix)
        {
            ch-='a';
            if(!node->next[ch]) 
                return false;
            node=node->next[ch];
        }
        return true;
        
    }
private:
    Trie *next[26]={};
    bool isword=false;
};