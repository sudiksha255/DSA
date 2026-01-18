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
    ListNode* mergeTwoLists(ListNode*a,ListNode*b){
        if(!a) return b;
        if(!b) return a;
        if(a->val<b->val){
            a->next=mergeTwoLists(a->next,b);
            return a;
        }
        else{
            b->next=mergeTwoLists(a,b->next);
            return b;
        }
    }
    ListNode* mergeList(vector<ListNode*>&lists,int left,int right){
        if(left==right) return lists[left];
        int mid=left+(right-left)/2;
        ListNode* l1=mergeList(lists,left,mid);
        ListNode* l2=mergeList(lists,mid+1,right);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeList(lists,0,lists.size()-1);
    }
};