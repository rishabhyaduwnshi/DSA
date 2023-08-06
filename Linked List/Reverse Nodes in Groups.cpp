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
        
        Node* reverseGroup(Node* head_node, int k)
        {
            Node *previous = nullptr;
            Node *current = head_node;
            
            for(int i=0;i<k;i++)
            {
                if(current == nullptr)
                    break;
                    
                Node* next_node = current->next_node;
                current->next_node = previous;
                previous = current;
                current = next_node;
            }
            
            return previous;
        }

        Node* reverseListInGroup(Node* head_node, int k)
        {
            if(head_node == nullptr || k <= 1)
                return head_node;
                
            Node* new_head = reverseGroup(head_node, k);
            Node* previous_group_end = head_node;
            
            Node* next_group_start = nullptr;
            Node* current = new_head;
            
            while(current != nullptr)
            {
                next_group_start = current;
                current = reverseGroup(current,k);
                previous_group_end->next_node = next_group_start;
                previous_group_end = next_group_start;
            }
            
            return new_head;
        }
        
        
                
        void printNodeValues()
        {
            Node *temp_node = head_node;
            while(temp_node != nullptr)
            {
                cout<<temp_node->node_value<<" ";
                temp_node = temp_node->next_node;
            }
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
   
   ll.reverseGroup(ll.getRootNode(),3);
   ll.printNodeValues();
}
