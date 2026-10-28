
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string title;
    Node* next;

    Node(int bookID, string bookTitle)
    {
        id = bookID;
        title = bookTitle;
        next = nullptr;
    }
};

class CircularLibrary
{
private:
    Node* head;

public:
    CircularLibrary()
    {
        head = nullptr;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    void DisplayAllBooks()
    {
        if (IsEmpty())
        {
            cout << "No books in the collection.\n";
            return;
        }

        Node* temp = head;
        cout << "\nCircular Library Book Collection:\n";

        do
        {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void InsertAtHead(int id, string title)
    {
        Node* newNode = new Node(id, title);

        if (IsEmpty())
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }

        cout << "Book inserted at head successfully.\n";
    }

    void RemoveFromHead()
    {
        if (IsEmpty())
        {
            cout << "Collection is empty.\n";
            return;
        }

        Node* temp = head;

        if (head->next == head)
        {
            head = nullptr;
        }
        else
        {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
        }

        cout << "Removed book: " << temp->title << endl;
        delete temp;
    }

    void InsertAt(int index, int id, string title)
    {
        if (index < 0)
        {
            cout << "Invalid index.\n";
            return;
        }

        if (index == 0)
        {
            InsertAtHead(id, title);
            return;
        }

        if (IsEmpty())
        {
            cout << "Invalid index. Collection is empty.\n";
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid index.\n";
                return;
            }
        }

        Node* newNode = new Node(id, title);
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Book inserted successfully.\n";
    }

    void RemoveAt(int index)
    {
        if (index < 0 || IsEmpty())
        {
            cout << "Invalid index or empty collection.\n";
            return;
        }

        if (index == 0)
        {
            RemoveFromHead();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid index.\n";
                return;
            }
        }

        Node* target = temp->next;

        if (target == head)
        {
            cout << "Invalid index.\n";
            return;
        }

        temp->next = target->next;

        cout << "Removed book: " << target->title << endl;
        delete target;
    }

    void SwapBooks(int id1, int id2)
    {
        if (IsEmpty())
        {
            cout << "Collection is empty.\n";
            return;
        }

        Node* first = nullptr;
        Node* second = nullptr;
        Node* temp = head;

        do
        {
            if (temp->id == id1)
                first = temp;

            if (temp->id == id2)
                second = temp;

            temp = temp->next;
        } while (temp != head);

        if (first == nullptr || second == nullptr)
        {
            cout << "Book ID not found.\n";
            return;
        }

        int tempID = first->id;
        first->id = second->id;
        second->id = tempID;

        string tempTitle = first->title;
        first->title = second->title;
        second->title = tempTitle;

        cout << "Books swapped successfully.\n";
    }

    void SortByID()
    {
        if (IsEmpty() || head->next == head)
        {
            cout << "Not enough books to sort.\n";
            return;
        }

        Node* current = head;

        do
        {
            Node* nextNode = current->next;

            while (nextNode != head)
            {
                if (current->id > nextNode->id)
                {
                    int tempID = current->id;
                    current->id = nextNode->id;
                    nextNode->id = tempID;

                    string tempTitle = current->title;
                    current->title = nextNode->title;
                    nextNode->title = tempTitle;
                }

                nextNode = nextNode->next;
            }

            current = current->next;
        } while (current != head);

        cout << "Books sorted by ID successfully.\n";
    }

    void Reverse()
    {
        if (IsEmpty() || head->next == head)
        {
            cout << "Not enough books to reverse.\n";
            return;
        }

        Node* previous = head;
        Node* current = head->next;
        Node* nextNode = nullptr;

        while (current != head)
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        head->next = previous;
        head = previous;

        cout << "Book collection reversed successfully.\n";
    }

    void MoveToNextBook()
    {
        if (IsEmpty())
        {
            cout << "Collection is empty.\n";
            return;
        }

        head = head->next;

        cout << "Current featured book: "
             << head->title << " (ID: " << head->id << ")\n";
    }

    void CollectionStatus()
    {
        if (IsEmpty())
        {
            cout << "Collection is empty.\n";
            return;
        }

        int count = 0;
        Node* temp = head;

        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        cout << "Collection is not empty.\n";
        cout << "Total books: " << count << endl;
        cout << "Featured book: " << head->title
             << " (ID: " << head->id << ")\n";
    }

    ~CircularLibrary()
    {
        if (IsEmpty())
            return;

        Node* current = head->next;

        while (current != head)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
        head = nullptr;
    }
};

int main()
{
    CircularLibrary library;
    int choice, id, index, id1, id2;
    string title;

    do
    {
        cout << "\n========================================\n";
        cout << "CIRCULAR LIBRARY BOOK DISPLAY SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Move to Next Book\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.DisplayAllBooks();
            break;

        case 2:
            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter book title: ";
            cin >> ws;
            getline(cin, title);
            library.InsertAtHead(id, title);
            break;

        case 3:
            library.RemoveFromHead();
            break;

        case 4:
            cout << "Enter index (starting from 0): ";
            cin >> index;
            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter book title: ";
            cin >> ws;
            getline(cin, title);
            library.InsertAt(index, id, title);
            break;

        case 5:
            cout << "Enter index to remove: ";
            cin >> index;
            library.RemoveAt(index);
            break;

        case 6:
            cout << "Enter first book ID: ";
            cin >> id1;
            cout << "Enter second book ID: ";
            cin >> id2;
            library.SwapBooks(id1, id2);
            break;

        case 7:
            library.SortByID();
            break;

        case 8:
            library.Reverse();
            break;

        case 9:
            library.MoveToNextBook();
            break;

        case 10:
            library.CollectionStatus();
            break;

        case 11:
            cout << "Exiting Library System.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 11);

    return 0;
}
