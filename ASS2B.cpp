#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    string song;
    string singer;
    float playtime;
    Node *prev;
    Node *next;
};

class Playlist
{
    Node *head;
    Node *tail;
    Node *current;

public:
    Playlist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    Node* getNode();
    void addSong();
    void deleteSong();
    void searchSong();
    void display();
    void nextSong();
    void previousSong();
};

Node* Playlist::getNode()
{
    Node *p = new Node;

    cout << "Enter Song Name: ";
    cin.ignore();
    getline(cin, p->song);
    cout<<"Enter singer name: ";
    cin.ignore();
    getline(cin, p->singer);
    cout<<"Enter playtime of the song:";
    cin>>p->playtime;

    p->prev = NULL;
    p->next = NULL;

    return p;
}

// Add Song
void Playlist::addSong()
{
    Node *p = getNode();

    if(head == NULL)
    {
        head=new Node;
    }
    else
    {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }

    cout << "Song Added Successfully.\n";
}

// Display Playlist
void Playlist::display()
{
    if(head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    Node *temp = head;

    cout << "\nPlaylist:\n";

    while(temp != NULL)
    {
        cout << temp->song << endl;
        temp = temp->next;
    }
}

// Search Song
void Playlist::searchSong()
{
    if(head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    string key;

    cout << "Enter Song Name to Search: ";
    cin.ignore();
    getline(cin, key);

    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->song == key)
        {
            cout << "Song Found.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Song Not Found.\n";
}

// Delete Song
void Playlist::deleteSong()
{
    if(head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    string key;

    cout << "Enter Song Name to Delete: ";
    cin.ignore();
    getline(cin, key);

    Node *temp = head;

    while( temp != NULL && temp->song != key)
        temp = temp->next;

    if(temp == NULL)
    {
        cout << "Song Not Found.\n";
        return;
    }

    if(temp == head)
    {
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
    }
    else if(temp == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    if(current == temp)
        current = head;

    delete temp;

    cout << "Song Deleted Successfully.\n";
}

// Play Next Song
void Playlist::nextSong()
{
    if(current == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    if(current->next != NULL)
    {
        current = current->next;
        cout << "Now Playing: " << current->song << endl;
    }
    else
    {
        cout << "Already at Last Song.\n";
    }
}

// Play Previous Song
void Playlist::previousSong()
{
    if(current == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    if(current->prev != NULL)
    {
        current = current->prev;
        cout << "Now Playing: " << current->song << endl;
    }
    else
    {
        cout << "Already at First Song.\n";
    }
}

int main()
{
    Playlist p;
    int ch;

    do
    {
        cout << "\n MUSIC PLAYLIST MANAGER \n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Search Song\n";
        cout << "4.Delete Song \n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                p.addSong();
                break;

            case 2:
                p.display();
                break;

            case 3:
                p.searchSong();
                break;

            case 4:
                p.deleteSong();
                break;

            case 5:
                p.nextSong();
                break;

            case 6:
                p.previousSong();
                break;

            case 7:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    }while(ch != 7);

    return 0;
}