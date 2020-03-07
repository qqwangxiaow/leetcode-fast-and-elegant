//重点在于每个频率都拉一个list
//values 保存value，freq
//iters 告诉key的位置
//keys 告诉你拉在哪个list里了
class LFUCache {
public:
    LFUCache(int capacity):capacity(capacity),size(0),lfu(0){

    }
    
    int get(int key) {
        if(values.find(key)==values.end())
            return -1;
        update(key);
        return values[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return ;
        if(values.find(key)!=values.end())
        {
            values[key].first=value;
            update(key);
        }
        else
        {
            if(size==capacity)
            {
                int todel=keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(todel);
                iters.erase(todel);
            }
            else
                size++;
            values[key] = {value,1};
            keys[1].push_back(key);
            iters[key]=--keys[1].end();
            lfu=1;
        }
    }
private:
    int capacity,size,lfu;
    unordered_map<int,pair<int,int>>values;
    unordered_map<int,list<int>>keys;
    unordered_map<int,list<int>::iterator>iters;
    void update(int key)
    {
        int freq=values[key].second;
        auto it=iters[key];
        values[key].second++;
        keys[freq].erase(it);
        keys[freq+1].push_back(key);
        iters[key]=--keys[freq+1].end();
        if(keys[lfu].empty())
            lfu++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */