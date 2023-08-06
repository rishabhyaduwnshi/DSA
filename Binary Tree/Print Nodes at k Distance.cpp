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
        
            
        void inorderTraversal(Node* root_node)
        {
            if(root_node != nullptr)
            {
                inorderTraversal(root_node->left_child);
                cout<<root_node->node_value<<" ";
                inorderTraversal(root_node->right_child);
            }
        }
        
        void printNodesAtKDistance(Node* root_node, int k)
        {
            if(root_node == nullptr)
                return;
                
            if(k == 0)
                cout<<root_node->node_value<<" ";
                
            printNodesAtKDistance(root_node->left_child, k-1);
            printNodesAtKDistance(root_node->right_child, k-1);
        }
};

int main()
{
   BinaryTree bt;
   bt.createTree();
   //bt.inorderTraversal(bt.getRootNode());
   bt.printNodesAtKDistance(bt.getRootNode(),3);
}
