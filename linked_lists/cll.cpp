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
    void insertNew(int);
    void removeNew();
    void display();
    void findNode(int);
    void findRemove(int);            //Take example of a list li1= 10->20->30
    void replaceNode(int,int);
    ~list();
};

list::~list(){                  //De-allocating the linked list memory nodes from memory during exit call
  while(head->next!=head){
    node *temp=head;
    head=head->next;
    node *cur=head;           //This nested while loop deletes up until the second last element because the condition fails at the
    while(cur->next!=temp)    //the last element as head->next == head for one element in the circular list.
      cur=cur->next;
    cur->next=head;
    delete temp;
  }
  if(head->next==head){       //That's why we seperately delete the remaining head node
    delete head;
  }
    cout<<"List deleted"<<endl;
}

void list::insertNew(int data){                //Insert '40' to the front of li1 like 40->10->20->30
    node *temp=new node;
    temp->data=data;
    if(head==NULL){                           //If list is empty obtain the value in a temp node and point it to itself
      temp->next=temp;
    }
    else{
      node *cur=head;                         //And if the list isn't empty link the new node to the previous head and traverse
      temp->next=head;                        //the old list using cur node so the last node of the old list will point to temp
      while(cur->next!=head){
        cur=cur->next;
      }
      cur->next=temp;
    }
    head=temp;                               //initialize the temp as the new head
}
void list::removeNew(){
  node *temp=head;                           //Remove the frontmost element of li1 making the list as 10->20->30->50
  if(head==NULL){
    cout<<"List is empty"<<endl;             //If list is empty, print the appropriate message
    return;
  }
  head=head->next;                          //If list isn't empty set the head node to temp, and move the head pointer to next and delete
  node *cur=head;                           //then traverse the list to the end node using another cur node
  while(cur->next!=temp){
    cur=cur->next;
  }
  if(cur==temp)                             //If there was only one element in the list, then set the head to null to unlink it
    head=NULL;
  else
    cur->next=head;                         //Else point the next pointer of cur(the last element) to the new shifted head
  delete temp;                              //Finally delete the node using 'delete *node'

}
void list::display(){                   // Traverse the list li1 to display 10->20->30
  node *temp= head;
  if(head==NULL){                       // If head is NULL, means list is empty and return to main
    cout<<"List is empty"<<endl;
    return;
  }
  cout<< "\n[head] ";
  if(temp->next==temp)                  //If there's only one element in the list, display that
    cout<<"=> "<< temp->data;
  else{
    while(temp->next!=head){            //Else Initializing head as temp, traverse and display the data of every node until the temp points
        cout<<"=> "<< temp->data;       //to the first head node
        if(temp->next==head) break;
        temp= temp->next;
      }
      cout<<"=> "<< temp->data;         //Since the temp stops at the last node and doesn't display because the while loop condition fails
    }                                   //we manually display the last node data of traversed temp
  cout<<"=> [head]"<<endl;
}

void list::findNode(int data){          // Traverse the list li1 to find an element for eg.'20', set the flag if found and print the
  node *temp= head;                     // appropriate message and position of the element if found
  int pos=0,flag=0;
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  while(temp->next!=head){
    if(temp->data==data){
      cout<<"Element "<<data<<" found at index-position: "<<pos<<endl;
      flag=1;
    }
    temp=temp->next;
    pos++;
  }
  if(temp->data==data){
    cout<<"Element "<<data<<" found at index-position: "<<pos<<endl;
    flag=1;
  }
  if(flag==0)
  cout<<"Element not found"<<endl;
}

void list::replaceNode(int data,int data2){          // Traverse the list li1 to find an element for eg.'20', set the flag if found and print the
  node *temp= head;                               // appropriate message and replace with the newdata
  int pos=0,flag=0;
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  while(temp->next!=head){
    if(temp->data==data){
      cout<<"Element "<<data<<" found at index-position: "<<pos<<endl;
      temp->data=data2;
      flag=1;
    }
    temp=temp->next;
    pos++;
  }
  if(temp->data==data){
    cout<<"Element "<<data<<" found at index-position: "<<pos<<endl;
    temp->data=data2;
    flag=1;
  }
  if(flag==0L)
    cout<<"Element not found"<<endl;
  else
    cout<<"Element replaced"<<endl;
}

void list::findRemove(int data){        // Traverse the list li1 to find an element for eg.'20' to delete it, s
    int flag=0,flag2=0,pos=0;
    node *temp=head;
    while(temp->next!=head){
      if(temp->data==data){             //Set the flag if found and flag2=0 and print the appropriate message and break out of loop which
        flag=1;                         //checks for the data upto to the second last element because after that temp->next points to head
        flag2=1;                        //making the condition of while loop false
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
    if(flag==0)                             //Check the flag value to verify if the element was found and display appropriate message
      cout<<"Element not found"<<endl;
    else{
      if(temp!=head){
        node *cur=head;                         //If element is found but not in the head position link, traverse upto the previous node of the
        while(cur->next!=temp){                 // required node using cur and link the next pointer of the previous node(cur) to the next pointer
          cur=cur->next;                        // of the required node hence taking out the node from between
        }
          cur->next=temp->next;
      }
      else if(temp==head && head->next!=head)   //If element is found at head(first) position and there's consecutive node(s), then simply
      {
        head=head->next;                        //move the head pointer to the next node, breaking its link
        node *cur=head;                         //then traverse to the last element of the list using cur node and point cur's next to the
        while(cur->next!=temp){                 //new head node
          cur=cur->next;
        }
        cur->next=head;
      }
      else                         //Else if element is foundat head(first)position and it's the only node present in the list
        head=NULL;                 // remove the node by setting the head to NULL
      delete temp;                 //Finally delete the node using 'delete *node'
    }
}

int main()
{
  list li;
  int option,data,data2;
  cout<< "Enter \n1.To insert a node\n2.To remove a node\n3.To display the linked list\n4.To find an element\n5.To find and remove\n6.To find and replace\n7.Exit"<<endl;
  while(1){
    cout<<"Enter the option no: ";
    cin>>option;
    switch(option){
      case 1:
                cout<<"Enter the data: ";
                cin>>data;
                li.insertNew(data);
                break;
      case 2:
                li.removeNew();
                break;

      case 3:
                li.display();
                break;

      case 4:   cout<<"Enter the data to find its position: ";
                cin>>data;
                li.findNode(data);
                break;
      case 5:
                cout<<"Enter the data to find and delete: ";
                cin>>data;
                li.findRemove(data);
                break;
      case 6:
                cout<<"Enter the data to find: ";
                cin>>data;
                cout<<"\nEnter what to replace it with: ";
                cin>>data2;
                li.replaceNode(data,data2);
                break;
      case 7:
                li.~list();
                exit(0);
      default: cout<<"Enter the correct option"<<endl;
    }
  }
}
