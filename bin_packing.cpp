#include<stdlib.h>
#include<stdio.h>
#define size 10
int a[size][size],l[size],bb[size],re[size][size],ar=size*size,aa[size][size],aar=size*size,al[size],abb[size];
struct box
{
	int length;
	int bredth;
	int no;
	struct box *next;
	struct box *p;
}*top,*newnode,*temp,*rear,*temp2,*top2,*rear2,*temp3;

void display(struct box *temp3)
{
	if(temp3==NULL)
	{
		printf("Underflow..!! ");
		system("PAUSE");
		return;
	}
	while(temp3!=NULL)
	{
		printf("%d --> %d \n",temp3->length,temp3->bredth);
		temp3=temp3->next;	
	}
	printf("!!! ");
	system("PAUSE");	
}

void copy_ll()
{
	temp3=top;
	if(temp3==NULL)
	{
		printf("Underflow..!! ");
		system("PAUSE");
		return;
	}
	
	newnode= (struct box *)malloc(sizeof(struct box));
	if(newnode==NULL)
	{
		printf("\nOut of memeory space..!! ");
		system("PAUSE");
		return;
	}
	newnode->next=NULL;
	newnode->p=NULL;
	newnode->bredth=temp3->bredth;
	newnode->length=temp3->length;
	newnode->no=(newnode->length*10)+newnode->bredth;
	
	top2=rear2=newnode;
	temp3=temp3->next;	
	while(temp3!=NULL)
	{
		newnode= (struct box *)malloc(sizeof(struct box));
		if(newnode==NULL)
		{
			printf("\nOut of memeory space..!! ");
			system("PAUSE");
			return;
		}
		newnode->next=NULL;
		newnode->p=NULL;
		newnode->bredth=temp3->bredth;
		newnode->length=temp3->length;
		newnode->no=(newnode->length*10)+newnode->bredth;
		
		newnode->p=rear2;
		rear2->next=newnode;
		rear2=newnode;
		
		temp3=temp3->next;
	}
}

void push()
{
	int len,b;
	newnode= (struct box *)malloc(sizeof(struct box));
	if(newnode==NULL)
	{
		printf("\nOut of memeory space..!! ");
		system("PAUSE");
		return;
	}
	
	printf("Enter the Length, Bredth of the box : ");
	scanf("%d %d",&len,&b);
	if (len>b)
	{
		newnode->length=len;
		newnode->bredth=b;
	}
	else
	{
		newnode->length=b;
		newnode->bredth=len;
	}
	newnode->next=NULL;
	newnode->p=NULL;
	newnode->no=(newnode->length*10)+newnode->bredth;
	
	temp=top;
	
	if(temp==NULL)
		rear=top=newnode;
	else
	{
		if(rear->no >= newnode->no)
		{
			newnode->p=rear;
			rear->next=newnode;
			rear=newnode;
			display(top);
			return;
		}
		else if(top->no <= newnode->no)
		{
			newnode->next=top;
			top->p=newnode;
			top=newnode;
			display(top);
			return;
		}
		while(temp!=NULL)
		{
		    if(temp->no <= newnode->no)
			{	
				newnode->next=temp;
				temp->p->next=newnode;
				newnode->p=temp->p;
				temp->p=newnode;	
				break;
			}
			temp=temp->next;
		}
	}
	display(top);
}

struct box * del_using_boxno(int no, struct box *&top, struct box *&rear)
{
	temp3=top;
	while(temp3!=NULL && temp3->no!=no)
		temp3=temp3->next;
	
	if(temp3==NULL)
	{
		printf("Data not Found..!! ");
		system("PAUSE");
		return NULL;
	}
	else
	{
		if(top==rear)
		{
			top=rear=NULL;
			free(temp3);
			return NULL;
		}
		else if(top->next==rear)
		{
			if(temp3==rear)
			{
				top->next=NULL;
				rear=top;
				free(temp3);
			}
			else
			{
				rear->p=NULL;
				top=rear;
				free(temp3);
			}
			return top;
		}
		else if(temp3==top)
		{
			top=top->next;
			free(temp3);
			return top;
		}
		else if(temp3==rear)
		{
			rear=rear->p;
			rear->next=NULL;
			free(temp3);
			return rear;
		}
		else
		{
			temp3->p->next=temp3->next;
			temp3->next->p=temp3->p;
			temp2=temp3->next;
			free(temp3);
			return temp2;
		}
	}
}

void dis(int a[][size], int l[], int bb[], int ar)
{
	int i,j;
	system("CLS");
	for(i=0;i<size;i++)
	{	
		for(j=0;j<size;j++)
			printf("%3d ",a[i][j]);
		printf("%2d \n",l[i]);
	}
	for(i=0;i<size;i++)
		printf("%3d ",bb[i]);
	printf("\n %d \n",ar);
	system("PAUSE");	
}

