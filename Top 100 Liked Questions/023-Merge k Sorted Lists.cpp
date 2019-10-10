//mergetwo
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        while(lists.size()>1)
        {
            lists.push_back(mergetwo(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* mergetwo(ListNode *l1,ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *cur=&dummy;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else
            {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next=l1?l1:l2;
        return dummy.next;
    }
};
//using priority queue and awesome lambda
class Solution {
public:
    struct compare{
    bool operator()(const ListNode *l,const ListNode *r)
    {
        return l->val>r->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto lambda = [](const ListNode* p1, const ListNode* p2){return p1->val>p2->val;};
        priority_queue<ListNode*,vector<ListNode *>,decltype(lambda)>pq(lambda);
        for(auto l:lists)
        {
            if(l)
                pq.push(l);
        }
        if(pq.empty())
            return nullptr;
        ListNode* result=pq.top();
        pq.pop();
        if(result->next)
            pq.push(result->next);
        ListNode* tail=result;
        while(!pq.empty())
        {
            tail->next=pq.top();
            pq.pop();
            tail=tail->next;
            if(tail->next)
                pq.push(tail->next);
        }
        return result;
    }
};