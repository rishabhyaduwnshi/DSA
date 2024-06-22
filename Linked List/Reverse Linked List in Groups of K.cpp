ListNode* reverse_list(ListNode* head)
    {
        ListNode* previous_node = nullptr;
        ListNode* current_node = head;
        ListNode* next_node = nullptr;

        while(current_node != nullptr)
        {
            next_node = current_node->next;
            current_node->next = previous_node;
            previous_node = current_node;
            current_node = next_node;
        }

        return previous_node;
    }

    ListNode* find_kth_node(ListNode* head, int k)
    {
        ListNode* temp_head = head;
        while(temp_head != nullptr && k > 1)
        {
            temp_head = temp_head->next;
            k--;
        }

        return temp_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (head == nullptr || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify insertion
        dummy->next = head;
        ListNode* previous_node = dummy;    // Use dummy as previous_node
        ListNode* current_node = head;

        while (current_node != nullptr) 
        {
            ListNode* start = current_node;
            ListNode* end = find_kth_node(start,k);

            if(end == nullptr)
                break;

            ListNode* next_group = end->next;
            end->next = nullptr;

            ListNode* reverse_head = reverse_list(start);
            previous_node->next = reverse_head;
            start->next = next_group;

            previous_node = start;
            current_node = next_group;
        }

        head = dummy->next;  // Update head to the correct starting point
        delete dummy;        // Delete the dummy node to avoid memory leak
        return head;
    }
