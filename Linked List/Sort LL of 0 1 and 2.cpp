Node* segregate(Node *head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        Node* zero_head = new Node(-1);
        Node* one_head = new Node(-1);
        Node* two_head = new Node(-1);
        
        Node* zero_ptr = zero_head;
        Node* one_ptr =  one_head;
        Node* two_ptr = two_head;
        Node* temp_head = head;
        
        while(temp_head != nullptr)
        {
            if(temp_head->data == 0)
            {
                zero_ptr->next = temp_head;
                zero_ptr = temp_head;
            }
            else if(temp_head->data == 1)
            {
                one_ptr->next = temp_head;
                one_ptr = temp_head;
            }
            else
            {
                two_ptr->next = temp_head;
                two_ptr = temp_head;
            }
            temp_head = temp_head->next;
        }
        
        zero_ptr->next = (one_head->next != nullptr) ?  one_head->next : two_head->next;
        one_ptr->next =  two_head->next;
        two_ptr->next = nullptr;
            
        return zero_head->next;
    }
