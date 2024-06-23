// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next=nullptr;
//     Node(int data){
//         val=data;
//         next=nullptr;
//     }
// };
// class LinkedList{
//  public:
//  Node* head;
//      // ptr is representing to address of starting listnode
//      LinkedList(){
//         head=nullptr;
//      }
//       void insertattail(int x){
//         Node* new_node=new Node(x);
//           if(head==nullptr){
//        head=new_node;
//        return;
//   }
//   Node* temp=head;
//   while(temp->next!=nullptr){
//     temp=temp->next;
//   }
//   //temp is poinitng to last listnode
//   temp->next=new_node;
//   new_node->next=nullptr;
//      }
//      void sorting(Node* head){
//         Node* curr=head;
//         while(curr!=NULL){
//             Node* temp=head;
//             while(temp!=NULL){
//                 if (curr->val > temp->val) {
//                     // Swap values
//                     int swap_val = curr->val;
//                     curr->val = temp->val;
//                     temp->val = swap_val;
//                 temp=temp->next;
//             }
//         }
//      }
//      }
//      void display(){
//         Node* temp=head;
//         while(temp!=nullptr){
//      cout<<temp->val<<"->";
//      temp=temp->next;
//         }
//         cout<<"nullptr"<<endl;
//      }
// };
// int main(){
//     LinkedList l;
//     l.insertattail(4);
//     l.insertattail(2);
//     l.insertattail(1);
//     l.insertattail(3);
//     l.display();
//     cout<<endl;
//     cout<<"After Sorting :"<<endl;
//     l.sorting(l.head);
//     l.display();
//     return 0;
// }
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
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void sorting() {
        if (head == nullptr) return;
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr->next;
            while (temp != nullptr) {
                if (curr->val > temp->val) {
                    // Swap values
                    int swap_val = curr->val;
                    curr->val = temp->val;
                    temp->val = swap_val;
                }
                temp = temp->next;
            }
            curr = curr->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList l;
    l.insertattail(4);
    l.insertattail(2);
    l.insertattail(1);
    l.insertattail(3);
    l.display();
    cout << endl;
    cout << "After Sorting :" << endl;
    l.sorting();
    l.display();
    return 0;
}
