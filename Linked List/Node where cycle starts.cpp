Node* detectCycle(Node* head)
    {
        set<Node*> node_set;
        Node *temp_node = head;
        while(true)
        {
            if(node_set.find(temp_node) != node_set.end())
                return temp_node;
                
            node_set.insert(temp_node);
            temp_node = temp_node->next;
        }
    }
