#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int node_value;
        Node *next_node;
};

class LinkedList
{
    private:
        Node *head_node;
        Node *last_node;
        
    public:
        LinkedList()
        {
            head_node = nullptr;
            last_node = nullptr;
        }
        
        
        Node* getRootNode()
        {
            return head_node;
        }
        
        
        void insertNode(int data)
        {
            if(head_node == nullptr)
            {
                head_node = new Node;
                head_node->node_value = data;
                head_node->next_node = nullptr;
                last_node = head_node;
            }
            else
            {
                Node* temp_node = new Node;
                temp_node->node_value = data;
                last_node->next_node = temp_node;
                last_node = last_node->next_node;
            }
        }
        
    
        bool isLoopInLinkedList()
        {
            Node* slow_ptr = head_node;
            Node* fast_ptr = head_node;
            
            do
            {
                slow_ptr = slow_ptr->next_node;
                fast_ptr = fast_ptr->next_node;
                
                if(fast_ptr != nullptr)
                    fast_ptr = fast_ptr->next_node;
    
            }
            while((slow_ptr && fast_ptr) && (slow_ptr != fast_ptr));
            
            if(slow_ptr == fast_ptr)
                return true;
            else
                return false;
        }
        
        void createLoop(int data)
        {
            Node* temp_node = new Node;
            temp_node->node_value = data;
            temp_node->next_node = head_node;
            last_node->next_node = temp_node;
        }
};



int main()
{
   LinkedList ll;
   ll.insertNode(5);
   ll.insertNode(10);
   ll.insertNode(15);
   ll.insertNode(20);
   ll.insertNode(25);
   ll.insertNode(30);
   ll.createLoop(45);
   
    if(ll.isLoopInLinkedList())
        cout<<"Yes";
    else
        cout<<"No";

}
