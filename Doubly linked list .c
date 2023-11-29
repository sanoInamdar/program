#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *ptr;
struct Node *head;
struct Node *temp;
struct Node *temp1;

void insert_begin(int val);
void insert_end(int val);
void insert_pos(int val);
void delete_begin();
void delete_end();
void delete_pos();
void display();

int main()
{
    int ch, val;
    while (1)
    {
        printf("\n1.insert at begin \n2.insert at end \n3.insert at pos \n4.delete at begin \n5.delete at end \n6.delete at pos \n7.display \n8.exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("enter the value: ");
            scanf("%d", &val);
            insert_begin(val);
            break;
        case 2:
            printf("enter the value: ");
            scanf("%d", &val);
            insert_end(val);
            break;
        case 3:
            printf("enter the value: ");
            scanf("%d", &val);
            insert_pos(val);
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_pos();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("enter wrong choice");
            break;
        }
    }
    return 0;
}
void insert_begin(int val)
{
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("memory is not allocated");
    }
    else
    {
        scanf("%d", &val);
        ptr->data = val;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            ptr->prev = NULL;
            head->prev = ptr;
            head = ptr;
        }
    }
}

void insert_end(int val)
{
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("memory is not allocated");
    }
    else
    {
        scanf("%d", &val);
        ptr->data = val;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            ptr->next = NULL;
            temp->next = ptr;
            ptr->prev = temp;
        }
    }
}

void insert_pos(int val)
{
    int loc, i;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("memory is not allocated");
    }
    else
    {
        printf("\n enter location: ");
        printf("\n enter value: ");
        scanf("%d", &loc);
        scanf("%d", &val);
        temp = head;
        for (i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("can not insert");
            }
        }
        ptr->data = val;
        ptr->prev = temp;
        ptr->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
    }
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (head->next == NULL)
    {
        printf("\n %d is deleted", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        printf("\n %d is deleted", temp->data);
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (head->next == NULL)
    {
        printf("\n %d is deleted", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp->prev = NULL;
        printf("\n %d is deleted", temp->data);
        free(temp);
    }
}

void delete_pos()
{
    int i, loc;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("\n enter location: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("cannot delete");
                return;
            }
        }

        if (temp->next == NULL)
        {
            printf("cannot delete");
            return;
        }

        temp1 = temp->next;
        temp->next = temp1->next;
        if (temp1->next != NULL)
        {
            temp1->next->prev = temp;
        }
        temp1->next = NULL;
        temp1->prev = NULL;
        printf("\n %d is deleted", temp1->data);
        free(temp1);
    }
}

void display()
{
    temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        do
        {
            printf("\t %d ", temp->data);
            temp = temp->next;
        }while(temp!=NULL);
  }
}







