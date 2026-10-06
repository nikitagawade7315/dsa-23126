#include<iostream>
using namespace std;
class Node{
    public:
    int data;
     Node* next;
};
class MSLL{
    public:
    Node* p;
    Node* head;
    MSLL(){
        head=NULL;
    }
    void create();
    void display();
    void inserts();
    void inserte();
    void insertb();
    void search();
    void deleten();
    void update();
    void reverse();
};
//Create list
void MSLL::create(){
    int n;
    Node*p,*q;
cout<<"Enter the number of nodes:";
cin>>n;
for(int i=0;i<n;i++){
    p=new Node;
    cout<<"Enter the element you want to insert in list:";
    cin>>p->data;
    p->next=NULL;
    if(head==NULL){
        head=p;
        q=p;
    }
    else{
        q->next=p;
        q=p;
    }
}
}
//Display list
void MSLL::display(){
    Node *p;
    p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//Insert st starting
void MSLL::inserts(){
    Node* p;
    p=new Node;
    cout<<"Enter the element to inert at start:";
    cin>>p->data;
    p->next=NULL;
    if(head==NULL){
        head=p;
      
    }
    else{
       p->next=head;
       head=p;
    }
}
//Insert at end
void MSLL::inserte(){
    Node* p;
    p=new Node;
    cout<<"Enter element to be inserted in last:";
    cin>>p->data;
    p->next=NULL;
    if(head==NULL){
        head=p;
      
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
     temp->next=p;
    
    }
}
//Insert in between
void MSLL::insertb(){
    Node* p;
    int key;
    p=new Node;
    cout<<"Enter position at which element want inserted:";
    cin>>key;
    cout<<"Enter element insert in between:";
    cin>>p->data;
    if(head==NULL){
        p=head;
    }
    else{
        Node*temp=head;
        while(temp!=NULL && temp->data!=key){
         temp=temp->next;
        }
        if(temp!=NULL){
            p->next=temp->next;
            temp->next=p;

        }
        
    }
}
//Search element
void MSLL::search(){
   
    int value;
    int pos=0;
    cout<<"Enter element to search:";
    cin>>value;
    if(head==NULL){
        cout<<"List is empty.";
    }
    cout<<endl;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            cout<<"Element found at position:";
            cout<<pos<<"\n";
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout<<"Element not found.\n";
    }
    //Delete element
    void MSLL::deleten(){
      int value;
      cout<<"Enter element to delete:";
      cin>>value;
      if(head==NULL){
        cout<<"List is empty.";
        return;
      }
      Node *temp=head;
      Node *prev=NULL;
      if(head->data==value){
        head=head->next;
        delete temp;
        cout<<"Element deleted.";
        return;
      }
      while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
      }
      if(temp==NULL){
        cout<<"Element not found.";
        cout<<"endl";
      }
      prev->next=temp->next;
      delete temp;
      cout<<"Element deleted successfully.\n";
    }
    //Update value
    void MSLL::update(){
        int oldvalue,newvalue;
        cout<<"Enter element to update:";
        cin>>oldvalue;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==oldvalue){
                cout<<"Enter new value:";
                cin>>newvalue;
                temp->data=newvalue;
                cout<<"Node updated successfully.\n"<<endl;
                return;
        }
        

        temp=temp->next;
    }
        cout<<"Element not found.\n";
        
    }
    //reverse list
    void MSLL::reverse(){
        if(head==NULL){
            cout<<"List is empty.";
            return;
        }
        Node *prev=NULL;
        Node *curr=head;
        Node *next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        cout<<"List reversed successfully.\n";
    }

int main(){
    MSLL s;
    s.create();
    s.display();
    s.inserts();
     s.display();
     s.inserte();
     s.display();
     s.insertb();
     s.display();
     s.search();
     s.display();
     s.deleten();
     s.display();
     s.update();
     s.display();
     s.reverse();
     s.display();
     
    return 0;
}