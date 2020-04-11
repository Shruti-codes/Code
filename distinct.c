#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10

int main()
{
	char str[MAX];
	scanf("%s",str);
	int hash[26]={0};
	int l = strlen(str);
	for(int i=0;i<l;i++)
	{
		if(str[i]>='a' && str[i]<='z')
				hash[str[i]-'a']++;
		else
			printf("Error \n");
	}

	 for(int i=0;i<26;i++)
	 	if(hash[i]==1)
	 		printf("%c ", i+'a');
}