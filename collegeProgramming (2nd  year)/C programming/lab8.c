#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <String.h>



struct node
{
    int freq;
    int leaf;
    
    char code[256]; //code which relates to character
    union
    {
        struct
        {
            struct node * left;
            struct node * right;
        }compound;
		char c;
    }u;
    
};

int * countfreqs(char * filename)                        //return an array of char's frequencies
{
	int * freqs = calloc(256, sizeof(int));
    
    for(int i=0; i<256; i++)
    {
        freqs[i]=0;
    }
    FILE * file;
    unsigned char c;
    file= fopen(&filename[0], "r");
    assert(file!=NULL);
    c= fgetc(file);
    while( !feof(file) ) {
        freqs[c]++;
        c = fgetc(file);
    }
    fclose(file);
    return  freqs;
    
}

int find_lowest_freq(struct node ** list, int size)             // finds lowest frequency
{
	int lowest =0;
	
    for(int i=0; i<size;i++)
    {
        if(list[i]->freq < list[lowest]->freq)
        {
            lowest= i;
			//printf("%d\n", list[temp]->freq );
        }
        
    }
    return lowest;
}

struct node * create_compound_node(struct node * p,struct node * p2)   // take two nodes and makes one
{
    
    struct node * result;
    result = malloc(sizeof(struct node));
    result ->freq = p->freq+p2->freq;
    result->leaf=0;
    result->u.compound.left=p;
    result->u.compound.right=p2;
    return result;
    
};


struct node * build_huffman_tree(int * freqs, int nFreqs)
{
	struct node ** list;
	list =malloc(sizeof(struct node *) * nFreqs);
	int count =0;
	
    for(int i=0; i<nFreqs; i++)
    {
		if(freqs[i]!=0)
		{
			
        	struct node * p = malloc(sizeof(struct node));
       	 	p->freq=freqs[i];
       	 	p->leaf=1;
       	 	p->u.c=(unsigned char)i;
			
			list[count]=p;
			//printf("%d\n", list[count]->freq);
			count++;
		}
    }
	nFreqs=count;
	
	while(nFreqs>1)
	{
		int smallest;
		int secondSmallest;
		smallest=find_lowest_freq(list, nFreqs);
		//printf("%d\n", smallest);
		
		struct node *p, *p2;
		p=list[smallest];
		list[smallest]=list[nFreqs-1];
     	
		nFreqs--;
   	 	int smallest2 = find_lowest_freq(list, nFreqs);
   	 	p2=list[smallest2];
		
   	 	struct node * comp;
		comp= create_compound_node(p, p2);
		//fprintf(stderr, "%d   %d   %d\n  ", p->freq, p2->freq,comp->freq);
   	 	list[smallest2]=comp;
	 
	}
	return list[0];
};

void encodeTree(struct node * list, char * prefix)
{
	
	if(list->leaf==0) 
	{
		
		int length = strlen(prefix);
		
		char * temp[length+2];
		strcpy(temp, prefix);
		strcat(temp, "0");
		encodeTree(list->u.compound.left, temp);
		strcpy(temp, prefix);
		strcat(temp, "1");
		encodeTree(list->u.compound.right, temp);
		
	}
	
	else 
	{
		strcat(list->code, prefix);
		printf("%c:          %s\n", list->u.c, prefix);
	}
}

char * encoder(struct node * list, char ** toChange)
{
	char * codeSend;
	for(int i=0; i<sizeof(toChange); i++)
	{
		for(int j=0; j<sizeof(list); j++)
		{
			if(strcmp(toChange[i], &list[j].u.c)==0)
			{
				strcat(codeSend, list[j].code);
			}
				
		}
	}
	return codeSend;
	
}


int main(int argc, char ** argv)
{
	
	int * freq = countfreqs(argv[1]);
	struct node * t;
	t=build_huffman_tree(freq, 256);
	
	char * prefix;
	
	prefix =calloc(sizeof(char), 1);
	printf("%s\n", "Character        Huffman Code");
	encodeTree(t, prefix);
	
	
	
	printf("%s\n", "JUMPMAN, JUMPMAN, JUMPMAN, JUMPMAN");
	
	char stringToSend=  * encoder(t, toChange);
	
	//printf("%s\n", "Here it is");
	
    return 0;
}

