#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
int data;
node* next;
};


void add (struct node** head, int data);

bool isPresent (struct node *head, int data);

 node *doUnion (node *head1, node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
    while (t1 != NULL)
    {
        add(&result, t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            add(&result, t2->data);
        t2 = t2->next;
    }

    return result;
}

 node *doIntersection (node *head1, node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            add (&result, t1->data);
        t1 = t1->next;
    }

    return result;
}

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

bool isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

int main()
{

    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersec = NULL;
    struct node* uni = NULL;
    add (&head1, 67);
    add (&head1, 14);
    add (&head1, 16);
    add (&head1, 18);
    add (&head2, 14);
    add (&head2, 27);
    add (&head2, 67);
    add (&head2, 81);
    intersec = doIntersection (head1, head2);
    uni = doUnion (head1, head2);
    cout<<"\n First linked list is\n";
    printList(head1);
    cout<<"\n Second linked list is";
    printList (head2);
    cout<<"\n Intersection of these two lists is";
    printList (intersec);
    cout<<"\n Union list is \n";
    printList (uni);

    return 0;
}
