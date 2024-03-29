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
    int getSize() {
        int length = 0;
        DLLNode<T>* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            length++;
        }
        return length;
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
    void saveFile(string);
    T deleteFromDLLHead();
    T& firstEl();
    T* find(const T&) const;
    T findnode(int index) const;

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
void DoublyLinkedList<T>::saveFile(string filename) {
   
    ofstream file;
    file.open(filename.c_str());
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
    DLLNode<T>* newNode=new DLLNode<T>;

    if (head == NULL)
    {
        cout<<("List is empty. You cannot do that action.\n")<<endl;
    }

   
    else
    {
        temp = head;
        i = 1;

        if (temp == NULL)
        {
        for (temp->next == NULL; (index-1) > 0; index--) {
            newNode->info == " ";
        }
          }

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
    DLLNode<T>* iter;
    T el;
 
    //Deletion
    if (head == NULL)
    {
        printf("List is empty. You cannot do that action.\n");
    }
    else
    {
        temp = head;
        iter = head;
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
            el=temp->info;
            free(temp);
        }
        //Insertion
        while (i < indexm-1 && iter != NULL)
        {
            iter = iter->next;
            i++;
        }
         if (iter != NULL)
        {
             DLLNode<T>* newptr = new DLLNode<T>();
             newptr->info = el;
             newptr->next = iter->next;
             newptr->prev = iter;

            if (iter->next != NULL)
            {

                iter->next->prev = newptr;
            }

            iter->next = newptr;
            
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
            free(temp); 
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
//*******************************************************************************//
template <class T>
T DoublyLinkedList<T>::findnode(int index) const
{
    DLLNode<T>* temp;

    temp = head;
  
    int count = 1;
    while (temp != NULL)
    {
        if (count == index)
            return(temp->info);
        count++;
        temp = temp->next;
    }
    }

//*******************************************************************************//


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