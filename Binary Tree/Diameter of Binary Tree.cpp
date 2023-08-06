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
        
        int max(int a, int b)
        {
            if(a>b)
                return a;
            else
                return b;
        }
        
        int heightOfBinarytree(Node* root_node)
        {
            if(root_node == nullptr)
                return 0;
            return 1+heightOfBinarytree(root_node->left_child)+heightOfBinarytree(root_node->right_child);
        }
        
        int diameterOfTree(Node* root_node)
        {
            if(root_node == nullptr)
                return 0;
                
            int d1 = 1+heightOfBinarytree(root_node->left_child)+heightOfBinarytree(root_node->right_child);
            int d2 = diameterOfTree(root_node->left_child);
            int d3 = diameterOfTree(root_node->right_child);
            
            return max(d1,max(d2,d3));
            
        }
};

int main()
{
   BinaryTree bt;
   bt.createTree();
   cout<<bt.diameterOfTree(bt.getRootNode());
}
