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


void deletenode(struct node *&first, int data)
{
    struct node * current = first;// first will have the node after deletion
    
    struct node * prev = (node *)malloc(sizeof(node));
    while(current!=NULL)
    {
        if(current->data!=data)
        {
            prev=current;
            current = current->next;
        }
        else
        {
            prev->next = current->next;
            delete current;
            break;
        }
    }
}

void insertinsortedlist(struct node *& first, int data)
{
    struct node * current = first;// first will have the node after insertion
    struct node * newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    struct node * temp = (node *)malloc(sizeof(node));
    while(current)
    {
        if((current->data < data) && (current->next->data > data))
        {
            temp = current->next;
            current->next = newnode;
            newnode->next = temp;
            break;
        }
        current = current->next;
    }
}