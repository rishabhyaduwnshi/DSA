int find_length(Node* slow_node, Node* fast_node)
{
    int length = 1;
    slow_node = slow_node->next;
    while(slow_node != fast_node)
    {
        length++;
        slow_node = slow_node->next;
    }

    return length;
}


int lengthOfLoop(Node *head) 
{
    Node* slow_node = head;
    Node* fast_node = head;

    while(fast_node != nullptr && fast_node->next != nullptr)
    {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;

        if(slow_node == fast_node)
            return find_length(slow_node,fast_node);
    }

    return 0;
}
