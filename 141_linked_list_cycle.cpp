/**
 * check if there is a cycle in the linked list
 * 
 */
class Solution {
public:
        bool hasCycle(ListNode *head){
                if(head == null) return false;
                ListNode *walker = head, *runner = head;
                while(runner.next!=null && runner.next.next!=null){
                        walker = walker.next;
                        runner = runner.next.next;
                        if(walker==runner) return true;
                }
                return false;
        }
};