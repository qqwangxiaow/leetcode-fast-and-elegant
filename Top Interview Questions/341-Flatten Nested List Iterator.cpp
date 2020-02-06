//using stack
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto it=nestedList.rbegin();it!=nestedList.rend();it++)
            s.push(*it);
    }
    int next() {
        auto temp=s.top();
        s.pop();
        return temp.getInteger();
    }
    bool hasNext() {
        while(!s.empty())
        {
            auto temp=s.top();
            if(temp.isInteger())
                return true;
            s.pop();
            auto cur=temp.getList();
            for(auto it=cur.rbegin();it!=cur.rend();it++)
                s.push(*it);
        }
        return false;  
    }
private:
    stack<NestedInteger>s;
};
