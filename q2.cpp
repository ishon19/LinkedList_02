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

node* removeLoops(node* head)
{
    node* test = head;
    node* dummy = head;
    node* reset = NULL;
    node* fixed = NULL;

    while (head != NULL)
    {
        test = reset;
        test = dummy;

        while(test != NULL)
            {

                if((head->data) == (test->data)){
                      break;
                }
                else{add(&fixed,head->data);}
                test = test->next;

            }

        head = head -> next;
    }
    return fixed;
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
    add(&head, 16);
    cout<<"\n First linked list is\n";
    printList(head);
    fixed = removeLoops(head);
    cout<<"\nAfter Loop Removal the list is:\n";
    printList(fixed);

    return 0;
}

