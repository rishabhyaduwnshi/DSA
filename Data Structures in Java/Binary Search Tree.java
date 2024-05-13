import java.lang.*;

class Node
{
    public int node_data;
    public Node left_node;
    public Node right_node;
}

class BinarySearchTree
{
    //data member
    private Node root_node = null;
    
    //constructor
    BinarySearchTree()
    {
        root_node = null;
    }
    
    //add a node
    
    public void insert_node(int data)
    {
        if(root_node == null)
        {
            root_node = new Node();
            root_node.node_data = data;
            root_node.left_node = null;
            root_node.right_node = null;
            return;
        }
        else
        {
            Node temp_node = root_node;
            Node trailing_node = new Node();
            trailing_node = null;
            
            Node attached_node = new Node();
            attached_node.node_data = data;
            attached_node.left_node = null;
            attached_node.right_node = null;
            
            while(temp_node != null)
            {
                trailing_node = temp_node;
                if(temp_node.node_data > data)
                    temp_node = temp_node.left_node;
                    
                else if(temp_node.node_data < data)
                    temp_node = temp_node.right_node;
                else
                    return;
                    
            }
            
            if(trailing_node.node_data > data)
                trailing_node.left_node = attached_node;
            else
                trailing_node.right_node = attached_node;
            return;
        }
    }
    
    Node get_root_node()
    {
        return root_node;
    }
    
    public void inorder_traversal(Node root_node)
    {
        if(root_node != null)
        {
            inorder_traversal(root_node.left_node);
            System.out.println(root_node.node_data + " ");
            inorder_traversal(root_node.right_node);
        }
        
    }
    
}

class Main
{
    public static void main(String args[])
    {
        BinarySearchTree b1 = new BinarySearchTree();
        b1.insert_node(10);
        b1.insert_node(5);
        b1.insert_node(20);
        b1.insert_node(50);
        b1.insert_node(70);
        b1.insert_node(40);
        Node b1_root_node = b1.get_root_node();
        b1.inorder_traversal(b1_root_node);
    }
}
