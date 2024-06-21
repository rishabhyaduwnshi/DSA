int add_one_number(Node* head)
    {
        if(head == nullptr)
            return 1;
        
        int carry = add_one_number(head->next);
        if(head->data + carry >= 10)
        {
            head->data = 0;
            return 1;
        }
        else
        {
            head->data = head->data+carry;
            return 0;
        }
    }
    
    Node* addOne(Node *head) 
    {
        Node* temp_node = head;
        int carry = add_one_number(temp_node);
        if(carry == 1)
        {
            Node* new_head = new Node(1);
            new_head->data = 1;
            new_head->next = head;
            return new_head;
        }
        else
            return head;
    }
