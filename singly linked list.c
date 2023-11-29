#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head;
struct node*ptr;
struct node*temp;
void insert_begin(int val);
void insert_end(int val);
void insert_pos(int val);
void delete_begin();
void delete_end();
void delete_pos();
void display();
void exit();
int main()
{
	int ch,val;
	while(1)
	{
	   printf("\n1.insert at begin \n2.insert at end \n3.insert at pos \n4.delete at begin \n5.delete at end \n6.delete at pos \n7.display \n8.exit");
	   printf("\nenter your choice");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	   	  case 1: printf("enter the value");
	   	           scanf("%d",&val);
	   	           insert_begin(val);
	   	           break;
	   	  case 2: insert_end(val);   
			       break;
		  case 3: insert_pos(val); 
		           break;
		  case 4:  delete_begin();
		           break;
		  case 5:delete_end();
		           break;
		  case 6:delete_pos();
		           break;
		  case 7:display();
		           break;
		  case 8:exit(0);
			       break;
		   defazult:printf("enter wrong choice");
		            break;
						        
		  }	
		         
		   }	
	}
	void insert_begin(int val)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("memory is not allocated");
		}
		else if(head==NULL)
		{
		     ptr->data=val;
			 ptr->next=NULL;
			 head=ptr;
			 	
		}
		else
		{
			ptr->data=val;
			 ptr->next=NULL;
			 head=ptr;
			
		}
		}
		
	void insert_end(int val)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("memory is not allocated");
		}
		else if(head==NULL)
		{
		     ptr->data=val;
			 ptr->next=NULL;
			 head=ptr;
			 	
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			ptr->data=val;
			ptr->next=NULL;
			temp->next=ptr; 
			
		}
		}
		
		void insert_pos(int val)
	{
		int loc,i;
		ptr=(struct node*)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("memory is not allocated");
		}
		else
		{
			printf("enter location where you want to insert");
			scanf("%d",&loc);
			temp=head;
			for(i=0;i<loc-1;i++)
			{
				temp=temp->next;
				if(temp==NULL)
				{
				  printf("cannot insert");
				  return;
				 	
				}
			}
			    ptr->next=temp->next;
			    temp->next=ptr;
				}		
		}
		void delete_begin()
		{
			temp=head;
			if(head==NULL)
		{
			printf("list is empty");
		}
		else
		{
		  head=temp->next;
		  temp->next=NULL;
		  printf("%d is deleted",temp->data);
		  free(temp);	
		}
		}
        void delete_end()
		{
			struct node*temp1;
			struct node*ptr1;
			temp=head;
			if(head==NULL)
		{
			printf("list is empty");
		}
		else if(head->next==NULL)
		{
			printf("%d is deleted",temp->data);
			head=NULL;
			free(head);
			
		}
		else
		{
			while(temp->next!=NULL)
			{
				ptr1=temp;
			}
			ptr1->next=NULL;
			printf("%d is deleted",temp->data);
			free(temp);
			
		}
}
         void delete_pos()
		{
			struct node*temp1;
			temp=head;
			int loc,i;
			if(head==NULL)
		{
			printf("cannot delete");
		}
		else
		{
			printf("enter location");
			scanf("%d",&loc);
			for( i=0;i<loc-1;i++)
			{
				temp1=temp;
				temp=temp->next;
				if(temp==NULL)
				{
					printf("cannot delete");
					
				}
			}
			temp1->next=temp->next;
			temp->next=NULL;
			printf("%d is deleted",temp->data);
			free(temp);
		}
}
        void display()
        {
	          temp=head;
	          if(head==NULL)
	          {
	          	printf("list is empty");
	          	
			  }
			  else
			  {
			  	while(temp!=NULL)
			  	{
			  		printf("\t %d ",temp->data);
					 temp=temp->next; 
	            }
			  }
        }
