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

        void removeDuplicates()
        {
            Node* current_node = head_node;
            while(current_node->next_node != nullptr)
            {
                Node* temp_node = current_node->next_node;
                if(current_node->node_value == temp_node->node_value)
                {
                    current_node->next_node = temp_node->next_node;
                    delete temp_node;
                }
                else
                {
                    current_node = current_node->next_node;
                }
            }
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
   ll.insertNode(5);
   ll.insertNode(10);
   ll.insertNode(10);
   ll.insertNode(15);
   ll.insertNode(15);
   ll.insertNode(20);
   ll.insertNode(20);
   ll.removeDuplicates();
   ll.printNodeValues();
}
