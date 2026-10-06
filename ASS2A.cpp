#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class DLL
{
    Node *head;

public:
    DLL()
    {
        head = NULL;
    }

    Node* getNode();
    void create();
    void display();
    void insertBegin();
    void insertEnd();
    void insertAfter();
    void search();
    void update();
    void deleteNode();
    void reverse();
};

// Create New Node
Node* DLL::getNode()
{
    Node *p = new Node;

    cout << "Enter Data: ";
    cin >> p->data;

    p->prev = NULL;
    p->next = NULL;

    return p;
}

// Create List
void DLL::create()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node *p, *q;

    for(int i=0;i<n;i++)
    {
        p = getNode();

        if(head==NULL)
        {
            head=p;
            q=p;
        }
        else
        {
            q->next=p;
            p->prev=q;
            q=p;
        }
    }
}

// Display
void DLL::display()
{
    if(head==NULL)
    {
        cout<<"List is Empty.\n";
        return;
    }

    Node *temp=head;

    cout<<"DLL : ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

// Insert at Beginning
void DLL::insertBegin()
{
    Node *p=getNode();

    if(head==NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        head=p;
    }

    cout<<"Node Inserted at Beginning.\n";
}

// Insert at End
void DLL::insertEnd()
{
    Node *p=getNode();

    if(head==NULL)
    {
        head=p;
        return;
    }

    Node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=p;
    p->prev=temp;

    cout<<"Node Inserted at End.\n";
}

// Insert After Specific Node
void DLL::insertAfter()
{
    int key;
    cout<<"Enter value after which to insert: ";
    cin>>key;

    Node *temp=head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        cout<<"Node not found.\n";
        return;
    }

    Node *p=getNode();

    p->next=temp->next;
    p->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=p;

    temp->next=p;

    cout<<"Node Inserted Successfully.\n";
}

// Search
void DLL::search()
{
    int key;

    cout<<"Enter value to search: ";
    cin>>key;

    Node *temp=head;

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            cout<<"Node Found.\n";
            return;
        }

        temp=temp->next;
    }

    cout<<"Node Not Found.\n";
}

// Update
void DLL::update()
{
    int key;

    cout<<"Enter value to update: ";
    cin>>key;

    Node *temp=head;

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            cout<<"Enter new value: ";
            cin>>temp->data;

            cout<<"Node Updated Successfully.\n";
            return;
        }

        temp=temp->next;
    }

    cout<<"Node Not Found.\n";
}

// Delete
void DLL::deleteNode()
{
    int key;

    cout<<"Enter value to delete: ";
    cin>>key;

    Node *temp=head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        cout<<"Node Not Found.\n";
        return;
    }

    if(temp==head)
    {
        head=temp->next;

        if(head!=NULL)
            head->prev=NULL;
    }
    else
    {
        temp->prev->next=temp->next;

        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
    }

    delete temp;

    cout<<"Node Deleted Successfully.\n";
}

// Reverse DLL
void DLL::reverse()
{
    Node *current=head;
    Node *temp=NULL;

    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }

    if(temp!=NULL)
        head=temp->prev;

    cout<<"List Reversed Successfully.\n";
}

int main()
{
    DLL d;

    d.create();

    cout<<"\nOriginal List:\n";
    d.display();

    d.insertBegin();
    d.display();

    d.insertEnd();
    d.display();

    d.insertAfter();
    d.display();

    d.search();

    d.update();
    d.display();

    d.deleteNode();
    d.display();

    d.reverse();
    d.display();

    return 0;
}