int allocate_length(int len,int b, int a[][size],int  l[], int bb[],struct box *&top, struct box *&rear)
{
	int check=0,starti,startj,ii,j,i,f=0,gaps=1;
	starti=startj=-1;
	for(i=0;i<size;i++)
	{	
		if(l[i]>=len)
		{	
			while(gaps!=0 && i+b-1<size && b>1)
			{
				gaps=0;
				for(ii=i; ii<i+b ; ii++)
				{
					if(l[i]!=l[ii])
						gaps=1;
				}
				if(gaps==1)
				{
					i++;
					if(!(i+b-1<size))
						return f;
					continue;
				}
				else
					break;
			}
			
			if(startj==-1)
			{
				starti=i;
				startj=size-l[i];
			}
			check+=l[i];
			if (check>=len*b)
			{
				for(ii=starti;ii<starti+b;ii++)
				{
					for(j=startj;j<startj+len;j++)
					{
						a[ii][j]=temp->no;
						if (ii==starti+b-1)
							bb[j]=size-1-ii;
					}
					l[ii]=size-j;
				}
				f=1;
				temp=del_using_boxno(temp->no,top,rear);
				break;
			}				
		}
		
		else 
		{
			check=0;
			startj=-1;
		}
	}	
	return f;
}

int allocate_b(int len,int b, int a[][size], int l[], int bb[],struct box *&top, struct box *&rear)
{
	int check=0,starti,startj,ii,j,i,f=0;
	starti=startj=-1;
	for(i=0;i<size;i++)
	{
		if(l[i]>=b)
		{	
			if(startj==-1)
			{
				starti=i;
				startj=size-l[i];
			}
			check+=l[i];
			if (check>=len*b)
			{	
				for(ii=starti;ii<starti+len;ii++)
				{
					for(j=startj;j<startj+b;j++)
					{
						a[ii][j]=temp->no;
						if (ii==starti+len-1)
							bb[j]=size-1-ii;
					}
					l[ii]=size-j;
				}
				f=1;
				temp=del_using_boxno(temp->no,top,rear);
				break;
			}				
		}
		
		else 
		{
			check=0;
			startj=-1;
		}
	}
	return f;
}

int allocate_d(int len, int b,int s,int a[][size], int l[], int bb[],struct box *&top, struct box *&rear)
{
	int ii,j;
	for(ii=size-len;ii<size;ii++)
	{
		for(j=s;j<s+b;j++)
		{
			a[ii][j]=temp->no;
			if (ii==size-1)
				bb[j]=size-1-ii;
		}
		l[ii]=size-j;
	}
	temp=del_using_boxno(temp->no,top,rear);
	return 1;				
}

void allocate()
{	
	int b,i,ii,len,f,jump;
	temp=top;
	while(temp!=NULL)
	{	
		f=jump=0;
		b=temp->bredth;
		len=temp->length;	
		
		for(ii=0;ii<=size-b;ii++)
			if(bb[ii]==len)
				break;
				
		if(bb[ii]==len && len!=size && ii!=size+1-b && ii+b<size)
		{		
			int s=ii;
			for(i=ii;i<ii+b ;i++)
				if(!bb[i]==len)
				{	
					jump=1;
					break;
				}
			if(jump==0)
				f=allocate_d(len,b,s,a,l,bb,top,rear);
			
		}
		if (f==0)
			f=allocate_length(len,b,a,l,bb,top,rear);
				
		if (f==0)
			f=allocate_b(len,b,a,l,bb,top,rear);
		
		if(f==0)
			temp=temp->next;
		
		if(temp==NULL)
			break;
	}
}


void allocate2()
{	
	int b,i,ii,len,f;
	temp=top2;
	while(temp!=NULL)
	{	
		f=0;
		b=temp->bredth;
		len=temp->length;
				
		f=allocate_length(len,b,aa,al,abb,top2,rear2);
		if (f==0)
		{
			f=allocate_b(len,b,aa,al,abb,top2,rear2);
		}
		if(f==0)
		{
			temp=temp->next;
		}
	}
}
void restart()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			a[i][j]=0;
			aa[i][j]=0;
		}
		l[i]=al[i]=size;
		bb[i]=abb[i]=size;
	}	
}
int main()
{
	int i,j;
	top2=rear2=NULL;
	restart();
	int choice=1;
	while(choice!=0)
	{
		system("CLS");
		printf("\nMenu : \n1. New Box \n2. Display \n3. Allocate \n4. Free Box \n0. Exit ");
		scanf("%d",&choice);
		
		if(choice==1)
			push();
		else if(choice==2)
		{
			display(top);
			display(top2);
		}
		else if(choice==3)
		{
			if(top==NULL)
			{
				printf("\nEnter box data first ");
				system("PAUSE");
			}
			else		
			{
				copy_ll();
				ar=aar=0;
				allocate();
				system("PAUSE");
				allocate2();
				system("PAUSE");
				for(i=0;i<size;i++)
				{
					ar+=l[i];
					aar+=al[i];
				}
				if(ar<aar)
					dis(a,l,bb,ar);
				else if (ar>aar)
					dis(aa,al,abb,aar);
				else
				{
					printf("2 possible solutions : ");
					system("PAUSE");
					dis(a,l,bb,ar);
					dis(aa,al,abb,aar);	
				}	
			}
		}
		else if(choice==4)
			restart();
	}
	temp=top;
	struct box *t;
	while(temp!=NULL)
	{
		t=temp;
		temp=temp->next;
		free(t);
	}
	return 0;
}
