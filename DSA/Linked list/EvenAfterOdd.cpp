#include <iostream>
using namespace std;
class node{
   
    public:
     int data;
    node *next;
    node(int d)
    {
        data=d;
        this->next=NULL;
    }

};

node *evenAfterOdd(node *head)
{
   if(head==NULL)
   {
       return NULL;
   }
 node*oh=NULL;
 node*ot=NULL;
 node*eh=NULL;
 node*et=NULL;
 while(head!=NULL)
{
if((head->data)%2==0)
    {
        if(eh==NULL)
        {
            eh=head;
            et=head;
        }
        else
        {
            et->next=head;
            et=et->next;
        }
    }
    else{ 
        if(oh==NULL)
        {
            oh=head;
            ot=head;
        }
        else{
            ot->next=head;
            ot=ot->next;

        }
}   
    head=head->next;
}
if(ot==NULL)
{
    return eh;
}
        else{
        ot->next=eh;
        }
        if(eh!=NULL)
        {
            et->next=NULL;
        }
        return oh;
}

}


node *takeinput()
{   int data;
cin>>data;
node*head=NULL;
while(data!=-1)
{
    node *newnode=new node(data);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        node * temp=head;
        while(temp->next!=NULL)
        {temp=temp->next;}
        temp->next=newnode;

    }
    cin>>data;

}
     return head;
}

node* insertnode(node*head,int i,int data)
{  node* newnode=new node(data);
     if(head==NULL)
{
    return NULL;

}
if(i==0)
{   newnode->next=head;
   head=newnode;
   
}
node *x=insertnode(head->next,i-1,data);
head->next=x;
return head;
 }



node* deletenode(node* head,int i)
{   
    if(head==NULL)
    return NULL;
    if(i==0)
    {
        head=head->next;
        return head;
        delete(head);
    }
    node* x=deletenode(head->next,i-1);
    head->next=x;

  return head;
}


 void print(node *head){
        while(head!=NULL)
        {cout<<head->data<<" ";
        head=head->next;
        }
        

    }
int main() 
{
node * head=takeinput();
print (head);
cout<<endl;
head=evenAfterOdd(head);
print(head);

}
