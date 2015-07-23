#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
/*structure for node in a given tree*/
struct node
{
    int a;
    node *left;
    node *right;
}*n;
void enterIntoTree(int value){
    int check=0;
    if(n==NULL){              //if its the root element assign a new node
	n = new node;
	n->left = NULL;
	n->right = NULL;
	n->a = value;
    }
    else{
	node *temp = n,*temp1,*prev;
	temp1 = new node;
	temp1->left = NULL;
	temp1->right = NULL;
	temp1->a = value;        // assign the data to a temp pointer
	while(temp!=NULL){     // this loop finds where to enter the new node
	    prev = temp;
	    if(temp->a==value){
		check = 1;
		break;
	    }
	    else if(temp->a>value){
		temp = temp->left;
	    }
	    else if(temp->a<value){
		temp = temp->right;
	    }
	}
	if(check!=1){                   // new node is enter into the tree
	    if(prev->a>value)
		prev->left = temp1;
	    else if (prev->a<value)
		prev->right = temp1;
	}
    }
}
/*the breadth first traveersal of the tree
takes as arguement the starting level and and the level
which is to be printed for the particular iteration
*/
node *temp=NULL,*end=NULL;
void convert(node *n,int flag,int i)
{
    flag++;
    if(n!=NULL&&flag<=i)
    {
	convert(n->right,flag,i);
	convert(n->left,flag,i);
	if(flag == i)
	{   if(i == 1){
	    n->left=NULL;
	    n->right=temp;
	    temp->left=n;
	    cout<<temp->a<<"->"<<n->a<<endl;
	    }
	    else if(temp == NULL){
		 n->right = NULL;
		 temp = n;
		 end = temp;
		 clrscr();
		 cout<<"\nnull->"<<temp->a<<endl;
	     }
	     else{
		 cout<<temp->a<<"->"<<n->a<<endl;
		 temp->left = n;
		 n->right = temp;
		 temp = n;
	     }
	}
    }
}
/*Traverses the list that has been created out og the given tree */
void TraverseList(node *n){
    if(n!=NULL){
    cout<<n->a<<" ";
    TraverseList(n->right);
    }
}
void main()
{
    clrscr();
    n = NULL;
    int i=0,no=0,j=0;
    cout<<"how many values do you want to enter:";
    cin>>no;
    int value=0;
    while(i<no){
	cin>>value;
	enterIntoTree(value);
	i++;
    }
    for(j=no;j>0;j--)
	convert(n,0,j);
   // clrscr();
   cout<<"\n\n";
    TraverseList(n);
    delete(n);
    getch();
}
