#include<iostream>      //By H.D
#include<stdlib.h>
using namespace std;

struct node{          //Create a node consiting of integer datatype and a pointer to the next node of same struct type
  int data;
  node *prev,*next;
};
class list{
  private:
    node *head;         //Create a list class to make a head node and initialize it via constructor to NULL
  public:               //Include all the functions you want to perform on the singly linked list and use the scope resolution operator
    list(){             //to define them
      head=NULL;
    }
    void insertFront(int);
    void insertEnd(int);
    void removeFront();
    void removeEnd();
    void display();
    void displayReverse();
    void findNode(int);
    void findRemove(int);            //Take example of a list li1= 10->20->30
    void replaceNode(int,int);
    ~list();
};
list::~list(){                            //De-allocating the linked list memory nodes from memory during exit call
  while(head!=NULL){
    node *temp=head;
    head=head->next;
    delete temp;
  }
  cout<<"List deleted"<<endl;
}
void list::insertFront(int data){         //Insert '40' to the front of li1 like 40->10->20->30
  node *temp= new node;
    temp->data=data;
    temp->prev=NULL;
    if(head==NULL)
    {
      temp->next=NULL;                     //If list is empty obtain the value in a temp node and point it to itself
      head=temp;
    }
    else{
      temp->next=head;                    //And if the list isn't empty add the node to the front and link the previous and next
      head->prev=temp;                    //of the old list and the new node linked
      head=temp;
    }
}

void list::insertEnd(int data){
  node *temp=new node;                    //Insert '50' to the back of li1 like 40->10->20->30->50
  node *cur=head;
  if(head==NULL){                         //If list is empty then create a node and initialize it to head node
    temp->data=data;
    temp->prev=NULL;
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
    temp->prev=cur;
  }
}

void list::removeFront(){                //Remove the frontmost element of li1 making the list as 10->20->30->50
  node *temp=head;
  if(head==NULL)
    cout<<"No nodes to delete"<<endl;   //list is empty
  else if(head->next==NULL){            //If its the only element in the list, delete the list
    head=NULL;
    delete temp;
  }
  else if(head!=NULL){               //If list isn't empty set the head node to temp, and move the head pointer to next and delete temp
    head=head->next;
    temp->next=NULL;
    head->prev=NULL;
    delete temp;                         //Finally delete the node using 'delete *node'
  }
}

void list::removeEnd(){                  //Remove the last element of li1 making the list as 10->20->30
  node *temp=head;
  if(head==NULL)
    cout<<"No nodes to delete"<<endl;   //list is empty if head==NULL
  else if(head->next==NULL){
    head=NULL;                          //If its the only element in the list, delete the list
    delete temp;
  }
  else if(head->next!=NULL){            //If there are elements in the list
    while(temp->next!=NULL){            //then traverse to the last node whose next pointer points to NULL and set it to temp
      temp=temp->next;
    }
    (temp->prev)->next=NULL;            //Link the next-pointer of left(previous) node of the to be deleted node to NULL
    temp->prev=NULL;
    delete temp;
  }

}

void list::display(){                   // Traverse the list li1 to display
  node *temp= head;
  if (head==NULL)
    cout<<"List is empty"<<endl;
  else{
    cout<< "\n[null] ";
    while(temp!=NULL){                    //Initializing head as temp, traverse and display the data of every node until the last node
      cout<<" <=> "<< temp->data;           //is reached
      temp= temp->next;
    }
    cout<<" <=> [null]"<<endl;
  }
}

void list::displayReverse(){                   // Traverse the list li1 to display
  node *temp= head;
  if (head==NULL)
    cout<<"List is empty"<<endl;
  else{
    while(temp->next!=NULL)
      temp=temp->next;
    cout<<"Reversed linked list:"<<endl;
    cout<< "\n[null] ";
    while(temp!=NULL){                    //Initializing head as temp, traverse and display the data of every node until the last node
      cout<<" <=> "<< temp->data;           //is reached
      temp= temp->prev;
    }
    cout<<" <=> [null]"<<endl;
  }
}

void list::findNode(int data){          // Traverse the list li1 to find an element, set the flag if found and print the
  node *temp= head;                     // appropriate message and position of the element if found
  int pos=0,flag=0;
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
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

void list::replaceNode(int data,int data2){        // Traverse the list li1 to find an element, set the flag if found and print the
  node *temp= head;                               // appropriate message and replace with the newdata
  int pos=0,flag=0;
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  while(temp!=NULL){
    if(temp->data==data){
      cout<<"Element "<<data<<" found at index-position: "<<pos<<endl;
      temp->data=data2;
      flag=1;
    }
    temp=temp->next;
    pos++;
  }
    if(flag==0)
    cout<<"Element not found"<<endl;
    else
    cout<<"Element replaced"<<endl;
}

void list::findRemove(int data){        // Traverse the list li1 to find an element to delete it, set the flag if found
    int flag=0,flag2=0,pos=0;                   // and delete the node, else don't and print the appropriate message
    node *temp=head;
    if(head==NULL){
      cout<<"List is empty"<<endl;
      return;
    }
    while(temp->next!=NULL){
    if(temp->data==data){
      flag=1;
      flag2=1;
      cout<<"Element "<<data<<" found and deleted at index-position: "<<pos<<endl;
      break;
    }
    pos++;
    temp=temp->next;
    }
    if(temp->data==data && flag2==0){       //So we check manually, if the flag2=0 then the end element (or the only element if single value list)
      flag=1;                               //wasn't checked and if it satisfies the temp->data=data, we set flag =1 and print message
      cout<<"Element "<<data<<" found and deleted at index-position: "<<pos<<endl;
    }
    if(flag==0)
      cout<<"Element not found"<<endl;
    else{
      if(temp==head && head->next!=NULL){    //If the element is the first element in the list to be found
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
      }
      else if(temp==head && head->next==NULL)   //If the element is the first and only element in the list
        head=NULL;
      else if(temp->next==NULL){                //If the element is not the first element but the last element in the last
        (temp->prev)->next=NULL;
        temp->prev=NULL;
      }
      else{                                     //if the element is neither first nor last in the list
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
      }
    delete temp;                            //Finally delete the node using 'delete *node'
  }
}
int main()
{
  list li;
  int option,data,data2;
  cout<< "Enter \n1.To insert to front\n2.To insert to end\n3.To remove front node\n4.To remove end node\n5.To display the linked list\n6.To display the reversed linked list\n7.To find an element\n8.To find and remove\n9.To find and replce\n10.Exit"<<endl;
  while(1){
    cout<<"\nEnter the option no: ";
    cin>>option;
    cout<<endl;
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
      case 6:
                li.displayReverse();
                break;

      case 7:   cout<<"Enter the data to find its position: ";
                cin>>data;
                li.findNode(data);
                break;
      case 8:
                cout<<"Enter the data to find and delete: ";
                cin>>data;
                li.findRemove(data);
                break;
      case 9:
                cout<<"Enter the data to find: ";
                cin>>data;
                cout<<"\nEnter what to replace it with: ";
                cin>>data2;
                li.replaceNode(data,data2);
                break;
      case 10:
                li.~list();
                exit(0);
      default: cout<<"Enter the correct option"<<endl;
    }
  }
}
