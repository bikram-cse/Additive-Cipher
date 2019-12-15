#include<stdio.h>

void encrypt()
{
	FILE *pt,*ct;
	char ch,ch1;
	int key,temp;
	pt=fopen("plain.txt","r");
	if(pt==NULL)
	{
		printf("\nUnable to Open File");
	}
	else
	{
		printf("\nEnter Key: ");
		scanf("%d",&key);
		ct=fopen("cipher.txt","w");
		while(!feof(pt))
		{
			ch=fgetc(pt);
			if(isalpha(ch))
			{
				temp=(ch-97+key)%26;
				ch1=(temp+65);
				fputc(ch1,ct);
			}
		}
		fclose(pt);
		fclose(ct);
	}
}

void decrypt()
{
	FILE *apt,*ct;
	char ch,ch1;
	int key,temp,keyinv,i;
	ct=fopen("cipher.txt","r");
	if(ct==NULL)
	{
		printf("\nUnable to Open File");
	}
	else
	{
		printf("\nEnter Key: ");
		scanf("%d",&key);
		for(i=0;i<=25;i++)
		{
			if((key+i)%26==0)
			{
				keyinv=i;
				break;
			}
		}
		apt=fopen("aplain.txt","w");
		while(!feof(ct))
		{
			ch=fgetc(ct);
			if(isalpha(ch))
			{
				temp=(ch-65+keyinv)%26;
				ch1=temp+97;
				fputc(ch1,apt);
			}
		}
		fclose(apt);
		fclose(ct);	   
	}
}

int main()
{
	int choice;
	printf("\nEnter 0 to Exit");
	printf("\nEnter 1 to Encrypt");
	printf("\nEnter 2 to Decrypt");
	printf("\nEnter Your Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
				return;
		case 1:
				encrypt();
				break;
		case 2:
				decrypt();
				break;
	}
	return 0;
}

