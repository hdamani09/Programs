#include<iostream>      //By H.D
#include<stdlib.h>
using namespace std;

struct node{          //Create a node consiting of integer datatype and a pointer to the next node of same struct type
  int data;
  node *next;
};
class list{
  private:
    node *head;         //Create a list class to make a head node and initialize it via constructor to NULL
  public:               //Include all the functions you want to perform on the singly linked list and use the scope resolution operator
    list(){             //to define them
      head=NULL;
    }
    void insertFront(int data);
    void insertEnd(int data);
    void removeFront();
    void removeEnd();
    void display();
    void findNode(int data);
    void findRemove(int data);            //Take example of a list li1= 10->20->30
};

void list::insertFront(int data){         //Insert '40' to the front of li1 like 40->10->20->30
  node *temp= new node;
    temp->data=data;                      //Obtain the value in a temp node and point it to the previous head, then initialize it as
    temp->next=head;                      //the new head
    head=temp;
}

void list::insertEnd(int data){
  node *temp=new node;                    //Insert '50' to the back of li1 like 40->10->20->30->50
  node *cur=head;
  if(head==NULL){                         //If list is empty then create a node and initialize it to head node
    temp->data=data;
    temp->next=head;
    head=temp;
  }
  else{                                   //Else traverse to the last node using cur until its next points to NULL and set its
    temp->data=data;                      //pointer to temp node which holds the new node data and whose next points to NULL making it
    temp->next=NULL;                      //the new last node
    while(cur->next!=NULL){
      cur=cur->next;
    }
    cur->next=temp;
  }
}

void list::removeFront(){                //Remove the frontmost element of li1 making the list as 10->20->30->50
  if(head!=NULL){
    node *temp;                          //If list isn't empty set the head node to temp, and move the head pointer to next and delete
    temp=head;                           //the temp node
    head=head->next;
    delete temp;
  }
  else
    cout<<"No nodes to delete"<<endl;   //Else list is empty
}

void list::removeEnd(){                  //Remove the last element of li1 making the list as 10->20->30
  node *cur=head,*temp=head;
  if(head!=NULL){                       //If there are elements in the list
    while(temp->next!=NULL){            //then traverse to the last node whose next pointer points to NULL and set it to temp
      temp=temp->next;
    }
    if(temp!=head){                     //If there is more than one element in the list, that is temp!=head then traverse to the previous
      while(cur->next!=temp){           //node which points to the last node of the list using cur until its next points to temp
        cur=cur->next;
      }
      cur->next=NULL;                   //Set it to NULL
    }
    else                                //Else if there is only one element in the list, that is temp==head, then just set head to NULL
      head=NULL;
    delete temp;                        //Finally delete the node using 'delete *node'
  }
  else
    cout<<"No nodes to delete"<<endl;   //Else list is empty if head==NULL
}

void list::display(){                   // Traverse the list li1 to display 10->20->30
  node *temp= head;
  cout<< "\n[head] ";
  while(temp!=NULL){                    //Initializing head as temp, traverse and display the data of every node until the last node
    cout<<"=> "<< temp->data;           //is reached
    temp= temp->next;
  }
  cout<<"=> [null]"<<endl;
}

void list::findNode(int data){          // Traverse the list li1 to find an element for eg.'20', set the flag if found and print the
  node *temp= head;                     // appropriate message and position of the element if found
  int pos=0,flag=0;
  while(temp!=NULL){
    if(temp->data==data){
      cout<<"Element "<<data<<" found at index-position: "<<pos<<endl;
      flag=1;
    }
    temp=temp->next;
    pos++;
  }
    if(flag==0)
    cout<<"Element not found"<<endl;
}
void list::findRemove(int data){        // Traverse the list li1 to find an element for eg.'20' to delete it, set the flag if found
    int flag=0,pos=0;                   // and delete the node, else don't and print the appropriate message
    node *cur=head,*temp=head;
    while(temp!=NULL){
    if(temp->data==data){
      flag=1;
      cout<<"Element "<<data<<" found and deleted at index-position: "<<pos<<endl;
      break;
    }
    pos++;
    temp=temp->next;
  }
  if(flag==0)
    cout<<"Element not found"<<endl;
  else{
    if(temp!=head){                           //If element is found but not in the head position link, traverse upto the previous node of the
      while(cur->next!=temp){                 // required node using cur and link the next pointer of the previous node(cur) to the next pointer
        cur=cur->next;                        // of the required node hence taking out the node from between
      }
        cur->next=temp->next;
    }
    else if(temp==head && head->next!=NULL)   //If element is found at head(first) position and there's consecutive node(s), then simply
      head=head->next;                        //move the head pointer to the next node, breaking its link
    else                                      //Else if element is foundat head(first)position and it's the only node present in the list
      head=NULL;                              // remove the node by setting the head to NULL
  }
    delete temp;                               //Finally delete the node using 'delete *node'
}
int main()
{
  list li;
  int option,data;
  cout<< "Enter \n1.To insert to front\n2.To insert to end\n3.To remove front node\n4.To remove end node\n5.To display the linked list\n6.To find an element\n7.To find and remove\n8.Exit"<<endl;
  while(1){
    cout<<"Enter the option no: ";
    cin>>option;
    switch(option){
      case 1:
                cout<<"Enter the data: ";
                cin>>data;
                li.insertFront(data);
                break;
      case 2:
                cout<<"Enter the data: ";
                cin>>data;
                li.insertEnd(data);
                break;
      case 3:
                li.removeFront();
                break;
      case 4:
                li.removeEnd();
                break;

      case 5:
                li.display();
                break;

      case 6:   cout<<"Enter the data to find its position: ";
                cin>>data;
                li.findNode(data);
                break;
      case 7:
                cout<<"Enter the data to find and delete: ";
                cin>>data;
                li.findRemove(data);
                break;
      case 8:
                exit(0);
      default: cout<<"Enter the correct option"<<endl;
    }
  }
}
