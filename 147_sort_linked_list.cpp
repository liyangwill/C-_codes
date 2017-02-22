/**
 * 
 * sort a linked list
 * 
 */
class Solution{
public:
    ListNode *insertionSortList(ListNode *head){
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *pre = new_head, *cur = head;
        while(cur){
            if(cur->next && cur->next->val < cur->val){
                while(pre->next && pre->next->val < cur->next->val) pre = pre->next;
                //insert cur->next after pre
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            else cur = cur->next;
        }
        ListNode *res = new_head->next;
        return res;
    }
    
};