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
            cout << line << endl;
            dll.addToDLLTail(line);

        }
    }
    
    void savefilename(string filename) {
        dll.saveFile(filename);
        
    }

    void insert(int index, string text) {

        if (dll.isEmpty()) 
        {
            dll.addToDLLHead(text); 
        }
        if (index == 1) {
            dll.addToDLLHead(text); 
        }
        else {
            dll.addToBetween(index,text); 
        }
        cout<< dll << endl;
    }

    void del(int index) {
       if (dll.isEmpty())
        {
            cout<<"You cannot do that action. Please close the program.";
        }
        else {
            dll.deletetoSelectedNode(index); //Kullanýcýnýn girdiði index deðeri (row sayýsý) silinir.
            cout << dll << endl;
            
        }
    }
   void move(int indexn, int indexm) {
       dll.MoveNode(indexn, indexm);
       cout << dll << endl;

   }

    void replace(int index, string text) {
       dll.ReplaceNode(index, text);
       cout << dll << endl;
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
    int indexn;
    int indexm;
    do {
        cout << "********************************************************\n";
        cout << "Written By: Baturay Caglasin\n";
        cout << "********************************************************\n";
        cout << "Welcome to the project. Please type your command:\n";
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
        cout << " Press '0' button to exit" << endl;


        cin >> command;

        if (command == 1)
        {
            termproject.openfilename("Text.txt");
            cout << "The file successfully opened." << endl;
        }
        if (command == 2)
        {
            termproject.savefilename("Text.txt");
            cout << "The file successfully saved." << endl;
        }
        if (command == 3)
        {
            cout << "Where do you want to insert your text? Type a line number." << endl;
            cin >> index;
            cout << "What do you want to insert that row? Write your text." << endl;
            cin >> text;
            termproject.insert(index, text);
            cout << "The text successfully inserted." << endl;
        }
        if (command == 4)
      {
            cout << "Which do you want to delete your text? Type a line number." << endl;
            cin >> index;
            termproject.del(index);
            cout << "The line successfully deleted." << endl;
       }
        if (command == 5)
        {
            cout << "Enter your first line:" << endl;
            cin >>indexn ;
            cout << "Enter your second line:" << endl;
           cin >>indexm;
           termproject.move(indexn,indexm);
           cout << "The line moved from position n to position m successfully." << endl;
        }
       if (command == 6)
       {
           cout << "Enter a line number that you want to change the text of it." << endl;
           cin >>index;
           cout << "Enter your new text:" << endl;
           cin >>text;
           termproject.replace(index, text);
           cout << "You have successfully changed the line text." << endl;
        }
       if (command == 7)
       {
           termproject.next();
       }




       if (command == 0)
       {
           exit (0);
       }
    } while (true);
}