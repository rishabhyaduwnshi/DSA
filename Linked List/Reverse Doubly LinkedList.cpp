Node* reverseDLL(Node* head)
{   
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* current_node = head;
    while(current_node != nullptr)
    {
        Node* previous_node = current_node->prev;

        current_node->prev = current_node->next;
        current_node->next = previous_node;

        current_node = current_node->prev;

        if(current_node != nullptr && current_node->next == nullptr)
            head = current_node;
    }
    
    return head;
}
