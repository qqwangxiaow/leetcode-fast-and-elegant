//using hash list
struct Node{
    int val;
    Node *next;
    Node(int val): val(val),next(nullptr){}
};
const int len = 100;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        arr=vector<Node*>(len,new Node(-1));
    }
    
    void add(int key) {
        int haval=key%len;
        Node *temp=arr[haval];
        if(temp->val!=-1)
        {
            while(temp)
            {
                if(temp->val==key)
                    return;
                if(!temp->next)
                {
                    Node *node=new Node(key);
                    temp->next=node;
                    return;
                }
                temp=temp->next;
            }
        }
        else 
        {
            temp->val=key;
            return;
        }
    }
    
    void remove(int key) {
        int haval=key%len;
        Node *temp=arr[haval];
        if(temp->val!=-1)
        {
            while(temp)
            {
                if(temp->val==key)
                {
                    temp->val=-1;
                    return;
                }
                temp=temp->next;
                
            }
        }     
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int haval=key%len;
        Node *temp=arr[haval];
            while(temp)
            {
                if(temp->val==key)
                    return true;
                temp=temp->next;
            }
        return false;
        
    }
private:
    vector<Node*>arr;
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
//using BST
struct MyHashSetNode{
    int val;
    MyHashSetNode *left,*right;
    MyHashSetNode(int v):val(v),left(nullptr),right(nullptr){}
    ~MyHashSetNode(){
        if(left!=nullptr) delete left;
        if(right!=nullptr) delete right;
    }
};
class MyHashSetTree{
private:
    MyHashSetNode *root;
public:
    MyHashSetTree() : root(nullptr) {}
    ~MyHashSetTree()
    {
        if(root!=nullptr)
            delete root;
    }
    MyHashSetNode *Insert(int x,MyHashSetNode *parent)
    {
        MyHashSetNode *result=parent;
        if(parent==nullptr)
        {
            result=new MyHashSetNode(x);
        }
        else if(x<parent->val)
        {
            parent->left=Insert(x,parent->left);
        }
        else if(x>parent->val)
        {
            parent->right=Insert(x,parent->right);
        }
        else 
        {
            return nullptr;
        }
        return result;
    }

    bool Insert(int x)
    {
        if(Find(x)!=nullptr)
            return false;
        root=Insert(x,root);
        return true;
    }
    MyHashSetNode *Find(int x,MyHashSetNode *parent)
    {
        MyHashSetNode *current=parent;
        int currentValue;
        while(current!=nullptr)
        {
            currentValue=current->val;
            if(x<currentValue)
            {
                current=current->left;
            }
            else if(x>currentValue)
            {
                current=current->right;
            }
            else 
            {
                return current;
            }
        }
        return nullptr;
    }
    MyHashSetNode *Find(int x)
    {
        if(root!=nullptr)
            return Find(x,root);
        return nullptr;
    }
    MyHashSetNode *FindMin(MyHashSetNode *parent)
    {
        MyHashSetNode *current=parent;
        MyHashSetNode *left=nullptr;
        if(current!=nullptr)
        {
            while((left=current->left)!=nullptr)
                current=left;
        }
        return current;
    }
    MyHashSetNode *RemoveMin(MyHashSetNode *parent)
    {
        if(parent==nullptr)
            return nullptr;
        else if(parent->left!=nullptr)
        {
            parent->left=RemoveMin(parent->left);
            return parent;
        }
        else {
            MyHashSetNode *result=parent->right;
            parent->right=parent->left=nullptr;
            delete parent;
            return result;
        }
    }
    MyHashSetNode *Remove(int x,MyHashSetNode *parent)
    {
        MyHashSetNode *current=parent;
        MyHashSetNode *left=nullptr;
        MyHashSetNode *right=nullptr;
        int currentValue;
        if(current!=nullptr)
        {
            left=current->left;
            right=current->right;
            currentValue=current->val;
        }
        if(current==nullptr)
        {
            return nullptr;
        }
        else if(x<currentValue)
        {
            current->left=Remove(x,left);
        }
        else if(x>currentValue)
        {
            current->right=Remove(x,right);
        }
        else if(left!=nullptr&&right!=nullptr)
        {
            current->val=FindMin(right)->val;
            current->right=RemoveMin(right);
        }
        else {
            current=(left!=nullptr)?left:right;
            parent->right=parent->left=nullptr;
            delete parent;
        }
        return current;
    }
    bool Remove(int x)
    {
        if(Find(x)==nullptr)
            return false;
        root=Remove(x,root);
        return true;
    }
};
class MyHashSet {
private:
    MyHashSetTree tree;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        tree.Insert(key);
        
    }
    
    void remove(int key) {
        tree.Remove(key);
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return tree.Find(key)!=nullptr;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */