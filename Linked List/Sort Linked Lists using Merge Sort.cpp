 ListNode* merge_lists(ListNode* head_1, ListNode* head_2)
    {
        ListNode* temp1 = head_1;
        ListNode* temp2 = head_2;
        ListNode* dummy_node = new ListNode;
        ListNode* dummy = dummy_node;

        dummy_node->val = -1;
        dummy_node->next = nullptr;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val < temp2->val)
            {
                dummy->next = temp1;
                dummy = temp1;
                temp1 = temp1->next;
            }
            else
            {
                dummy->next = temp2;
                dummy = temp2;
                temp2 = temp2->next;
            }
        }

        if(temp1 != nullptr)
            dummy->next = temp1;
        else
            dummy->next = temp2;

        return dummy_node->next;

    }

    ListNode* find_middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sort_lists(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* middle_node = find_middle(head);
        ListNode* left_head = head;
        ListNode* right_head = middle_node->next;
        middle_node->next = nullptr;
        
        left_head = sort_lists(left_head);
        right_head = sort_lists(right_head);

        return merge_lists(left_head,right_head);
    }

    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
            
        ListNode* temp_head = head;
        return sort_lists(temp_head);
    }
