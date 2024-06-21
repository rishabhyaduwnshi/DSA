ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        ListNode* temp_1 = headA;
        ListNode* temp_2 = headB;

        while(temp_1 != temp_2)
        {
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;

            if(temp_1 == temp_2)
                return temp_1;
            
            if(temp_1 == nullptr)
                temp_1 = headB;
            
            if(temp_2 == nullptr)
                temp_2 = headA;
        }

        return temp_1;
    }
