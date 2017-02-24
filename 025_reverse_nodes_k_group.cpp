/**
 *Given this linked list: 1->2->3->4->5
 *
 *For k = 2, you should return: 2->1->4->3->5
 */

class Solution {
public:
        ListNode* reverseKGroup(ListNode* head, int k) {
                if(head==NULL||k==1) return head;
                int num=0;
                ListNode* preheader = new ListNode(-1);
                preheader->next = head;
                ListNode* cur = preheader, *nex, *pre = preheader;
                while(cur = cur->next) 
                        num++;
                while(num>=k) {
                        cur = pre->next;
                        nex = cur->next;
                        for(int i=1;i<k;++i) {
                                cur->next=nex->next;
                                nex->next=pre->next;
                                pre->next=nex;
                                nex=cur->next;
                        }
                        pre = cur; //shift k steps
                        num-=k; //shift k steps
                }
                return preheader->next; 
        }
};