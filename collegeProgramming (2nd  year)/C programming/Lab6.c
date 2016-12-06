#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
	char * data;
	struct node * next;
	
};


struct hashtable{
	int size;
	struct node ** table;
};

unsigned hash_string(char * str)
{
  unsigned hash = 0;
  for ( int i = 0; str[i] != '\0'; i++ ) 
  {
    hash = str[i];
  }
  return hash;
}

void hashtable_free(struct hashtable * this)
{
	for(int i=0; i<this->size; i++)
	{
		struct node * temp;
		temp=malloc(sizeof(struct node));
		temp->data=NULL;
		temp->next=NULL;
		
		this->table[i]=temp;
		
		
	}
	
}

struct hashtable * hashtable_new(unsigned sizeH)
{
	
	struct hashtable * theHash;
	theHash->size=sizeH;
	theHash->table=malloc(sizeH * (sizeof(struct node)));
	hashtable_free(theHash);
	
	return theHash;
	
}


void insert(struct hashtable * this, char * item)
{
	
	unsigned hashValue=hash_string(item);
	hashValue=hashValue%this->size;
	if(this->table[hashValue]->data==NULL)
	{
		//printf("%s\n", "Once");
		this->table[hashValue]->data=item;
	}
	else if(this->table[hashValue]->data!=NULL &&  this->table[hashValue]->data!=item)
	{
		struct node * head = malloc(sizeof(struct node));
		struct node * temp = malloc(sizeof(struct node)); //making new node
		head=this->table[hashValue];
		
		temp->data=item;
		temp->next=head;
		head=temp;
		this->table[hashValue]=head;
	}
}

void removeS(struct hashtable * this, char * item)
{
	
	unsigned hashValue = hash_string(item);
	hashValue=hashValue%this->size;

	struct node * head;
	head = this->table[hashValue];
	struct node * temp;
	temp=head;
	struct node * prev;
	struct node * next;

	while(strcmp(temp->data, item)!=0)
	{ 
 		
		prev=temp;
		temp= temp->next;
		
		
	}
	if(temp->next!=NULL)
	{
		
		prev->next=temp->next;
	}
	else if(temp==this->table[hashValue])
	{
		
		this->table[hashValue]=NULL;
	}
	else 
	{
		
		prev->next=NULL;
	}
	
	free(temp);
}

void print(struct hashtable * this)
{
	for(int i=0; i<this->size;i++)
	{
		if(this->table[i]->data==NULL)
		{
			this->table[i]->data="<empty>";
		}
		
		printf("%d", i);
		printf(" %s", this->table[i]->data);
		struct node * temp;
		temp = this->table[i];
		
		if(temp->next!=NULL)
		{
			
			struct node * temp2;
			temp2 = this->table[i];
			while(temp2->next!=NULL)
			{
				
				temp2=temp2->next;
				printf(" %s", temp2->data);
			}
			
		}
		printf("\n");
		
	}
	
}

int main(int argc, char * argv[])
{
	struct hashtable * theHash;
	theHash=hashtable_new(5); 
	
	//print(theHash);
	
	for(int i=1; i<argc; i+=2)
	{
		if(strcmp(argv[i], "+")==0)
		{
			insert(theHash, argv[i+1]);
		}
		else if(strcmp(argv[i], "-")==0)
		{
			removeS(theHash, argv[i+1]);
		}
		else if(strcmp(argv[i], "=")==0)
		{
			print(theHash);
		}
	}
	
	
	
	
	print(theHash);
	return 0;
}





