ListNode *removeElements(ListNode *head, int val)
{
    ListNode **list = &head;  //pointer of pointer
    
    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }
    
    return head;
}
