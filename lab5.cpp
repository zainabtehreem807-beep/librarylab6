
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Book
{
    int id;
    string name;
    Book* next;
};

class Library
{
private:
    Book* head;

public:
    Library()
    {
        head = NULL;
    }

    // 1. Display all books
    void displayBooks()
    {
        if (head == NULL)
        {
            cout << "Library is empty!" << endl;
            return;
        }

        Book* temp = head;

        while (temp != NULL)
        {
            cout << "Book ID: " << temp->id
                 << ", Book Name: " << temp->name << endl;

            temp = temp->next;
        }
    }

    // 2. Insert book at head
    void insertAtHead()
    {
        Book* newBook = new Book;

        cout << "Enter Book ID: ";
        cin >> newBook->id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Book Name: ";
        getline(cin, newBook->name);

        newBook->next = head;
        head = newBook;

        cout << "Book inserted at head!" << endl;
    }

    // 3. Remove book from head
    void removeFromHead()
    {
        if (head == NULL)
        {
            cout << "Library is empty!" << endl;
            return;
        }

        Book* temp = head;
        head = head->next;

        cout << "Removed Book: " << temp->name << endl;

        delete temp;
    }

    // 4. Insert book at index (0-based)
    void insertAtIndex()
    {
        int index;

        cout << "Enter index (starting from 0): ";
        cin >> index;

        if (index < 0)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0)
        {
            insertAtHead();
            return;
        }

        Book* temp = head;

        for (int i = 0; i < index - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        Book* newBook = new Book;

        cout << "Enter Book ID: ";
        cin >> newBook->id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Book Name: ";
        getline(cin, newBook->name);

        newBook->next = temp->next;
        temp->next = newBook;

        cout << "Book inserted successfully!" << endl;
    }

    // 5. Remove book at index (0-based)
    void removeAtIndex()
    {
        int index;

        cout << "Enter index (starting from 0): ";
        cin >> index;

        if (index < 0 || head == NULL)
        {
            cout << "Invalid index or empty library!" << endl;
            return;
        }

        if (index == 0)
        {
            removeFromHead();
            return;
        }

        Book* temp = head;

        for (int i = 0; i < index - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        Book* deletedBook = temp->next;
        temp->next = deletedBook->next;

        cout << "Removed Book: " << deletedBook->name << endl;

        delete deletedBook;
    }

    // 6. Swap two books using their IDs
    void swapBooks()
    {
        int id1, id2;

        cout << "Enter first Book ID: ";
        cin >> id1;

        cout << "Enter second Book ID: ";
        cin >> id2;

        Book* first = NULL;
        Book* second = NULL;
        Book* temp = head;

        while (temp != NULL)
        {
            if (temp->id == id1)
                first = temp;

            if (temp->id == id2)
                second = temp;

            temp = temp->next;
        }

        if (first == NULL || second == NULL)
        {
            cout << "Book ID not found!" << endl;
            return;
        }

        int tempID = first->id;
        first->id = second->id;
        second->id = tempID;

        string tempName = first->name;
        first->name = second->name;
        second->name = tempName;

        cout << "Books swapped successfully!" << endl;
    }

    // 7. Sort books by ID (ascending order)
    void sortBooks()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Not enough books to sort!" << endl;
            return;
        }

        bool swapped;

        do
        {
            swapped = false;
            Book* temp = head;

            while (temp->next != NULL)
            {
                if (temp->id > temp->next->id)
                {
                    int tempID = temp->id;
                    temp->id = temp->next->id;
                    temp->next->id = tempID;

                    string tempName = temp->name;
                    temp->name = temp->next->name;
                    temp->next->name = tempName;

                    swapped = true;
                }

                temp = temp->next;
            }

        } while (swapped);

        cout << "Books sorted by ID!" << endl;
    }

    // 8. Reverse book collection
    void reverseBooks()
    {
        Book* previous = NULL;
        Book* current = head;
        Book* nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        head = previous;

        cout << "Book collection reversed!" << endl;
    }

    // 9. Check collection status
    void collectionStatus()
    {
        int count = 0;
        Book* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        if (count == 0)
            cout << "Collection is EMPTY." << endl;
        else
            cout << "Collection is NOT EMPTY." << endl;

        cout << "Total Books: " << count << endl;
    }

    // Free allocated memory
    ~Library()
    {
        Book* temp;

        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "\n========================================" << endl;
        cout << "    LIBRARY BOOK COLLECTION SYSTEM" << endl;
        cout << "========================================" << endl;
        cout << "1. Display All Books" << endl;
        cout << "2. Insert Book at Head" << endl;
        cout << "3. Remove Book from Head" << endl;
        cout << "4. Insert Book at Index" << endl;
        cout << "5. Remove Book at Index" << endl;
        cout << "6. Swap Books" << endl;
        cout << "7. Sort Books by ID" << endl;
        cout << "8. Reverse Book Collection" << endl;
        cout << "9. Check Collection Status" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Please enter a valid number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                lib.displayBooks();
                break;

            case 2:
                lib.insertAtHead();
                break;

            case 3:
                lib.removeFromHead();
                break;

            case 4:
                lib.insertAtIndex();
                break;

            case 5:
                lib.removeAtIndex();
                break;

            case 6:
                lib.swapBooks();
                break;

            case 7:
                lib.sortBooks();
                break;

            case 8:
                lib.reverseBooks();
                break;

            case 9:
                lib.collectionStatus();
                break;

            case 10:
                cout << "Program ended!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 10);

    return 0;
}
