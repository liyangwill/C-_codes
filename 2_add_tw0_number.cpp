/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                ListNode preHead(0), *p = &preHead; //create listNode preHead with a pointer p.
                int extra=0;
                int sum=0;
                while(l1 || l2 || extra){
                        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
                        extra = sum/10;
                        p->next= new ListNode(sum%10);
                        p = p->next;
                        p->val = sum%10;
                        l1 = l1 ? l1->next : l1;
                        l2 = l2 ? l2->next : l2;
                }
                return preHead.next;
        }
};