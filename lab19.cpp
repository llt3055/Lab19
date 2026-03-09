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
        vector<Movie> movies;
        Movie m1("Inception");
        movies.push_back(m1);
        Movie m2("The Matrix");
        movies.push_back(m2);
        Movie m3("Interstellar");
        movies.push_back(m3);
        Movie m4("The Dark Knight");
        movies.push_back(m4);
        string fileComment;
        for (int i = 0; i < movies.size(); i++) {
            if (getline(fin, fileComment)) {
                double randomRating = (rand() % 41 + 10) / 10.0;
                movies[i].addReview(randomRating, fileComment);
            }
        }
        fin.close();
  
        for (int i = 0; i < movies.size(); i++) {
            movies[i].print();
        }
    } else {
        cout << "File not found.\n";
    }
    

        return 0;
    }
