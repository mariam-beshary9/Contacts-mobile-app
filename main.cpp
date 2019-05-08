/**
This program is created by Mariam Ahmad Amin

**/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
struct Data
{
    string nameOfContact ;
    string numberOfcontact;
};
struct Node
{
    string number ;
    Node *nxt  ;
};
class LinkedList
{
public :
    Node * head ;
    Node * tail ;

public :
    LinkedList ()
    {
        head = NULL ;
        tail = NULL ;
    }
    ~LinkedList ()
    {
        Node* current = head ;
        Node* deleted ;
        while (current)
        {
            deleted = current ;
            current = current->nxt ;
            delete deleted ;
        }
   //     cout<<"\n\nCalled the destructor of the number linked list \n";
    }
    void  AddNum (string num )
    {
        Node *newNode = new Node;
        newNode->number = num  ;
        newNode->nxt = NULL ;

        Node *current = head ;

        if (head==NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            if ((head->number) > num )
            {
                newNode->nxt = head;
                head = newNode ;
                return ;
            }
            while (current->nxt!=NULL)
            {
                if (((current->nxt)->number  )> num)
                {
                    newNode->nxt = current->nxt ;
                    current->nxt = newNode ;
                    break ;
                }
                else
                {
                    current = current->nxt ;

                }

            }
            current->nxt= newNode ;
            tail = newNode ;
        }
    }
    void printNumberList ()
    {
        Node* current = head ;
        while (current)
        {
            cout<< "  " <<current->number ;
            current = current->nxt ;
        }
    }


};
struct ContactNode
{
    string name ;
    ContactNode *next ;
    LinkedList numList ;
};

class ContactLinkedList
{
private :
    ContactNode *Head ;
    ContactNode *Tail ;
public:
    ContactLinkedList ()
    {
        Head = NULL ;
        Tail = NULL ;
    }
     ~ContactLinkedList ()
    {
        ContactNode* current = Head ;
        ContactNode* deleted ;
        while (current)
        {
            deleted = current ;
            current = current->next ;
            delete deleted ;
        }
        //     cout<<"\n\nCalled the destructor of the contact linked list \n";
    }
    int searchContactList (string contactName)
    {
        int rrn = -1, couter = -1;
        ContactNode *current = Head ;
        while (current)
        {
            couter++;
            if (current->name==contactName )
            {
                rrn=couter ;
                return rrn ;
            }
            current=current->next;

        }
        return rrn ;



    }
    void AddContact (string contactName,string num )
    {
        if (searchContactList (contactName)==-1)
        {
            ContactNode *newContactNode = new ContactNode;
            newContactNode->name = contactName ;
            newContactNode->next = NULL ;
           (newContactNode->numList).AddNum(num);

            ContactNode *current = Head ;

            if (Head==NULL)
            {
                Head = newContactNode;
                Tail = newContactNode;
            }
            else
            {
                if (Head->name  > contactName )
                {
                    newContactNode->next = Head;
                    Head = newContactNode ;
                    return ;
                }
                while (current->next!=NULL)
                {
                    if (((current->next)->name) >contactName)
                    {
                        newContactNode->next = current->next ;
                        current->next = newContactNode ;
                        break ;
                    }
                    else
                    {
                        current = current->next ;

                    }

                }
                current->next= newContactNode ;
                Tail = newContactNode ;
            }
        }
        else
        {
            ContactNode *current = Head ;
            for (int i=0 ; i<searchContactList(contactName) ; i++)
            {
                current = current->next ;
            }

            (current->numList).AddNum(num);

        }

    }
    void printContactList ()
    {

        ContactNode* current = Head ;
        int i = 0 ;
        while (current)
        {
            cout<< "Contact "<<++i<<" is : " <<current->name ;
            (current->numList).printNumberList();
            current = current->next ;
            cout<<endl;
        }
    }
};


vector <Data> loadDataFromFile ( )
{
     vector<Data> v;
     Data data ;
    fstream file ("Contacts.txt",ios::in);
    file.seekg(0,ios::beg);

    while(!file.eof()&&!file.fail())
    {


        file>>data.numberOfcontact;
        getline (file,data.nameOfContact);
        v.push_back(data);

    }
    return v;

}

int main()
{
  ContactLinkedList List  ;
  vector <Data> myData = loadDataFromFile();
  for (int i = 0 ; i<myData.size() ; i++)
  {
      List.AddContact(myData[i].nameOfContact,myData[i].numberOfcontact);
  }

  List.printContactList();

    return 0;
}
