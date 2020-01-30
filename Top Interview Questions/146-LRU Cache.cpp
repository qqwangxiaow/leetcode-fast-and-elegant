//为什么用双链表 因为能O(1)的把动过的元素放在最前面，删除back也很方便
//再用map就能O(1)找到元素的位置，key对应在双链表中的iterator
//list::splice很关键 实现list拼接功能
//void splice ( iterator position, list<T,Allocator>& x, iterator it );
//这种声明把x中it的值剪接到要操作的list的position中
class LRUCache {
public:
    LRUCache(int capacity):capacity{capacity} {
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
            return;
        }
        if(mymap.size()==capacity)
        {
            int todel=l1.back().first;
            l1.pop_back();
            mymap.erase(todel);
        }
        l1.emplace_front(key,value);
        mymap[key]=l1.begin();
        return ;
    }
private:
    int capacity;
    list<pair<int,int>>l1;
    map<int,list<pair<int,int>>::iterator>mymap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */