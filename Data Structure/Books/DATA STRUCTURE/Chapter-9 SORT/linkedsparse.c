#include<stdio.h>
#include<conio.h>
struct node
{
	
	int row;
	int col;
	int data;
	struct node *link;
	
};
struct node *root1=NULL,*root2=NULL,*root3=NULL,*temp;
void getmat();
void display();
void add();
int main()
{
	
	printf("Enter First Matrix ");
	getmat(&root1);
	
	printf("Enter Second Matrix ");
	getmat(&root2);
	
	add();
	printf("Ur First Matrix Is \n");
	display(root1);
	printf("Ur Second Matrix Is \n");
	display(root2);
	printf("Sum is \n");
	display(root3);
	
}
void getmat(struct node **start)
{
	
	int i,j,num;
	struct node *nev;
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<3;j++)
		{
			
			scanf("%d",&num);
			if(num !=0)
			{
				
				nev=(struct node *)malloc(sizeof(struct node));
				nev->row=i;
				nev->col=j;
				nev->data=num;
				nev->link=NULL;
				
				if((*start)==NULL)
				{
					
					(*start)=nev;
					
				}
				else
				{
					
					temp=(*start);
					while(temp->link !=NULL)
					   temp=temp->link;
		             temp->link=nev;
		             
				}
						
			}
		}
	}
}
void display(struct node *start)
{
	int i,j;
    for(i=0;i<3;i++)
    {
    	 for(j=0;j<3;j++)
    	 {
    	 	if(start !=NULL && start->row==i && start->col==j)
    	 	{
	 	    	printf("%5d",start->data);
	 	    	start=start->link;
	 	    }
	 	    else
		 	{
		 		printf("%5d",0);
    	 		
    	 	}
 	    	
       }
       printf("\n");
    	
    }
	  
 
	    getch();
	    return;    	
}
void add()
{
	
	struct node *temp1,*temp2,*nev;
	int i,j;
	temp1=root1;
	temp2=root2;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
		   if((temp1 !=NULL && temp2 !=NULL))
		   {
   			
   			
			if((temp1->row==i && temp1->col==j) ||  (temp2->row==i && temp2->col==j))			
			{
				nev=(struct node *)malloc (sizeof(struct node));
				nev->row=i;
				nev->col=j;
				nev->link=NULL;
				if((temp1->row==i && temp1->col==j)&&(temp2->row==i &&temp2->col==j))
				{
					nev->data=temp1->data+temp2->data;
					temp1=temp1->link;
					temp2=temp2->link;
					
				}
				else if(temp1->row==i && temp1->col==j)
				{
					nev->data=temp1->data;
					temp1=temp1->link;
				}
				else if(temp2->row==i && temp2->col ==j)
				{
					nev->data=temp2->data;
					temp2=temp2->link;
				}
				else
				{
					
				}
				
	     		if(root3==NULL)	
		    	{
			    	root3=nev;
				
			    }
    			else
	    		{
		    		temp=root3;
    				while(temp->link !=NULL)
	    			   temp=temp->link;
	                temp->link=nev;
    			}
			}
		   }
			
			
		}
	    
	}
	while(temp1!=NULL)
	{
		nev=(struct node *)malloc(sizeof(struct node));
		nev->row=temp1->row;
		nev->col=temp1->col;
		nev->data=temp1->data;
		nev->link=NULL;
		
		if(root3==NULL)	
	    	{
    		    	root3=nev;
				
			    }
    			else
	    		{
		    		temp=root3;
    				while(temp->link !=NULL)
	    			   temp=temp->link;
	                temp->link=nev;
    			}
		temp1=temp1->link;
	}
	while(temp2!=NULL)
	{
		nev=(struct node *)malloc(sizeof(struct node));
		nev->row=temp2->row;
		nev->col=temp2->col;
		nev->data=temp2->data;
		nev->link=NULL;
		
		if(root3==NULL)	
	    	{
    		    	root3=nev;
				
			    }
    			else
	    		{
		    		temp=root3;
    				while(temp->link !=NULL)
	    			   temp=temp->link;
	                temp->link=nev;
    			}
		temp2=temp2->link;
	}
	return;
}