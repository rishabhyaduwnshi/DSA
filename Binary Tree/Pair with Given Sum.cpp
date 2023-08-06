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
        
        bool pairWithGivenSum(Node* root_node, int sum, unordered_set<int> &st)
        {
            if(root_node == nullptr)
                return false;
                
            if(pairWithGivenSum(root_node->left_child, sum,st))
                return true;
                
            if(st.find(sum-root_node->node_value) != st.end())
                return true;
            else
                st.insert(root_node->node_value);
                
            return pairWithGivenSum(root_node->right_child,sum,st);
            
        }
};

int main()
{
    BinarySearchTree bst;
    bst.insertNode(1);
    bst.insertNode(2);
    bst.insertNode(5);
    bst.insertNode(4);
    bst.insertNode(3);
    bst.insertNode(3);
    unordered_set<int> st;
    
    if(bst.pairWithGivenSum(bst.getRootNode(),6,st))
        cout<<"Yes";
    else
        cout<<"No";
    
}
