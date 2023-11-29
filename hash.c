#include<stdio.h>
#include<conio.h>
#define size 10
int arr[size];
void init();
void insert(int value);
void del(int value);
void print();
int main()
{
   int ch =0,temp;
   init();
   while (ch!=4)
   {
       printf("\n1.Insert\n2.Delete\n3.Print hash table\n4.Exit\nEntre your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1 : printf("Entre element to be inserted : ");
                    scanf("%d",&temp);
                    insert(temp);
                    break;
           case 2 : printf("Entre element to be deleted : ");
                    scanf("%d",&temp);
                    del(temp);
                    break;
           case 3 : print();
                    break;
           case 4 : exit(0);
                    break;
           default : printf("wrong input !!!");
       }
     }
  return 0;
}

void init()
{
   int i;
   for(i = 0; i < size; i++)
       arr[i] = -1;
}

void insert(int value)
{
    int flag=1;
    int key = value % size;
    if(arr[key] == -1)
    {
       arr[key] = value;
       printf("%d inserted with key %d !\n", value,key);

    }
    else
    {
        printf("Collision : key %d has element %d already!\n",key,arr[key]);
        while(flag)
        {
            while(arr[key]!=-1)
            {
                key++;
            }
            if(key != size-1)
            {
                 //if(arr[key] == -1)
                 //{
                       arr[key] = value;
                   printf("%d inserted with key %d !\n", value,key);
                   flag=0;
            }
            else
                printf("\n Unable to insert");
        }
    }
}

//delete item from table
void del(int value)
{
    /*int key = value % size;
    if(arr[key] == value)
         arr[key] = -1;
    else
         printf("%d not present in the hash table\n",value);*/
    int i;
    for(i =0; i<size-1; i++)
    {
        if(arr[i] == value)
        {
            arr[i] = -1;
            printf("\n %d is deletd",value);
        }
    }

}
//hash table print method
void print()
{
    int i;
    printf("\nVALUE\t---\tKEY");
    printf("\n===================\n");
    for(i = 0; i < size; i++)
    {
         if(arr[i]!=-1)
         {
               printf("%d\t---\t%d\n",arr[i],i);
         }
    }
}

