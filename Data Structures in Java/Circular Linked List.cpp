import java.lang.*;
import java.util.*;

class Node
{
    public int node_data;
    public Node next_node;
}

class CircularLinkedList
{
    private Node head_node;
    private Node last_node;
    
    //constructor
    CircularLinkedList()
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
            last_node.next_node = head_node;
        }
        else
        {
            Node temp_node = new Node();
            temp_node.node_data =  data;
            
            last_node.next_node = temp_node;
            last_node = last_node.next_node;
            last_node.next_node = head_node;
        }
    }
    
    public void printList()
    {
        Node temp_node = head_node;
        System.out.print(temp_node.node_data + " ");
        temp_node = temp_node.next_node;
        
        while(temp_node != head_node)
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
        CircularLinkedList L1 = new CircularLinkedList();
        L1.insertNode(10);
        L1.insertNode(20);
        L1.insertNode(30);
        L1.insertNode(40);
        L1.printList();
    }
}
