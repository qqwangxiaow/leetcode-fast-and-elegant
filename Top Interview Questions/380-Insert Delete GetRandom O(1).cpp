//using map and vector to get O(1) insert and delete (vector back)
//using rand()%vector.size() to get random num
//when remove erase must be the last operation
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {   
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mymap.find(val)!=mymap.end())
            return false;
        else
        {
            myvec.push_back(val);
            mymap[val]=myvec.size()-1;
            return true;
        }
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mymap.find(val)==mymap.end())
            return false;
        else{
            int last=myvec.back();
            int indextodel=mymap[val];
            mymap[last]=indextodel;
            myvec[indextodel]=last;
            myvec.pop_back();
            mymap.erase(val);
            return true;
        }
    }
    /** Get a random element from the set. */
    int getRandom() {
        int size=myvec.size();
        if(size==0)
            return 0;
        return myvec[rand()%size];  
    }
private:
    unordered_map<int,int>mymap;
    vector<int>myvec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */