int findNthElementFromLast(int n)
{
     Node* front_ptr = head_node;
     Node* last_ptr = head_node;
            
    for(int i=0;i<n;i++)
    {
        if(front_ptr != nullptr)
            front_ptr = front_ptr->next_node;
    }
                
    while(front_ptr != nullptr)
    {
        front_ptr = front_ptr->next_node;
        last_ptr = last_ptr->next_node;
    }

    return last_ptr->node_value;
}
