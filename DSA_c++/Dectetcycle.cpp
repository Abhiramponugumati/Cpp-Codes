#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int val;
    Node* next=nullptr;
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
     void display(){
        Node* temp=head;
        while(temp!=nullptr){
     cout<<temp->val<<"->";
     temp=temp->next;
        }
        cout<<"nullptr"<<endl;
     }
     bool dectetLoop(Node* head){
    if(head==nullptr) return false;
    map<Node*,bool>visited;
    Node* temp=head;
    while(temp!=NULL){
        // cycle is presnt
       if( visited[temp]==true) return true;
       visited[temp]=true;
       temp=temp->next;
    }
    return false;
 }
 Node* floydDetectLoop(Node* head){
    if(head==nullptr) return nullptr;
    Node* s=head;
    Node* f=head;
      while(f!=NULL && f->next!=NULL){
   s=s->next;
   f=f->next->next;
   if(s==f) return s;
      }
      return nullptr;
 }
 Node* getStartingNode(Node* head){
      if(head==nullptr) return nullptr;
      Node* intersection=floydDetectLoop(head);
      Node* slow=head;
      while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
      }
      return slow;
 }
 void removeloop(Node* head){
    if(head==NULL) return;
   Node* startofLoop=getStartingNode(head);
   Node* temp=head;
   while(temp->next!=startofLoop){
    temp=temp->next;
   }
   temp->next=NULL;
 }
};

int main(){
    LinkedList l;
     l.insertattail(1);
     l.insertattail(2);
      l.insertattail(2);
       l.insertattail(3);
        l.insertattail(3);
        l.insertattail(3);
        l.insertattail(4);
        l.display();
cout<<l.dectetLoop(l.head);
    return 0;
}