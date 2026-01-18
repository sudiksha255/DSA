/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//min heap custom comparator
    struct Compare{
        bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
//creating a priority queue- min heap 
    priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
//pushing the initial nodes
    for(auto list:lists){
        if(list!=nullptr){
            pq.push(list);
        }
    }
    ListNode dummy(0);
    ListNode* tail=&dummy;

    while(!pq.empty()){
        ListNode* node=pq.top();
        pq.pop();

        tail->next=node;
        tail=tail->next;

        if(node->next!=nullptr){
            pq.push(node->next);
        }
    }
    return dummy.next;
    }
};