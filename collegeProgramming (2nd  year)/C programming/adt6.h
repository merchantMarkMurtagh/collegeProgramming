struct bitset{
	char * vector;
	int sizeS;
	
};
	struct bitset * bitset_new(int size)
	{
		struct bitset * s;
		s=malloc(sizeof(struct bitset));
		s->vector=malloc(sizeof(char)*(size)+1);
		
		for(int i=0; i<size; i++)
		{
			s->vector[i]=0;
		}
		s->sizeS=(size/8) +1;
		return s;
	}

	
	int bitset_lookup(struct bitset * this, int item)
	{
		int byte_index = item/8;
		int bit_number = item%8;
		int the_byte = this -> vector[byte_index];
		return ((the_byte >> bit_number ) & 1);
	
	}

	int bitset_add(struct bitset * this, int item)
	{
		int byte_index = item/8;
		int bit_number = item%8;
		int the_byte = this -> vector[byte_index];
		this -> vector[byte_index] = the_byte |= 1 << bit_number;
		
		
		return 1 ;
	
	}

	int bitset_remove(struct bitset * this, int item)
	{
		int byte_index = item/8;
		int bit_number = item%8;
		int the_byte = this -> vector[byte_index];
		this -> vector[byte_index] = the_byte &= 0 << bit_number;
		
		
		return 1;
	}

	void bitset_union(struct bitset * dest, struct bitset * src1, struct bitset * src2)
	{
		for(int i=0; i<src1->sizeS; i++)
		{
			char src1Item = src1 -> vector[i];
			char src2Item = src2 -> vector[i];
			
			char result = src1Item | src2Item;
			dest-> vector[i]=result;
		}
			
	}
	
	void Display(struct bitset * set)
	{
		for(int i=0; i<255; i++)
		{
			if(bitset_lookup(set, i)==1)
			{
				printf("%c", (char)i);
			}
			
		}
		
		printf("\n");
	}
	

	void bitset_intersection(struct bitset * dest, struct bitset * src1, struct bitset * src2)
	{
		for(int i=0; i<src1->sizeS; i++)
		{
			char src1Item = src1 -> vector[i];
			char src2Item = src2 -> vector[i];
			
			char result = src1Item & src2Item;
			dest-> vector[i]=result;
		}
	}