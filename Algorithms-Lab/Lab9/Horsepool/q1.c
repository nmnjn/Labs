#include<stdio.h>
#include<string.h>

void shift(char P[],int m,int table[])
{
	for(int i=0;i<31;i++)
		table[i]=m;
	for(int i=0;i<m-1;i++)
		table[(int)P[i]-65]=m-i-1;
}
int match(char P[],char T[],int m,int n)
{
	int table[100];
	shift(P,m,table);
	int i=m-1;
	int k;
	while(i<n)
	{
		k=0;
		while(k<m && P[m-1-k]==T[i-k])
			k++;
		if(k==m)
			return i-m+1;
		else
			i=i+table[(int)T[i]-65];
	}
	return -1;
}
int main()
{
	char P[30],T[100];
	int m,n;
	printf("Enter substring\n");
	gets(P);
	printf("Enter string\n");
	gets(T);
	m=strlen(P);
	n=strlen(T);
	int k=match(P,T,m,n);
	if(k==-1)
		printf("No match\n");
	else
		printf("Match at %d\n",k+1);
}