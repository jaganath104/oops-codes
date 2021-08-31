/*cs20b1070
s.naga.jaganath 
menu driven programming for queue
*/
#include "queue"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    queue q1;//object creation using class
    int choice,num4,num,num1,num3,peek;//for to check boundary conditions
    cout << "----------------WELCOME TO OUR SECURE JOBS ALLINES--------------------------------------";
    while(1)
    {
        cout << " \n READ THE MENU CAREFULLY \n";
        cout << "\n 1)enter the integer job id  \n 2)the current job \n 3)excute a job \n 4)display jobs \n 5)Exit \n";
        cout << " enter your choice from above: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                num1 = q1.isFull();
                if(num1 == -1)//if the queue is filled
                {
                  break;
                }
                else
                {
                  cout << "\n enter the integer job ID: ";
                  cin >> num;
                  q1.enqueue(num);
                  cout << " \n the integer job id is successfully added " << endl;
                  
                  break;
                }
            case 2:
                  peek = q1.peek();
                  if(peek == -1)//if queue is empty
                  {
                      break;
                  }
                  else
                  {
                    cout << "\n the current job that will excute next is: " << peek;
                  }
                  cout << "\n";
                  break;
            case 3:
                 num3 = q1.dequeue();
                 if(num3 == -1)//if queue is empty
                 {
                   break;
                 }
                 else
                 {
                  cout << " \n The job INSERT job ID has been completed \n ";
                  cout << "\n";
                 }
                 break;
            case 4:
                num4 = q1.peek();//if queue is empty
                if(num4 == -1)
                {
                    break;
                }
                else
                {
                  cout << " \n all the jobs in queue pool are:- \n";
                  q1.display();
                  cout << "\n";
                }
                break;
            case 5:
                cout << " ------------------------------------------THANK YOU--------------------------------------- ";
                exit(0);
            default:
                cout << " enter a valid input \n ";                
        }

    }
    return 0;
}