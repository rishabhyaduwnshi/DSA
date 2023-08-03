#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int node_value;
        Node *next_node;
};

class Queue
{
    private:
        Node *head_node;
        Node *last_node;
    public:
        
        Queue()
        {
            head_node = nullptr;
            last_node = nullptr;
        }
        
        void pushElement(int data)
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
                temp_node->next_node = nullptr;
                last_node->next_node = temp_node;
                last_node = last_node->next_node;
            }
        }
        
        void popElement()
        {
            if(head_node == nullptr)
                return;
                
            Node* temp_node = head_node;
            head_node = head_node->next_node;
            delete temp_node;
        }
        
        void printQueue()
        {
            Node* temp_node = head_node;
            while(temp_node != nullptr)
            {
                cout<<temp_node->node_value<<" ";
                temp_node = temp_node->next_node;
            }
        }
};



int main()
{
   Queue qq;
   qq.pushElement(10);
   qq.pushElement(20);
   qq.pushElement(30);
   
   qq.popElement();
   qq.popElement();
   
   qq.pushElement(40);
   qq.pushElement(50);
   qq.printQueue();
}
