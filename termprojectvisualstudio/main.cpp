#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Header.h"

using namespace std;
class termproject
{

private:
    bool error;
    DoublyLinkedList <string>** listoflist;
    int arraysize;
    int* CheckList;
    void TurnDefault(void)
    {
        for (int i = 0; i < arraysize + 1; i++)
        {
            CheckList[i] = -1;
        }
    }
public:
    void openfilename();
    void savefilename();
    void insert();
    void del();
    void move();
    void replace();
    void next();
    void prev();
    void undo();



public:
    termproject(string filename)
    {

        ifstream file;
        file.open(filename.c_str());
        file >> arraysize;
        if (file.is_open() == false)
        {
            cout << "Couldn't open the file" << endl;
            error = true;
            return;
        }
        error = false;
        CheckList = new int[arraysize + 1];
        TurnDefault();
        listoflist = new DoublyLinkedList <string> *[arraysize];
        for (int i = 0; i < arraysize; i++)
        {
            listoflist[i] = new DoublyLinkedList <string>;
        }

        //int from,to;
        //int i = 0;
        //while(file.eof() == false)
        //{
            //file>>from;
            //file>>to;


            //listoflist[from-1]->addToDLLTail(to);
        //}
    }
};
int main(void)
{

    string filename;
    int element;
    cout << "Enter filename " << endl;
    getline(cin, filename);
    termproject file(filename);


}


