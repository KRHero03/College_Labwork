#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string label, symbol, address;
    struct Node *next;
    Node(string label, string symbol, string address)
    {
        this->label = label;
        this->symbol = symbol;
        this->address = address;
        this->next = NULL;
    }
};
class SymbolTable
{
    Node *head, *tail;

public:
    // Constructor work as Create Function that creats an empty Symbol table
    SymbolTable()
    {
        head = NULL;
        tail = NULL;
    }
    //Insert function to add Row in the Table
    void Insert(string label, string symbol, string address)
    {
        Node *new_entry = new Node(label, symbol, address);
        if (head == NULL)
        {
            head = new_entry;
            tail = new_entry;
            return;
        }
        tail->next = new_entry;
        tail = tail->next;
    }
    //modify function to modify Row symbol based on label in the Table
    bool Modify(string label, string symbol, string address)
    {
        Node *cur = head;
        while (cur)
        {
            if (cur->label == label)
            {
                cur->symbol = symbol;
                cur->address = address;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    //Search function to search Row based on label in the Table
    int Search(string label)
    {
        Node *cur = head;
        int cnt = 1;
        while (cur)
        {
            if (cur->label == label)
                return cnt;
            cur = cur->next;
            cnt++;
        }
        return -1;
    }
    void Display()
    {
        Node *cur = head;
        int cnt = 1;
        while (cur)
        {
            cout << cnt << " | " << cur->label << " | " << cur->symbol << " | " << cur->address << "\n";
            cur = cur->next;
            cnt++;
        }
    }
};
int main()
{
    int op;
    SymbolTable table;
    do
    {
        do
        {
            cout << "1.Insert\n";
            cout << "2.Modify\n";
            cout << "3.Search\n";
            cout << "4.Display\n";
            cout << "5.Exit\n";
            cin >> op;
        } while (op < 1 || op > 5);
        switch (op)
        {
        case 1:
        {
            cout << "\n\n";
            string label, address, symbol;
            cout << "Enter Label :";
            cin >> label;
            cout << "\nEnter Symbol :";
            cin >> symbol;
            cout << "\nEnter Address :";
            cin >> address;
            table.Insert(label, symbol, address);
            cout << "\n\n";
            break;
        }
        case 2:
        {
            cout << "\n\n";
            string label, address, symbol;
            cout << "Enter Label to Modify : ";
            cin >> label;
            cout << "\nEnter New Symbol : ";
            cin >> symbol;
            cout << "\nEnter New Address : ";
            cin >> address;
            if (table.Modify(label, symbol, address))
                cout << "\nModification Success";
            else
                cout << "\nModification Failed";
            cout << "\n\n";
            break;
        }
        case 3:
        {
            cout << "\n\n";
            string label;
            cout << "Enter Label to Search : ";
            cin >> label;
            int res = table.Search(label);
            if (res > 0)
                cout << "\nEntry Found at Row Number " << res;
            else
                cout << "\nNo Result Found";
            cout << "\n\n";
            break;
        }
        case 4:
        {
            cout << "\n\n";
            table.Display();
            cout << "\n\n";
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    } while (true);
    return 0;
}