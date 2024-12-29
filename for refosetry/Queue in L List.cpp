#include<iostream>
using namespace std;

struct node {
    string name;
    int ID;
    string address;
    int payment;
    int no_oreder;
    node* link;
};

class Book {
    node* head;

public:
    Book() { 
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(string n, string add, int id, int pay, int no) {
        node* newNode = new node; 
        newNode->name = n;
        newNode->ID = id;
        newNode->no_oreder = no;
        newNode->address = add;
        newNode->payment = pay;
        newNode->link = NULL;

        if (isEmpty()) {
            head = newNode;
        } else {
            node* temp = head;
            head = newNode;
            head->link = temp;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            node* temp = head;
            head = head->link;
            temp->link = NULL;
            delete temp;
        } else {
            cout << "\nEmpty Linked List!" << endl;
        }
    }

    void Display() {
        node* current = head;
        if (!isEmpty()) {
            while (current != NULL) {
                cout << "Name: " << current->name
                     << ", ID: " << current->ID
                     << ", Address: " << current->address
                     << ", Payment: " << current->payment
                     << ", No. of Orders: " << current->no_oreder << endl;
                current = current->link;
            }
        } else {
            cout << "Empty Linked List!" << endl;
        }
    }
};

int main() {
    Book B;
    int choice = 0;
    string cname, cadd;
    int cpay, cid, cno;

    while (choice != 4) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue Book \n";
        cout << "2. Dequeue Book :\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book name: ";
            cin >> cname;
            cout << "Enter Book address: ";
            cin >> cadd;
            cout << "Enter Book ID: ";
            cin >> cid;
            cout << "Enter Book payment: ";
            cin >> cpay;
            cout << "Enter no. of orders: ";
            cin >> cno;
            B.enqueue(cname, cadd, cid, cpay, cno);
            break;
        case 2:
            B.dequeue();
            cout << "Node dequeued from the stack." << endl;
            break;
        case 3:
            B.Display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
