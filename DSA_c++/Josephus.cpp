#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int data) {
        val = data;
        next = nullptr;
    }
};
// we should have to create a circular linked list
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insertattail(int x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
     void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
void killing(int k) {
    if (head == nullptr) {
        cout << "List is empty, no one to eliminate." << endl;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != temp) {
        for (int i = 0; i < k - 1; i++) {
            prev = temp;
            temp = temp->next;
        }
        Node* q = temp;
        if (prev != nullptr) {
            prev->next = temp->next; 
        } else {
            head = temp->next; 
        }
        temp = temp->next; 
        delete q; 
    }
    // Last person remaining
    cout << "Last person remaining: " << temp->val << endl;
    delete temp; // Free memory of last remaining node  **important to delete 
    head = nullptr; // Reset head to nullptr
}
};
int main(){
    LinkedList l;
    int n;
    cout<<"Enter the  no of persons inside the  circle"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
      l.insertattail(i);
    }
    int k;
    cout<<"Enter the value of k such that  k-th person  eliminated until only one person remains "<<endl;
    cin>>k;
   l.display();
   l.killing(k);
   cout << "The last remaining person is: ";
    l.display();
}