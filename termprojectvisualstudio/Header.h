#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include <iostream>
#include <string>
#include <stack>
using namespace std;
template<class T>
class DLLNode

{
public:
    DLLNode()
    {
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode<T>* n = 0, DLLNode<T>* p = 0)
    {
        info = el;
        next = n;
        prev = p;
    }
    T info;
    DLLNode<T>* next, * prev;
};

template<class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head = tail = 0;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();
    ~DoublyLinkedList()
    {
        clear();
    }
    bool isEmpty() const
    {
        return head == 0;
    }
    void clear();
    void setToNull()
    {
        head = tail = 0;
    }
    
    void addToDLLHead(const T&);
    void addToBetween(int, const T&);
    void deletetoSelectedNode(int index);
    void ReplaceNode(int, const T&);
    void MoveNode(int indexn,int indexm);
    void saveFile();
    T deleteFromDLLHead();
    T& firstEl();
    T* find(const T&) const;
    T  get_size();
protected:
    DLLNode<T>* head, * tail;
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
    {
        for (DLLNode<T>* tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->info << ' ';
        return out;
    }
};

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el)
{
    if (head != 0)
    {
        head = new DLLNode<T>(el, head, 0);
        head->next->prev = head;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el)
{
    if (tail != 0)
    {
        tail = new DLLNode<T>(el, 0, tail);
        tail->prev->next = tail;
    }
    else head = tail = new DLLNode<T>(el);
}
//*******************************************************************************//
template<class T>
void DoublyLinkedList<T>::saveFile() {
   
    ofstream file;
    file.open("Text.txt", ios::out | ios::app | ios::binary);
    DLLNode<T>* temp;
    temp = head;
    if (!file) {
        cout << "Couldn't open the file";
    }
    else {
        while (temp != NULL)
        {
            file << temp->info +"\n";
                temp = temp->next;
        }
    }

}

//*******************************************************************************//
template<class T>
void DoublyLinkedList<T>::addToBetween(int index, const T& el)
{
    int i;
    DLLNode<T>* temp;

    if (head == NULL)
    {
        cout<<("List is empty. You cannot do that action.\n")<<endl;
    }
    else
    {
        temp = head;
        i = 1;

        while (i < index - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (index == 1)
        {
            addToDLLHead(el);
        }
        else if (temp == tail)
        {
            addToDLLTail(el);
        }
        
        else if (temp != NULL)
        {
            DLLNode<T>* newptr = new DLLNode<T>();
            newptr->info = el;
            newptr->next = temp->next;
            newptr->prev = temp;

            if (temp->next != NULL)
            {

                temp->next->prev = newptr;
            }

            temp->next = newptr;

            cout << ("Node inserted successfully.\n", index) << endl;
        }
        else
        {
            cout << ("Error, Invalid position.\n") << endl;
        }
    }
}
//*******************************************************************************//

template <typename T>
void DoublyLinkedList<T>::MoveNode(int indexn, int indexm) {

    int i;
    DLLNode<T>* temp;
    DLLNode<T>* deleted;

    deleted = NULL;

    if (head == NULL)
    {
        printf("List is empty. You cannot do that action.\n");
    }
    else
    {
        temp = head;
        i = 1;

        while (i < indexn && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp != NULL)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp = deleted;
            free(temp); // Delete the indexn's node
        }
        //n node'u silindi; temp=n'i tutuyordu. temp n i tutmaya devam edecek m e insert selected node yapacak which is m

        while (i < indexm - 1 && deleted != NULL)
        {
            deleted = deleted->next;
            i++;
        }
         if (deleted != NULL)
        {
             DLLNode<T>* newptr = new DLLNode<T>();
             //newptr->info = el;
             newptr->next = deleted->next;
             newptr->prev = deleted;

            if (deleted->next != NULL)
            {

                deleted->next->prev = newptr;
            }

            deleted->next = newptr;

            cout << ("The node moved from position n to position m successfully.\n") << endl;
        }
    }
}
//*******************************************************************************//
template<class T>
void DoublyLinkedList<T>::deletetoSelectedNode(int index)
{
    int i;
    DLLNode<T>* temp;
    if (head == NULL)
    {
        printf("List is empty. You cannot do that action.\n");
    }
    else
    {
        temp = head;
        i = 1;
      
        while (i < index && temp != NULL)
        {
            temp = temp->next;
            i++;
        } 

        if (index == 1)
        {
            deleteFromDLLHead();
        }
        else if (temp == tail)
        {
            deleteFromDLLTail();
        }
        else if (temp != NULL)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp); // Delete the n node
        }
        else
        {
            cout << ("Invalid Position") << endl;
        }
    }
}
//*******************************************************************************//


template <typename T>
void DoublyLinkedList<T>::ReplaceNode(int index, const T& el) {

    int i;
    DLLNode<T>* temp;

    if (head == NULL)
    {
        printf("List is empty. You cannot do that action.\n");
    }
    else
    {
        temp = head;
        i = 1;

        while (i < index && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        temp->info = el;
        return;
    }
}
//*******************************************************************************//
template<class T>
T DoublyLinkedList<T>::get_size() {
    int size = 0;
    for (DLLNode* tmp = head; tmp != 0; tmp = tmp->next)
        size++;

    return size;
}
template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead()
{
    T el = head->info;
    if (head == tail)   // if only one DLLNode on the list;
    {
        delete head;
        head = tail = 0;
    }
    else                // if more than one DLLNode in the list;
    {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
    T el = tail->info;
    if (head == tail)   // if only one DLLNode on the list;
    {
        delete head;
        head = tail = 0;
    }
    else                // if more than one DLLNode in the list;
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return el;
}

template <class T>
T* DoublyLinkedList<T>::find(const T& el) const
{
    DLLNode<T>* tmp = head;
    for (; tmp != 0 && !(tmp->info == el);  // overloaded ==
        tmp = tmp->next);
    if (tmp == 0)
        return 0;
    else return &tmp->info;
}

template<class T>
T& DoublyLinkedList<T>::firstEl()
{
    return head->info;
}

template<class T>
void DoublyLinkedList<T>::clear()
{
    for (DLLNode<T>* tmp; head != 0; )
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif