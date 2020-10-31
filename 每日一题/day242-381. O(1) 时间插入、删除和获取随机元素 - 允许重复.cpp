//主要是一个数组，map表示下表的set集合
//删除的时候跟最后一个位置交换删除  
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        myvec.push_back(val);
        mymap[val].insert(myvec.size()-1);
        return mymap[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mymap.find(val)==mymap.end())
            return false;
        int index=*(mymap[val].begin());
        myvec[index]=myvec.back();
        mymap[val].erase(index);
        mymap[myvec[index]].erase(myvec.size()-1); 
        if(index<myvec.size()-1)
        {
            mymap[myvec[index]].insert(index);
        }
        if(mymap[val].size()==0)
            mymap.erase(val);
        myvec.pop_back();
        return true;

    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return myvec[rand()%myvec.size()];

    }
private:
    unordered_map<int,unordered_set<int>>mymap;
    vector<int>myvec;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */