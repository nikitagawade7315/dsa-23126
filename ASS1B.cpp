#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int rollno;
    string email;
    float percentage;
    int phone;
    Node *next;
    Node() {
        next = NULL;
    }
};

class MSLL {
private:
    Node *head;

public:
    MSLL() {
        head = NULL;
    }

    // Create a New Node
    Node* getNode() {
        Node *newNode = new Node();

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, newNode->name);

        cout << "Enter Roll No: ";
        cin >> newNode->rollno;

        cout << "Enter Email: ";
        cin >> newNode->email;

        cout << "Enter Percentage: ";
        cin >> newNode->percentage;
        cout<<"Enter the phone number of student:";
        cin>>newNode->phone;

        newNode->next = NULL;

        return newNode;
    }

    // Create Linked List
    void createList() {
        int n;

       cout << "Enter Number of Students: ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cout << "\nEnter Details of Student " << i << endl;
        }

            Node *newNode = getNode();

            if (head == NULL) {
                head = newNode;
            } else {
                Node *temp = head;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = NULL;
            }
        
    }

    // Display List
    void display() {
        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nStudent Records\n";
        

        while (temp != NULL) {
            cout << "Name       : " << temp->name << endl;
            cout << "Roll No    : " << temp->rollno << endl;
            cout << "Email      : " << temp->email << endl;
            cout << "Percentage : " << temp->percentage << "%" << endl;
            cout<<"Phone number:"<<temp->phone<<endl;

            temp = temp->next;
        }
    }

    // Insert at Beginning
    void insertStart() {
        cout << "\nEnter Student Details\n";

        Node *newNode = getNode();

        newNode->next = head;
        head = newNode;
    }

    // Insert at End
    void insertEnd() {
        cout << "\nEnter Student Details\n";

        Node *newNode = getNode();

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Insert at Position
    void insertMiddle() {
        int pos;

        cout << "Enter Position: ";
        cin >> pos;

        cout << "\nEnter Student Details\n";

        Node *newNode = getNode();

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Invalid Position\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Search by Roll Number
    void search() {
        int roll;

        cout << "Enter Roll Number to Search: ";
        cin >> roll;

        Node *temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->rollno == roll) {
                cout << "\nStudent Found\n";
                cout << "Position   : " << pos << endl;
                cout << "Name       : " << temp->name << endl;
                cout << "Roll No    : " << temp->rollno << endl;
                cout << "Email      : " << temp->email << endl;
                cout << "Percentage : " << temp->percentage << "%" << endl;
                 cout<<"Phone number:"<<temp->phone<<endl;

                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Student Not Found.\n";
    }

    // Delete by Roll Number
    void deleteValue() {
        int roll;

        cout << "Enter Roll Number to Delete: ";
        cin >> roll;

        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }

        if (head->rollno == roll) {
            Node *temp = head;
            head = head->next;
            delete temp;

            cout << "Student Deleted Successfully.\n";
            return;
        }

        Node *temp = head;

        while (temp->next != NULL && temp->next->rollno != roll)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Student Not Found.\n";
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "Student Deleted Successfully.\n";
    }

    // Reverse Linked List
    void reverse() {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        cout << "Linked List Reversed Successfully.\n";
    }
};

int main() {
    MSLL obj;

    cout << "\nCreate Linked List\n";
    obj.createList();
    obj.display();

    cout << "\nInsert at Beginning\n";
    obj.insertStart();
    obj.display();

    cout << "\nInsert at End\n";
    obj.insertEnd();
    obj.display();

    cout << "\nInsert at Position\n";
    obj.insertMiddle();
    obj.display();

    cout << "\nSearch Student\n";
    obj.search();

    cout << "\nDelete Student\n";
    obj.deleteValue();
    obj.display();

    cout << "\nReverse Linked List\n";
    obj.reverse();
    obj.display();

    return 0;
}
