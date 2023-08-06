#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int node_value;
        Node *left_child;
        Node *right_child;
};

class BinaryTree
{
    private:
        Node *root_node;
    public:
        queue<Node*> q;
        
        BinaryTree()
        {
            root_node = nullptr;
        }
        
        Node* getRootNode()
        {
            return root_node;
        }
        
        void createTree()
        {
            int input_data;
            root_node = new Node;
            cout<<"Enter root_node data :"<<" ";
            cin>>input_data;
            
            root_node->node_value = input_data;
            root_node->left_child = nullptr;
            root_node->right_child = nullptr;
            
            q.push(root_node);
            
            while(!q.empty())
            {
                Node *temp_node = q.front();
                q.pop();
                
                cout<<"Enter left child of "<<temp_node->node_value<<": ";
                cin>>input_data;
                
                if(input_data != -1)
                {
                    Node *left_child_node = new Node;
                    left_child_node->node_value = input_data;
                    left_child_node->left_child = nullptr;
                    left_child_node->right_child = nullptr;
                    temp_node->left_child = left_child_node;
                    q.push(left_child_node);
                }
                
                cout<<"Enter right child of "<<temp_node->node_value<<": ";
                cin>>input_data;
                
                if(input_data != -1)
                {
                    Node *right_child_node = new Node;
                    right_child_node->node_value = input_data;
                    right_child_node->left_child = nullptr;
                    right_child_node->right_child = nullptr;
                    temp_node->right_child = right_child_node;
                    q.push(right_child_node);
                }
            }
        }
        
        int max(int a, int b)
        {
            if(a>b)
                return a;
            else
                return b;
        }
        
        bool childrenSumProperty(Node* root_node)
        {
            if(root_node == nullptr)
                return true;
                
            if(root_node->left_child == nullptr && root_node->right_child == nullptr)
                return true;
            
           int sum = 0;
           if(root_node->left_child != nullptr)
                sum += root_node->left_child->node_value;
            
            if(root_node->right_child != nullptr)
                sum += root_node->right_child->node_value;
            
            return (root_node->node_value == sum && childrenSumProperty(root_node->left_child) && childrenSumProperty(root_node->right_child));
        }
};

int main()
{
   BinaryTree bt;
   bt.createTree();
   Node* root_node = bt.getRootNode();
   
    if(bt.childrenSumProperty(bt.getRootNode()))
        cout<<"Yes";
    else
        cout<<"No";
}
