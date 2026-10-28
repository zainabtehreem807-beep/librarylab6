
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string url;
    Node* next;

    Node(string page)
    {
        url = page;
        next = nullptr;
    }
};

class BrowserHistory
{
private:
    Node* head;

public:
    BrowserHistory()
    {
        head = nullptr;
    }

    // Check if history is empty
    bool IsEmpty()
    {
        return head == nullptr;
    }

    // Check if history is not empty
    bool IsNotEmpty()
    {
        return head != nullptr;
    }

    // Insert a page at the head
    void Insert(string url)
    {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        cout << "Page added successfully.\n";
    }

    // Remove a page from the head
    void Remove()
    {
        if (IsEmpty())
        {
            cout << "Browser history is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        cout << "Removed page: " << temp->url << endl;
        delete temp;
    }

    // Insert a page at a specific index
    void InsertAt(int index, string url)
    {
        if (index < 0)
        {
            cout << "Invalid index.\n";
            return;
        }

        if (index == 0)
        {
            Insert(url);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid index.\n";
            return;
        }

        Node* newNode = new Node(url);
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Page inserted successfully.\n";
    }

    // Remove a page at a specific index
    void RemoveAt(int index)
    {
        if (index < 0 || IsEmpty())
        {
            cout << "Invalid index or empty history.\n";
            return;
        }

        if (index == 0)
        {
            Remove();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Invalid index.\n";
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;

        cout << "Removed page: " << deleteNode->url << endl;
        delete deleteNode;
    }

    // Swap two pages using their indexes
    void Swap(int index1, int index2)
    {
        if (index1 < 0 || index2 < 0)
        {
            cout << "Invalid index.\n";
            return;
        }

        Node* first = head;
        Node* second = head;

        for (int i = 0; i < index1 && first != nullptr; i++)
            first = first->next;

        for (int i = 0; i < index2 && second != nullptr; i++)
            second = second->next;

        if (first == nullptr || second == nullptr)
        {
            cout << "Invalid index.\n";
            return;
        }

        string temp = first->url;
        first->url = second->url;
        second->url = temp;

        cout << "Pages swapped successfully.\n";
    }

    // Sort pages alphabetically
    void Sort()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        for (Node* i = head; i->next != nullptr; i = i->next)
        {
            for (Node* j = head; j->next != nullptr; j = j->next)
            {
                if (j->url > j->next->url)
                {
                    string temp = j->url;
                    j->url = j->next->url;
                    j->next->url = temp;
                }
            }
        }

        cout << "History sorted alphabetically.\n";
    }

    // Reverse browser history
    void Reverse()
    {
        Node* previous = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        head = previous;
        cout << "Browser history reversed.\n";
    }

    // Print all visited pages
    void Print()
    {
        if (IsEmpty())
        {
            cout << "No pages in browser history.\n";
            return;
        }

        Node* temp = head;
        int index = 0;

        cout << "\nBrowser History:\n";

        while (temp != nullptr)
        {
            cout << index << ". " << temp->url << endl;
            temp = temp->next;
            index++;
        }
    }

    // Free memory
    ~BrowserHistory()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    BrowserHistory browser;
    int choice, index, index1, index2;
    string url;

    do
    {
        cout << "\n===== BROWSER BACK BUTTON SYSTEM =====\n";
        cout << "1. Visit a new page (Insert at Head)\n";
        cout << "2. Remove current page (Remove from Head)\n";
        cout << "3. Insert page at index\n";
        cout << "4. Remove page at index\n";
        cout << "5. Swap two pages\n";
        cout << "6. Sort history alphabetically\n";
        cout << "7. Reverse browser history\n";
        cout << "8. Print browser history\n";
        cout << "9. Check if history is empty\n";
        cout << "10. Check if history is not empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter page URL or name: ";
            cin >> ws;
            getline(cin, url);
            browser.Insert(url);
            break;

        case 2:
            browser.Remove();
            break;

        case 3:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter page URL or name: ";
            cin >> ws;
            getline(cin, url);
            browser.InsertAt(index, url);
            break;

        case 4:
            cout << "Enter index to remove: ";
            cin >> index;
            browser.RemoveAt(index);
            break;

        case 5:
            cout << "Enter first index: ";
            cin >> index1;
            cout << "Enter second index: ";
            cin >> index2;
            browser.Swap(index1, index2);
            break;

        case 6:
            browser.Sort();
            break;

        case 7:
            browser.Reverse();
            break;

        case 8:
            browser.Print();
            break;

        case 9:
            if (browser.IsEmpty())
                cout << "History is empty.\n";
            else
                cout << "History is not empty.\n";
            break;

        case 10:
            if (browser.IsNotEmpty())
                cout << "History contains pages.\n";
            else
                cout << "History is empty.\n";
            break;

        case 0:
            cout << "Exiting Browser History System.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
