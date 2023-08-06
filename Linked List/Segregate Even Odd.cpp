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
        
    
        void segregateEvenOddNodes()
        {
            Node* even_start = nullptr;
            Node* even_end = nullptr;
            Node* odd_start = nullptr;
            Node* odd_end = nullptr;
            
            for(Node* current_node = head_node; current_node != nullptr; current_node = current_node->next_node)
            {
                int node_data = current_node->node_value;
                if(node_data%2 == 0)
                {
                    if(even_start == nullptr)
                    {
                        even_start = current_node;
                        even_end = current_node;
                    }
                    else
                    {
                        even_end->next_node = current_node;
                        even_end = even_end->next_node;
                    }
                }
                else
                {
                    if(odd_start == nullptr)
                    {
                        odd_start = current_node;
                        odd_end = current_node;
                    }
                    else
                    {
                        odd_end->next_node = current_node;
                        odd_end = odd_end->next_node;
                    }
                }
            }
                
            even_end->next_node = odd_start;
            odd_end->next_node = nullptr;
            head_node = even_start;
            
            if(odd_start == nullptr || even_start == nullptr)
                return;
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
   ll.segregateEvenOddNodes();
   ll.printNodeValues();


}
