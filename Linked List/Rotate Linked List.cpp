ListNode* rotateRight(ListNode* head, int k) 
{
    if (head == nullptr || head->next == nullptr || k == 0) 
        return head;

    int length = 1;
    ListNode* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
        length++;
    }
    
    k = k % length;
    if (k == 0) 
        return head;

    int steps_to_new_last = length - k - 1;
    ListNode* new_last_node = head;
    for (int i = 0; i < steps_to_new_last; i++) 
        new_last_node = new_last_node->next;

    ListNode* new_head = new_last_node->next;
    new_last_node->next = nullptr;
    temp->next = head;

    return new_head;
}
