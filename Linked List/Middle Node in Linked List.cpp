Node *findMiddle(Node *head) 
{
    Node* slow_node = head;
    Node* fast_node = head;

    while(fast_node != nullptr && fast_node->next != nullptr)
    {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
    }

    return slow_node;
}
