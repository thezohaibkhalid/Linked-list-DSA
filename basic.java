// public class basic{


//     static class Node{
//         int data;
//         Node next;

//         Node(int data){
//             this.data=data;
//         }
//     }
//     public static void main( String[] Args){
//         Node n1 = new Node(10);
//         Node n2 = new Node(20);
//         Node n3 = new Node(30);

//         Node head = n1;
//         head.next = n2;
//         n2.next = n3;
//         n3.next = null;

//         insert(30, head, 3);
//         display(head);


//     }



//     static void insert(int data, Node head, int pos){
//         Node toAdd = new Node(data);
//         if(pos==0){
//             toAdd.next = head;
//             head = toAdd;
//             return;
//         }
//         Node prev = head;
//         for (int i = 0; i < pos - 1; i++){
//             prev = prev.next;
//         }
//         toAdd.next = prev.next;
//         prev.next = toAdd;
//     }
//     static void display(Node head){

//         Node temp = head;

//         while(temp != null){
//             System.out.println(temp.data);
//             temp = temp.next;
//         }
//     }
// }



import java.util.Scanner;

public class basic {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node n1 = new Node(10);
        Node n2 = new Node(20);
        Node n3 = new Node(30);

        Node head = n1;
        n1.next = n2;
        n2.next = n3;
        n3.next = null;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the value to insert: ");
        int dataToInsert = scanner.nextInt();

        System.out.print("Enter the position to insert (0 for the beginning): ");
        int positionToInsert = scanner.nextInt();

        head = insert(dataToInsert, head, positionToInsert);
        display(head);

        scanner.close();
    }

    static Node insert(int data, Node head, int pos) {
        Node toAdd = new Node(data);
        if (pos == 0) {
            toAdd.next = head;
            return toAdd;
        }
        Node prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev.next;
        }
        toAdd.next = prev.next;
        prev.next = toAdd;
        return head;
    }

    static void display(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}
