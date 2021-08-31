/*
name : s.naga.jaganath
roll_no: cs20b1070
merging the two sorted list in a sorted way 
*/
#include<iostream>

using namespace std;

class node
{
    private:
       int data;
       node *next;
    public:
        int getData()
         {
             return data;
         }
         node *getNEXT()
         {
             return next;
         }
         int Data = getData();
         node *Next = getNEXT();
};
class linkedlist
{
    public:
        node *head, *tail;
        linkedlist()
        {
            head = NULL;
            tail = NULL;
        }
        node *getHead()
        {
           return head;
        }

        ~linkedlist()
        {
            free(head);    
        }
//function to insert a newnode
   void insertNode(int num, int position)
        {
            int i = 1;
            
            cout << "enter the number(in a sorted way) and position u want to add : ";
            cin >> num >> position;
            
            node *newNode = new node;
            newNode->Data = num;

            if(position == 1)
            {
                newNode->Next = head;
                head = newNode;
            }
            else
            {
              if(head == NULL)
              {
                newNode->Next = NULL;
                head = newNode;
                i++;
              }
              else
              {
                 node *temp = head;
                 for(int i=1; i < position - 1 && temp != NULL; i++)
                 {
                    temp = temp->Next;
                 }
                 newNode->Next = temp->Next;
                 temp->Next = newNode;
              }
            }
            cout << "The element is successfully added to  linked list" << endl;
        }

        void display()
        {   
            node *temp = head;
            if(temp == NULL)
            {
                cout << "the linked list is empty!" << endl;
            }
            while(temp != NULL)
            {
                cout << temp->Data << "  ";
                temp = temp->Next;
            }
            cout << endl;
        }

         void deleteNode(int position)
        {
            cout << "enter the position that u want to delete: ";
            cin >> position;
          
            if(head == NULL)
            {
                cout << "LINKED LIST IS EMPTY!" << endl;
                return;
            }
            int i=1;
            node *temp1 = head;
            node *temp2;
            if(position == 1)
            {
                if(temp1->Next == NULL)
                {
                    head = NULL;
                    free(temp1);
                }
                else
                {
                    head = temp1->Next;
                    free(temp1);
                }
                
            }
            else
            {
                for(i = 1; i < position; i++)
                {
                    if(temp1 == NULL || temp1->Next == NULL)
                    {
                        cout << "the position of node not found " << endl;
                        return;
                    }
                    temp2 = temp1;
                    temp1 = temp1->Next;
                }
                temp2->Next = temp1->Next;
                free(temp1);
                cout << "The element is successfully deleted in linked list" << endl;
            }
           
        }
};

node* mergeSortList(node* temp1, node* temp2)
{
	node* final = NULL;
    if(temp1 == NULL && temp2 == NULL)
    {
        cout << "both linked list are empty! " << endl;
    }

	if (temp1 == NULL)
	{
        return(temp2);
    }
	else if (temp2 == NULL)
    {
		return(temp1);
    }

	if (temp1->Data <= temp2->Data)
	{
		final = temp1;
		final->Next = mergeSortList(temp1->Next, temp2);
	}
	else
	{
		final = temp2;
		final->Next = mergeSortList(temp1, temp2->Next);
	}

	return(final);
}


int main()
{
    linkedlist list1, list2, list3;
    int n1,insertPos;
    int delPos,choice;
    int flag;
    while(1)
    {
        cout << "\n1.Insert a newnode \n2.Delete a node \n3.Display the linkedlists \n4.Merge linkedlist \n5.Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Select the linkedlist" << endl;
                cout << "1.linedList 1 \n2.linkedList 2" << endl;
                cout << "Enter your choice(1,2): ";
                cin >> flag;
                if(flag == 1)
                {
                   list1.insertNode(n1,insertPos);
                   
                }
                else if(flag == 2)
                {
                    list2.insertNode(n1,insertPos);
                   
                }
                else
                {
                    cout << "INVALID NUMBER!" << endl;
                }
                break;
            case 2:
                cout << "select the linkedlist" << endl;
                cout << "1. linedList 1 \n2.linkedList 2" << endl;
                cout << "enter your choice(1,2): ";
                cin >> flag;
                if(flag == 1)
                {
                   list1.deleteNode(delPos);
                
                }
                else if(flag == 2)
                {
                    list2.deleteNode(delPos);
                }
                else
                {
                    cout << "INVALID NUMBER!" << endl;
                }
                break;
            case 3:
                cout << "select the linkedlist" << endl;
                cout << "1. linedList 1 \n2.linkedList 2" << endl;
                cout << "enter your choice(1,2): ";
                cin >> flag;
                if(flag == 1)
                {
                   cout << "the 1st linked list is: " << endl;
                   list1.display();
                }
                else if(flag == 2)
                {
                    cout << "the 2nd linked list is: " << endl;
                    list2.display();
                }
                else
                {
                    cout << "INVALID NUMBER!" << endl;
                }
                break;
            case 4:
                cout << "the final merged list is: " << endl;
                list3.head = mergeSortList(list1.getHead(),list2.getHead());
                list3.display();
                break;
            default:
                cout << "choose a valid choice!" << endl;
                exit(0);
        }
    }
    return 0;
}