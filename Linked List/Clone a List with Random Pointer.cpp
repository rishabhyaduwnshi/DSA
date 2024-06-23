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
