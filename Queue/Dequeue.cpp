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
        
        void pushElementAtFront(int data)
        {
            Node* temp_node = new Node;
            temp_node->node_value = data;
            temp_node->next_node = head_node;
            head_node = temp_node;
        }
        
        void popElementFromFront()
        {
            if(head_node == nullptr)
                return;
                
            Node* temp_node = head_node;
            head_node = head_node->next_node;
            delete temp_node;
        }
        
        
        void pushElementAtLast(int data)
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
        
        void popElementFromLast()
        {
            Node* temp_node= head_node;
            Node* sliding_node = nullptr;
            
            while(temp_node != last_node)
            {
                sliding_node = temp_node;
                temp_node = temp_node->next_node;
            }
            
            sliding_node->next_node = nullptr;
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
   qq.pushElementAtLast(10);
   qq.pushElementAtLast(20);
   qq.pushElementAtLast(30);
   
   qq.popElementFromFront();
   qq.popElementFromFront();
   
   qq.pushElementAtLast(40);
   qq.pushElementAtLast(50);
   
   qq.pushElementAtFront(100);
   qq.pushElementAtFront(150);
   qq.pushElementAtLast(800);
   qq.pushElementAtLast(60);
   qq.popElementFromLast();
   qq.printQueue();
}
