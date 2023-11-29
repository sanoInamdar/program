#include<stdio.h>
#include<stdlib.h>
struct node
{  
    int data;  
    struct node *leftChild;  
    struct node *rightChild;
	struct node *left;
    struct node *right;  
}; 
struct node *root= NULL; 
struct node* create();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int main()  
{  
       int ch;
       while(1)
       {
            printf("1. Create\n 2. Inorder\n 3. Preorder\n 4. Postorder\n 5. Exit");
            printf("\n Enter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                    case 1:  create();  
                                break;
                    case 2: inorder(root);  
                                break;
		            case 3: preorder(root);  
                                break;
		            case 4: postorder(root);  
                                break;
	            	case 5: exit(0);  
                                break;
		            default: printf("\n Wrong Choice:");
	       }
	}
}  

struct node *create()  
{  
   root=create();
   struct node *temp;  
   int data,ch;  
   temp = (struct node *)malloc(sizeof(struct node));  
   printf("Press 0 to exit");  
   printf("\n Press 1 for new node");  
   printf("Enter your choice : ");  
   scanf("%d", &ch);   
  if(ch==0)  
  {  
       return 0;  
   }  
  else  
  {  
      printf("Enter the data:");  
      scanf("%d", &data);  
      temp->data = data;  
      printf("Enter the left child of %d", data);  
      temp->left = create();  
      printf("Enter the right child of %d", data);  
     temp->right = create();  
     return temp;   
}  
}  
struct node pre_order_traversal(struct node* root) 
{
     if(root!=NULL)
    {
         printf("%d ",root->data);
         pre_order_traversal(root->leftChild);
         pre_order_traversal(root->rightChild);
   }
}
struct node inorder_traversal(struct node* root) 
{
      if(root!=NULL) 
     {
          inorder_traversal(root->leftChild);
          printf("%d ",root->data);          
          inorder_traversal(root->rightChild);
     }
}
struct node post_order_traversal(struct node* root)
 {
      if(root!=NULL) 
     {
          post_order_traversal(root->leftChild);
          post_order_traversal(root->rightChild);
          printf("%d ", root->data);
     }
}


