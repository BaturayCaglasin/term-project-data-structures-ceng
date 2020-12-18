#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Header.h"

using namespace std;
class termproject
{

public:

    DoublyLinkedList <string> dll;
    DLLNode <string> DLLNode;
    int arraysize;


    void openfilename(string filename) {

        string line;
        ifstream file;
        file.open(filename.c_str());

        if (file.is_open() == false)
        {
            cout << "Couldn't open the file" << endl;
            return;
        }
  
        while (getline(file, line)) {
            cout << line;
            dll.addToDLLTail(line);

        }
    }
    void savefilename() {

        ofstream SaveFile("Text.txt", std::ios::out | std::ios::app);

    }

    void insert(int n, string text) {

        if(dll.isEmpty())
        {
            dll.addToDLLHead(text);
        }
        else {
            //DLLNode newnode = new DLLNode();
            //newnode.info = text;
            //newnode.n = n;

        }
    }

    void del() {

    }
    void move() {
    }

    void replace() {
    }

    void next() {

    }
    void prev() {
    }

    void undo() {

    }




};


int main(void)
{

    termproject termproject;
    string text;
    int command;
    int n;
    do {
        cout << "********************************************************\n";
        cout << "Written By: Baturay Caglasin\n";
        cout << "********************************************************\n";
        cout << "Welcome to the project. Please type your command: :\n";
        cout << "********************************************************\n";
        cout << " 1-Open your file \n";
        cout << " 2.Save your file \n";
        cout << " 3.Insert a text to your given line \n";
        cout << " 4.Delete a text from your given line  \n";
        cout << " 5-Move your line position \n";
        cout << " 6-Replace a line \n";
        cout << " 7-Next Operation \n";
        cout << " 8-Prev Operation \n";
        cout << " 9-Undo Operation" << endl;
        

        cin >> command;

        if (command == 1)
        {
            termproject.openfilename("Text.txt");
        }
        if (command == 2)
        {
            termproject.savefilename();
        }
        if (command == 3)
        {
            cout << "Where do you want to insert your text? Type a number." << endl;
            cin >> n;
            cout << "What do you want to insert? Write your text." << endl;
            cin >> text; //tek bir kelime nasýl alýnýyor bak
            termproject.insert(n, text);
        }


    } while (true);
}