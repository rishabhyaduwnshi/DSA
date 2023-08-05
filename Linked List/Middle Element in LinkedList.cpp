int findMiddleNodeElement()
{
    Node* slow_ptr = head_node;
    Node* fast_ptr = head_node;
            
    while(fast_ptr != nullptr && fast_ptr->next_node != nullptr)
    {
        slow_ptr = slow_ptr->next_node;
        fast_ptr = fast_ptr->next_node->next_node;
    }

    return slow_ptr->node_value;
}
