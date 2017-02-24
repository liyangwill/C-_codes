/**
 *  &head: the address of head, pointer of pointer
 *  in order to change pointer (adress), we need pointer of pointer
 */

class Solution {
public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
                ListNode** t1 = &head, *t2 = head;
                for(int i = 1; i < n; ++i)
                {
                        t2 = t2->next;
                }
                while(t2->next != NULL)
                {
                        t1 = &((*t1)->next);//move pointer of pointer
                        t2 = t2->next;
                }
                *t1 = (*t1)->next; //change pointer 
                return head; 
        }
};