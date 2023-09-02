import java.lang.*;

class Node
{
    public int node_data;
    public Node previous_node;
    public Node next_node;
}

class DoublyLinkedList
{
    private Node head_node;
    
    //constructor
    DoublyLinkedList()
    {
        head_node = null;
    }
    
    public void insertNode(int data)
    {
        if(head_node == null)
        {
            head_node = new Node();
            head_node.node_data = data;
            head_node.previous_node = null;
            head_node.next_node = null;
        }
        else
        {
            Node temp_node = head_node;
            while(temp_node.next_node != null)
                temp_node = temp_node.next_node;
            
            Node inserted_node = new Node();
            inserted_node.node_data = data;
        
            inserted_node.previous_node = temp_node;
            inserted_node.next_node = null;
            temp_node.next_node = inserted_node;
            
        }
    }
    
    public void deleteNodeFromFront()
    {
        if(head_node == null)
            return;
            
        head_node = head_node.next_node;
    }
    
    public void deleteNodeFromLast()
    {
        Node temp_node = head_node;
        while(temp_node.next_node.next_node != null)
            temp_node = temp_node.next_node;
            
        temp_node.next_node = null;
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
        DoublyLinkedList dll = new DoublyLinkedList();
        dll.insertNode(10);
        dll.insertNode(20);
        dll.insertNode(30);
        dll.insertNode(40);
        dll.insertNode(50);
        
        System.out.print("List : ");
        dll.printList();
        System.out.print("\n");
        
        
        //delete element from front
        dll.deleteNodeFromFront();
        System.out.print("List after deleting first element : ");
        dll.printList();
        System.out.print("\n");
        
        //delete element from last
        dll.deleteNodeFromLast();
        System.out.print("List after deleting last element : ");
        dll.printList();
    }
}
