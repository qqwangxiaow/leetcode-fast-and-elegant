//use pq(lambda);
//pq defult big heap,greater means small heap; less means big heap
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto lambda=[](ListNode *l1,ListNode *l2){return l1->val>l2->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(lambda)>pq(lambda);
        ListNode *head=new ListNode(0),*tail=head;
        for(auto list:lists)
        {
            if(list)
                pq.push(list);
        }
        while(!pq.empty())
        {   
            tail->next=pq.top();
            pq.pop();
            tail=tail->next;
            if(tail->next)
                pq.push(tail->next);
        }
        return head->next;
        
    }
};
//erase interater lists.begin()
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        while(lists.size()>1)
        {
            lists.push_back(mergetwo(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
        
    }
    ListNode* mergetwo(ListNode *l1,ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *head=&dummy;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                head->next=l1;
                l1=l1->next;
            }
            else
            {
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        head->next=l1?l1:l2;
        return dummy.next;
    }
};