 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* dummy_head = new ListNode;
        dummy_head->val = -1;

        ListNode* temp = dummy_head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val < temp2->val)
            {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }

        if(temp1 != nullptr)
            temp->next = temp1;
        else
            temp->next = temp2;

        return dummy_head->next;
    }
