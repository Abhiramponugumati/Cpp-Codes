#include<iostream>
using namespace std;
class Node{
 public:
       int val;
       Node* next;
       // ptr always store address of variable, datatype of that variable is Node
       Node(int data){
        val=data;
        next=nullptr;
       }
};
class LinkedList{
 public:
 Node* head;
     // ptr is representing to address of starting listnode
     LinkedList(){
        head=nullptr;
     }
    void insertathead(int x){
        Node*  new_node=new Node(x);
        // creating listnode having val==x , new_node reprents the ptr stores the address of the new listnode which we created
  if(head==nullptr){
       head=new_node;
       return;
  }
   new_node->next=head;
   head=new_node;
    }
     void insertattail(int x){
        Node* new_node=new Node(x);
          if(head==nullptr){
       head=new_node;
       return;
  }
  Node* temp=head;
  while(temp->next!=nullptr){
    temp=temp->next;
  }
  //temp is poinitng to last listnode
  temp->next=new_node;
  new_node->next=nullptr;
     }
     void insertatpos(int x,int pos){
        int a=0;
        Node* new_node=new Node(x);
        Node* temp=head;
        while(a!=pos-1){
            temp=temp->next;
            a++;
        }
        // temp is pointing to pos-1 listnode
        new_node->next=temp->next;
        temp->next=new_node;
     }
     void display(){
        Node* temp=head;
        while(temp!=nullptr){
     cout<<temp->val<<"->";
     temp=temp->next;
        }
        cout<<"nullptr"<<endl;
     }
};
int main(){
    LinkedList l;
    l.insertattail(3);
     l.insertattail(4);
      l.insertattail(5);
       l.insertattail(6);
        l.insertattail(7);
        l.display();
        return 0;
}