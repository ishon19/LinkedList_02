#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
int data;
node* next;
};

void add (node** head_ref, int new_data)
{

     node* new_node =
        (node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList (node *node)
{
    while (node != NULL)
    {
        cout<<"\n"<<node->data;
        node = node->next;
    }
}

node* segregate(node* head)
{
    node* even = NULL;
    node* odd = NULL;
    node* seg = NULL;
    node* h1;
    node* h2;
    int pos=0;

    while (head != NULL)
    {
        if(pos%2==0)
        {
            add(&even,head->data);
        }
        else{
            add(&odd,head->data);
        }
        pos++;
        head = head -> next;
    }
     cout<<"\n";
     printList(even);
     cout<<"\n";
     printList(odd);
    pos = 0;
    h1 = even;
    h2 = odd;
    while (h1 != NULL && h2!=NULL)
    {
        if(pos%2==0 )
        {
            add(&seg,h2->data);
        }
        if(pos%2!=0){
            add(&seg,h1->data);
        }
        pos++;
        h1 = h1 -> next;
        h2 = h2->next;
    }
    return seg;
}



int main()
{

    node* head = NULL;
    node* fixed = NULL;
    add(&head, 67);
    add(&head, 14);
    add(&head, 16);
    add(&head, 18);
    add(&head, 45);
    add(&head, 44);
    add(&head, 19);
    cout<<"\n the linked list is\n";
    printList(head);
    fixed = segregate(head);
    cout<<"\nSegregated list is:\n";
    printList(fixed);

    return 0;
}

