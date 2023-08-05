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

        void reverseList(Node* first_node, Node* second_node)
        {
            if(first_node != nullptr)
            {
                reverseList(first_node->next_node, first_node);
                first_node->next_node = second_node;
            }
            else
                head_node = second_node;
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
   ll.reverseList(ll.getRootNode(),nullptr);
   ll.printNodeValues();
}
