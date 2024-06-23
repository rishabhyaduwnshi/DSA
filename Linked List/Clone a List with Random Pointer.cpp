Node* copyRandomList(Node* head) 
    {
        Node* temp_head = head;
        unordered_map<Node*, Node*> maps;

        while(temp_head != nullptr)
        {
            maps[temp_head] = new Node(temp_head->val);
            temp_head = temp_head->next;
        }

        temp_head = head;
        while(temp_head != nullptr)
        {
            Node* temp_node = maps[temp_head];
            temp_node->next = maps[temp_head->next];
            temp_node->random = maps[temp_head->random];
            temp_head = temp_head->next;
        }

        return maps[head];
    }


//without using extra space
Node* restore_origianl_nodes(Node* head)
    {
        Node* temp_head = head;
        Node* result_node = new Node(-1);
        Node* dummy_node = result_node;

        while(temp_head != nullptr)
        {
            dummy_node->next = temp_head->next;
            temp_head->next = temp_head->next->next;
            dummy_node = dummy_node->next;
            temp_head = temp_head->next;
        }
        return result_node->next;
    }
    void copy_random_ptrs(Node* head)
    {
        Node* temp_head = head;
        while(temp_head != nullptr)
        {
            Node* copy_node = temp_head->next;
            if(temp_head->random != nullptr)
                copy_node->random = temp_head->random->next;
            else
                copy_node->random = nullptr;
            temp_head = temp_head->next->next;
        }
    }

    void insert_nodes(Node* head)
    {
        Node* temp_head = head;
        while(temp_head != nullptr)
        {
            Node* new_node = new Node(temp_head->val);
            new_node->next = temp_head->next;
            temp_head->next = new_node;
            temp_head = temp_head->next->next;
        }

    }

    Node* copyRandomList(Node* head) 
    {
        Node* temp_head = head;
        insert_nodes(temp_head);
        copy_random_ptrs(temp_head);
        Node* cloned_head = restore_origianl_nodes(head);
        return cloned_head;
    }
