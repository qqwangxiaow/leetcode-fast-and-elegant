//用一个map 映射双链表的iterator  双链表保存一个pair 链表尾部满了就被删除
class LRUCache {
public:
    LRUCache(int capacity):capacity{capacity}{}
    int get(int key) {
        if(mymap.find(key)==mymap.end())
            return -1;
        l1.splice(l1.begin(),l1,mymap[key]); //将key iterator插入l1的头部
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
