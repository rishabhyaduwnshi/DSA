ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy_node = new ListNode(-1);
        ListNode* current_node = dummy_node;
        int carry = 0;
        int sum;

        while(temp1 != nullptr || temp2 != nullptr)
        {
            sum = carry;
            if(temp1 != nullptr)
                sum += temp1->val;
            if(temp2 != nullptr)
                sum += temp2->val;

            ListNode* adding_node = new ListNode(sum%10);
            carry = sum/10;

            current_node->next = adding_node;
            current_node = current_node->next;

            if(temp1 != nullptr)
                temp1 = temp1->next;
            
            if(temp2 != nullptr)
                temp2 = temp2->next;
        }

        if(carry != 0)
        {
            ListNode* adding_node = new ListNode(carry);
            current_node->next = adding_node;
        }

        return dummy_node->next;
    }
