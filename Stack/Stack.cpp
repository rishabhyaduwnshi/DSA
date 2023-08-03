#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int node_value;
        Node *next_node;
        Node *previous_node;
};

class Stack
{
    private:
        Node *top_node;
    public:
        
        Stack()
        {
            top_node = nullptr;
        }
        
        Node* getTopNode()
        {
            return top_node;
        }
        
        void pushElement(int data)
        {
            if(top_node == nullptr)
            {
                top_node = new Node;
                top_node->node_value = data;
                top_node->next_node = nullptr;
                top_node->previous_node = nullptr;
            }
            else
            {
                Node* temp_node = new Node;
                
                top_node->next_node = temp_node;
                
                temp_node->node_value = data;
                temp_node->next_node = nullptr;
                temp_node->previous_node = top_node;
                
                top_node = top_node->next_node;
            }
        }
        
        void popElement()
        {
            if(top_node == nullptr)
                return;
            
            Node* temp_node = top_node;
            top_node = top_node->previous_node;
            delete temp_node;
        }
        
        
        void printStack()
        {
            Node* temp_node = top_node;
            while(temp_node != nullptr)
            {
                cout<<temp_node->node_value<<" ";
                temp_node = temp_node->previous_node;
            }
        }
};



int main()
{
   Stack st;
   st.pushElement(10);
   st.pushElement(20);
   st.pushElement(30);
   
   st.popElement();
   st.popElement();
   
   st.pushElement(40);
   st.pushElement(50);
   st.printStack();
}
