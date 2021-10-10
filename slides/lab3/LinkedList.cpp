#include <iostream>


using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    // Insert a node at the end of the linked list.
    void insertNode(int);
  
   // print the linked list.
    void printList();
  
    // delete node at given position
    void deleteNode(int);
};


void Linkedlist::insertNode(int data){

    // Create the new Node.
    Node* newNode = new Node(data);
    cout<<newNode<<endl;
    // Assign to head if the linked list is empty
    if (head == NULL) {
        this->head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
        // Update temp
        temp = temp->next;
    }
    temp->next = newNode ; 
}
  
void Linkedlist::deleteNode(int nodeOffset){
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
  
    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }
  
    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }
    // Check if the position to be
    // deleted is less than the length
    // of the linked list.

    if (ListLen < nodeOffset) {
        cout << "Index out of range"
             << endl;
        return;
    }
  
    // Declare temp1
    temp1 = head;
  
    // Deleting the head.
    if (nodeOffset == 1) {
  
        // Update head
        head = head->next;
        delete temp1;
        return;
    }
  
    
 // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {
  
        // Update temp2
        temp2 = temp1;
  
        // Update temp1
        temp1 = temp1->next;
    }
  
    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;
  
    // Delete the node
    delete temp1;
}

void Linkedlist::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << "@("<<temp<<")->";
        temp = temp->next;
        if(temp == NULL) cout<<"X"<<endl;
    }
}

int main(){
    
    /*
    code
    */
    return 0;
}
