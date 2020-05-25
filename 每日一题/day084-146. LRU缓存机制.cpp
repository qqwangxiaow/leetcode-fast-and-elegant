class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity){

    }
    
    int get(int key) {
        if(mymap.find(key)==mymap.end())
            return -1;
        l1.splice(l1.begin(),l1,mymap[key]);
        return mymap[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1)
        {
            mymap[key]->second=value;
        }
        else
        {
            if(capacity==l1.size())
            {   
                mymap.erase(l1.back().first);
                l1.pop_back();
            }
            l1.push_front(make_pair(key,value));
            mymap[key]=l1.begin();
        }

    }
private:
    int capacity;
    list<pair<int,int>>l1;
    unordered_map<int,list<pair<int,int>>::iterator>mymap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */