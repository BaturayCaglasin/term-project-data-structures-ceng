#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Header.h"
#include "stackcpp.cpp"

using namespace std;
class termproject
{

public:

    DoublyLinkedList <string> dll;
    DLLNode <string> DLLNode;
    mystack<string> mystack;
    int pagelimit = 10;
    int arraysize;
    string line;
    ifstream file;
    int countremainlines;
    int pagecount=1;
    int i = 1;
    int z;
    int linelength;
    int p = pagecount;


    void openfilename(string filename) {
       


        file.open(filename.c_str());

        if (file.is_open() == false)
        {
            cout << "Couldn't open the file" << endl;
            return;
        }
        else {
            while (getline(file, line))
            {
                dll.addToDLLTail(line);
            }
            linelength = dll.getSize();

            for (i = 1; i <= linelength; i++) {
                line = dll.findnode(i);
               
                if (i < pagelimit + 1) {
                    cout << line << endl;
                }   
            }

            countremainlines = (dll.getSize() - pagelimit);
            cout << "---" << "Page-"<<pagecount << "---" << endl;
        }
        pagecount++;
        z += 10;
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
            dll.addToBetween(index, text);
        }
        cout << dll << endl;
        
    }      

    void del(int index) {
        if (dll.isEmpty())
        {
            cout << "You cannot do that action. Please close the program.";
        }
        else {
            dll.deletetoSelectedNode(index);
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


        void openfilename(string filename);
        i = p * 10;
        for (i; i<= linelength;i++){
            line = dll.findnode(i);

            if(i<=(p*10)+10){
            cout << line << endl;
            }
        }

        cout << "---" << "Page-" << pagecount << "---" << endl;
        p++;
    }
    
       
    void prev() {
        void openfilename(string filename);
        pagecount--;
        z -= 11;
        cout << z << endl;
      

        for (z; z <= dll.getSize(); z++) {
            line = dll.findnode(z);
            cout << line << endl;
        }
        cout << "---" << "Page-" << pagecount << "---" << endl;
    }

    void undo() {



    }

};

template<class T>
class mymainstack
{
public:
    DoublyLinkedList <string> dll;
    DLLNode <string> DLLNode;
    mystack<string> mystack;

    string line;
    ifstream file;
    int length;

    mymainstack()
    {
        length = dll.getSize();

    }

    void push(T value) {

    }
    int top() {
        return dll.firstEl();
    }
    int pop()
    {
        length--;
        return dll.deleteFromDLLHead();
    }

    int getSize() {
        return length;
    }
    void print() {
        length.printAll();
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
           cout << "You have successfully changed to your page." << endl;
       }
       if (command == 8)
       {
           termproject.prev();
           cout << "You have successfully changed to your page." << endl;

       }
       if (command == 9)
       {
           termproject.undo();
           cout << "Undo operation was successfully." << endl;

       }
       if (command == 0)
       {
           exit (0);
       }
    } while (true);
}