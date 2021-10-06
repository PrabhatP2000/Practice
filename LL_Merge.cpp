#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
};

class LinkedList
{
  public:
  node *head, *tail;

  LinkedList()
  {
    head=NULL; 
    tail=NULL;
  }

  void createNode(int temp_data=-1)
  {
    node *nnode = new node;
    nnode->next=NULL;
    if(temp_data==-1)
    {
      cout<<"Enter the data in the new node\n";
      cin>>nnode->data;
    }
    else
    {
      nnode->data=temp_data;
    }
    
    if(head==NULL)
    {
      head=tail=nnode;
    }
    else
    {
      tail->next=nnode;
      tail=nnode;
    }
  }


  void outputList()
  {
    node *temp;
    temp=NULL;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\n";
      temp=temp->next;
    }
  }

  LinkedList mergedList(LinkedList temp1,LinkedList temp2)
  {
    LinkedList merged;
    node *ptr1,*ptr2;
    ptr1=temp1.head;
    ptr2=temp2.head;
    while(ptr1!=NULL && ptr2!=NULL)
    {
      if(ptr1->data<ptr2->data)
      {
        merged.createNode(ptr1->data);
        ptr1=ptr1->next;
      }
      else
      {
        merged.createNode(ptr2->data);
        ptr2=ptr2->next;
      }

    }

    if(ptr1!=NULL)
    {
      while(ptr1!=NULL)
      {
        merged.createNode(ptr1->data);
        ptr1=ptr1->next;
      }
    }
    else
    {
      while(ptr2!=NULL)
      {
        merged.createNode(ptr2->data);
        ptr2=ptr2->next;
      }
    }
    return merged;

  }

};



int main()
{
  LinkedList l,m,n;
  cout<<"Enter data for the first Linked List\n";
  for(int i=0;i<3;i++)
  {
    l.createNode();
  }

  cout<<"Enter data for the second Linked List\n";
  for(int i=0;i<5;i++)
  {
    m.createNode();
  }

  n=n.mergedList(l,m);
  n.outputList();
}
