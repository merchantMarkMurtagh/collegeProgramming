#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include "adt.h"




	
	
	int main()
	{
		char line1[256];
		char line2[256];

		fgets(line1, 256, stdin);
		fgets(line2, 256, stdin);

		struct bitset * bitset1;
		struct bitset * bitset2;
		struct bitset * bitsetIntersection;
		struct bitset * bitsetUnion;
		
		bitset1 = bitset_new(256);
		bitset2 = bitset_new(256);
		bitsetIntersection= bitset_new(256);
		bitsetUnion= bitset_new(256);
		
		for(int i=0; line1[i]!='\0'; i++)
		{
			bitset_add(bitset1, line1[i]);
		}
		
		for(int i=0; line2[i]!='\0'; i++)
		{
			bitset_add(bitset2, line2[i]);
		}
		
		printf("%s\n", "Alphabetical set1: ");
		Display(bitset1);
		printf("%s\n", " ");
		
		printf("%s\n", "Alphabetical set2: ");
		Display(bitset2);
		printf("%s\n", " ");
		
		bitset_intersection(bitsetIntersection, bitset1, bitset2);
		
		printf("%s\n", "Intersection: ");
		Display(bitsetIntersection);
		printf("%s\n", " ");
		
		printf("%s\n", "Union:");
		bitset_union(bitsetUnion, bitset1, bitset2);
		Display(bitsetUnion);
		return 0;
	}








