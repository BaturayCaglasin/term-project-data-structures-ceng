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
            cout << line <<endl;
            dll.addToDLLTail(line);

        }
    }
    void savefilename() {

        ofstream SaveFile("Text.txt", std::ios::out | std::ios::app);

    }

    void insert(int index, string text) {

        if (dll.isEmpty()) 
        {
            dll.addToDLLHead(text); //Corner case: eðer text dosyasý boþ ise ilk row'a bu text'i ekleyecek.
        }
        if (index == 1) {
            dll.addToDLLHead(text); //Corner case: eðer ki kullanýcý ilk row'u seçmiþse bu text head'e eklensin.
        }
        else {
            dll.addToBetween(index,text); //Eðer ki kullanýcý index row'unu seçerse bu index row'una bu text eklenir.
        }
    }

    void del(int index) {
        if (dll.isEmpty())
        {
            cout<<"You cannot do that action. Please close the program.";
        }
        else {
            
        }
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
    int index;
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
            cin >> index;
            cout << "What do you want to insert? Write your text." << endl;
            cin >> text; 
            termproject.insert(index, text);

        }
       
    }
    while (true);
}