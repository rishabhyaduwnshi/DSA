#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int node_value;
        Node *left_child;
        Node *right_child;
};

class BinarySearchTree
{
    private:
        Node *root_node;
    public:
        BinarySearchTree()
        {
            root_node = nullptr;
        }
        
        Node* getRootNode()
        {
            return root_node;
        }
        
        void insertNode(int data)
        {
            Node *temp_node;
            if(root_node == nullptr)
            {
                root_node = new Node;
                root_node->node_value = data;
                root_node->left_child = nullptr;
                root_node->right_child = nullptr;
                return;
            }
            else
            {
                Node *sliding_node = root_node;
                Node *not_null_node = root_node;
                while(sliding_node != nullptr)
                {
                    if(sliding_node->node_value > data)
                        {
                            not_null_node = sliding_node;
                            sliding_node = sliding_node->left_child;
                        }
                    else if(sliding_node->node_value < data)
                        {
                            not_null_node = sliding_node;
                            sliding_node = sliding_node->right_child;
                        }
                    else
                        return;
                }
                
                Node *new_node = new Node;
                new_node->node_value = data;
                
                new_node->left_child = nullptr;
                new_node->right_child = nullptr;
                
                if(not_null_node->node_value > data)
                    not_null_node->left_child = new_node;
                else
                    not_null_node->right_child = new_node;
                return;
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
        
        Node* getFloor(int data)
        {
            Node* result = nullptr;
            
            while(root_node != nullptr)
            {
                if(root_node->node_value == data)
                    return root_node;
                else if(root_node->node_value > data)
                    root_node = root_node->left_child;
                else
                {
                    result = root_node;
                    root_node = root_node->right_child;
                }
            }
            return result;
        }
};

int main()
{
    BinarySearchTree bst;
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(15);
    bst.insertNode(12);
    bst.insertNode(30);
    
    cout<<bst.getFloor(14)->node_value;
    
}
