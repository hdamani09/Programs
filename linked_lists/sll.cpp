#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
  int data;
  node *next;
};
class list{
  private:
    node *head;
  public:
    list(){
      head=NULL;
    }
    void insertFront(int data);
    void insertEnd(int data);
    void removeFront();
    void removeEnd();
    void display();
    void findNode(int data);
    void findRemove(int data);
};

void list::insertFront(int data){
  node *temp= new node;
    temp->data=data;
    temp->next=head;
    head=temp;
}

void list::insertEnd(int data){
  node *temp=new node;
  node *cur=head;
  if(head==NULL){
    temp->data=data;
    temp->next=head;
    head=temp;
  }
  else{
    temp->data=data;
    temp->next=NULL;
    while(cur->next!=NULL){
      cur=cur->next;
    }
    cur->next=temp;
  }
}

void list::removeFront(){
  if(head!=NULL){
    node *temp;
    temp=head;
    head=head->next;
    delete temp;
  }
  else
    cout<<"No nodes to delete"<<endl;
}

void list::removeEnd(){
  node *cur,*temp=head;
  if(head!=NULL){
    while(temp->next!=NULL){
      temp=temp->next;
    }
    if(temp!=head){
      while(cur->next!=temp){
        cur=cur->next;
      }
      cur->next=NULL;
    }
    else
      head=NULL;
    delete temp;
  }
  else
    cout<<"No nodes to delete"<<endl;
}

void list::display(){
  node *temp= head;
  cout<< "\n[head] ";
  while(temp!=NULL){
    cout<<"=> "<< temp->data;
    temp= temp->next;
  }
  cout<<"=> [null]"<<endl;
}

void list::findNode(int data){
  node *temp= head;
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
void list::findRemove(int data){
  node *cur,*temp=head;
  int flag=0,pos=0;
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
    if(temp!=head){
      while(cur->next!=temp){
        cur=cur->next;
      }
        cur->next=temp->next;
    }
    else if(temp==head && head->next!=NULL)
      head=head->next;
    else
      head=NULL;
  }
    delete temp;
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
