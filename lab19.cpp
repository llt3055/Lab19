// COMSC-210 | Lab  19| Tianyi Cao 
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int W15 = 15;

struct Node {
    float rating;
    string comment;
    Node* next;
};

class Movie{
    private:
        string title;
        Node* head;
    public:
        Movie(){
            title = "Unknown";
            head = nullptr;
        }

        Movie(string t) {
            title = t;
            head = nullptr;
        }
    
        void addNode(double r, string c) {
        Node* newNode = new Node;
        newNode->rating = r;
        newNode->comment = c;
        newNode->next = head;
     
    }

    ~Movie() {
        if (head) {
            Node* current = head;
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        head = nullptr;
    }
};

void print() const {
        cout << "Movie Title: " << title << endl;
        Node* current = head;
        if (!current) {
            cout << "  (No reviews yet)" << endl;
            return;
        }else{
            while (current) {
                cout << "  Rating: " << current->rating << " - Comment: " << current->comment << endl;
                current = current->next;
            }
        }
    }

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Node *head = nullptr;
    ifstream fin;
    fin.open("comments.txt");
    if (fin.good()) {
        string fileComment;

    }
    

  



    

        // Add the new node to the linked list based on the user's choice
        if (choice_mode == 1) {
            if (!head) {
                head = newVal;
            } else {
                newVal->next = head;
                head = newVal;
            }
        } else {
            if (!head) {
                head = newVal;
            } else {
                Node *current = head;
                while (current->next) { 
                    current = current->next;
                }
                current->next = newVal;
            }
        }
    }

    // Clean up memory
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
      head = nullptr;
        cout << "Enter another review? Y/N: ";
        cin >> again;

        return 0;
    }
