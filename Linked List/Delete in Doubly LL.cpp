Node * deleteAllOccurrences(Node* head, int k) 
{
    if(head == nullptr)
        return nullptr;

    Node* current_node = head;
    while(current_node != nullptr && current_node->data == k)
    {
        Node* temp_node = head;
        head = head->next;
        current_node = head;
        delete temp_node;
    }

    while(current_node != nullptr)
    {
        if(current_node->data == k)
        {
            Node* previous_node = current_node->prev;
            Node* next_node = current_node->next;
            Node* temp_node = current_node;

            if (previous_node != nullptr) 
                previous_node->next = next_node;
            if (next_node != nullptr) 
                next_node->prev = previous_node;
            current_node = next_node;
            delete temp_node;
        }
        else
        {
            current_node = current_node->next;
        }
    }

    return head;
}
