Node* merge_lists(Node* head_1, Node* head_2) 
{
    Node dummy_node(-1);
    Node* temp1 = head_1;
    Node* temp2 = head_2;
    Node* temp_head = &dummy_node;

    while (temp1 != nullptr && temp2 != nullptr) 
    {
        if (temp1->data < temp2->data) 
        {
            temp_head->bottom = temp1;
            temp_head = temp1;
            temp1 = temp1->bottom;
        } 
        else 
        {
            temp_head->bottom = temp2;
            temp_head = temp2;
            temp2 = temp2->bottom;
        }
    }

    if (temp1 != nullptr) 
    {
        temp_head->bottom = temp1;
    } 
    else 
    {
        temp_head->bottom = temp2;
    }

    return dummy_node.bottom;
}


Node *flatten(Node *root)
{
    if(root == nullptr || root->next == nullptr)
        return root;
    
    Node* head_node = root;
    Node* merged_head = flatten(root->next);
    Node* new_head = merge_lists(head_node, merged_head);
    return new_head;
}
