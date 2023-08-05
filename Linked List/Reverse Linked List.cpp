void reverseList()
{
   Node *p = nullptr, *q = nullptr, *r = head_node;
   while (r != nullptr)
    {
        p = q;
        q = r;
        r = r->next_node;
        q->next_node = p;
    }
            
  head_node = q;
}
