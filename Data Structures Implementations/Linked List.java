import java.lang.*;

class Node
{
    public int node_data;
    public Node next_node;
}

class LinkedLisT
{
    private Node head_node;
    private Node last_node;
    
    //constructor
    LinkedLisT()
    {
        head_node = null;
        last_node = null;
    }
    
    public void insertNode(int data)
    {
       if(head_node == null)
       {
           head_node = new Node();
           head_node.node_data = data;
           head_node.next_node = null;
           last_node = head_node;
       }
       else
       {
           Node temp_node = new Node();
           temp_node.node_data = data;
           temp_node.next_node = null;
           last_node.next_node = temp_node;
           last_node = last_node.next_node;
       }
    }
    
    public void printList()
    {
        Node temp_node = head_node;
        while(temp_node != null)
        {
            System.out.print(temp_node.node_data + " ");
            temp_node = temp_node.next_node;
        }
    }
}


class Main
{
    public static void main(String args[])
    {
        LinkedLisT l1 = new LinkedLisT();
        l1.insertNode(5);
        l1.insertNode(15);
        l1.insertNode(25);
        l1.insertNode(35);
        l1.printList();
    }
}
