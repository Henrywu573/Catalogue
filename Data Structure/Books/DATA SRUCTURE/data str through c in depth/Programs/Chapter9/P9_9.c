/*P9.9 Separate chaining*/

#include <stdio.h>
#include<stdlib.h>
#define MAX 11

struct employee
{
	int empid;
	char name[20];
	int age;
};

struct Record 
{
	struct employee info;
	struct Record *link;
};

void insert(struct employee emprec, struct Record *table[]);
int search(int key, struct Record *table[]);
void del(int key, struct Record *table[]);
void display(struct Record *table[]);
int hash(int key);

main()
{
	struct Record *table[MAX];	
	struct employee emprec;
	int i,key,choice;
	
	for(i=0; i<=MAX-1; i++)
		table[i] = NULL;

	while(1)
	{
		printf("1.Insert a record\n");
		printf("2.Search a record\n");
		printf("3.Delete a record\n");
		printf("4.Display table\n");
		printf("5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : 
				printf("Enter the record\n");
				printf("Enter empid, name, age  : ");
				scanf("%d%s%d",&emprec.empid,emprec.name,&emprec.age);
				insert(emprec, table);
				break;
			case 2 : 
				printf("Enter a key to be searched : ");
				scanf("%d", &key);
				i = search(key, table);
				if(i==-1)
					printf("Key not found\n");
				else
					printf("Key found in chain %d\n", i);
				break;
			case 3: 
				printf("Enter a key to be deleted\n");
				scanf("%d",&key);
				del(key,table);
				break;
			case 4:
				display(table);
				break;
			case 5:
				exit(1);
		}
	}
}/*End of main()*/

void insert(struct employee emprec, struct Record *table[])
{
	int h, key;
	struct Record *tmp;

	key = emprec.empid;  /*Extract the key from the record*/
		
	if(search(key, table)!=-1)
	{
		printf("Duplicate key\n");
		return;
	}
    h = hash(key);				
	/*Insert in the beginning of list h*/
	tmp=malloc(sizeof(struct Record));
	tmp->info = emprec;
	tmp->link = table[h];
	table[h] = tmp;
}/*End of insert()*/

void display(struct Record *table[])
{
	int i;
	struct Record *ptr;
	for(i=0; i<MAX; i++)
	{
		printf("\n[%d]  ",i);
		if(table[i]!=NULL)
		{
			ptr=table[i];
			while(ptr!=NULL)
			{
				printf("%d %s %d\t", ptr->info.empid, ptr->info.name, ptr->info.age);
				ptr=ptr->link;
			}
		}
	}
	printf("\n");
}/*End of display()*/

int search(int key, struct Record *table[])
{
	int h;
    struct Record *ptr;
	h = hash(key);				
	ptr = table[h];
	while(ptr!=NULL)
	{
		if(ptr->info.empid == key)
			return h;
		ptr = ptr->link;
	}
	return -1;
}/*End of search()*/

void del(int key, struct Record *table[])
{
	int h;
    struct Record *tmp, *ptr;
	h = hash(key);				
	
	if(table[h]==NULL)
	{
		printf("Key %d not found\n", key);
		return;
	}
	if(table[h]->info.empid == key)
	{
		tmp=table[h];
		table[h]=table[h]->link;  
		free(tmp);
		return;
	}
	ptr = table[h];
	while(ptr->link!=NULL)
	{
		if(ptr->link->info.empid == key)   
		{
			tmp=ptr->link;
			ptr->link=tmp->link;
			free(tmp);
			return;
		}
		ptr=ptr->link;
	}
	printf("Key %d not found\n",key);
}/*End of del()*/

int hash(int key)
{
	return (key%MAX);
}/*End of hash()*/

