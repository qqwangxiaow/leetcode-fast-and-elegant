/*if(mypq.empty()) return nullptr;
tail=head not head->next;
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto lambda=[](const ListNode* l1,const ListNode* l2){return l1->val>l2->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(lambda)>mypq(lambda);
        for(auto list:lists)
        {
            if(list)
                mypq.push(list);
        }
        if(mypq.empty())
            return nullptr;
        ListNode* head=mypq.top();
        mypq.pop();
        ListNode *tail=head;
        if(tail->next)
            mypq.push(tail->next);
        while(!mypq.empty())
        {
            tail->next=mypq.top();
            mypq.pop();
            tail=tail->next;
            if(tail->next)
                mypq.push(tail->next);
        }
        return head;
   
    }
};