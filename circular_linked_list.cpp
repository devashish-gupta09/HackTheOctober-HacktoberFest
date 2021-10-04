#include<iostream>
#include<malloc.h>


using namespace std;

struct node
{
  int roll_no;
  char name[10];
  struct node *next;
};
struct node *head,*tail;
int leng=0;
void create(){
	struct node *newNode,*temp;
	char choice='y';
	head=NULL;
	while(choice=='y'){
		newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the Roll number:"<<endl;
	cin>>newNode->roll_no;
	cout<<"Enter Name:"<<endl;
	cin>>newNode->name;
	newNode->next=NULL;
	if(head==NULL){
		head=temp=newNode;
		leng++;
	}
	else{
		temp->next=newNode;
		temp=temp->next;
		leng++;
	}
	temp->next=head;
	cout<<"Do you want to enter more details?(y/n)"<<endl;
	cin>>choice;
	}
}


void insert_beg(){
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the Roll number to insert in the beginning:"<<endl;
	cin>>newNode->roll_no;
	cout<<"Enter Name:"<<endl;
	cin>>newNode->name;
	newNode->next=NULL;
	if (tail==NULL){
		tail=newNode;
		tail->next=newNode;
	}
	else{
		newNode->next=tail->next;
		tail->next=newNode;
	}
}
void insert_end(){
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the Roll number to insert at the end:"<<endl;
	cin>>newNode->roll_no;
	cout<<"Enter Name:"<<endl;
	cin>>newNode->name;
	newNode->next=NULL;
	if (tail==NULL){
		tail=newNode;
		tail->next=newNode;
		leng++;
	}
	else{
		newNode->next=tail->next;
		tail->next=newNode;
		tail=newNode;
		leng++;
	}
}
void insert_pos(){
	struct node *newNode,*temp;
	int pos,i=1;
	cout<<"Enter position at which a new record is to be inserted"<<endl;
	cin>>pos;

	if(pos<=0 || pos>leng)
	{
		cout<<"INVALID POSITION"<<endl;
	}
	else if (pos==1){
		insert_beg();
	}
	else{
		newNode=(struct node *)malloc(sizeof(struct node));
		cout<<"Enter the Roll number to insert at the end:"<<endl;
		cin>>newNode->roll_no;
		cout<<"Enter Name:"<<endl;
		cin>>newNode->name;
		newNode->next=NULL;
		temp=tail->next;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		newNode->next=temp->next;
		temp->next=newNode;
		}
	}

void del_beg(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        cout<<"List is Empty"<<endl;
    }
    else {
        head=head->next;
        free(temp);
        leng--;
    }
}
void del_end()
{	struct node *temp, *prevnode;
	while(temp->next!=NULL)  {
		prevnode=temp;
		temp=temp->next;
	}
	if(temp==head)
	{ head=NULL;
	}
	else{
		prevnode->next=NULL;
	}free(temp);
	leng--;
}
void del_pos(){
	struct node *temp,*newNode;
	int pos,i=1;
	temp=head;
	cout<<"Enter the position to delete the record"<<endl;
	cin>>pos;
	while(i<pos-1){
	temp=temp->next;
	i++;
	}
	newNode=temp->next;
	temp->next=newNode->next;
	free(newNode);
	leng--;
}
void display(){
	struct node *temp;
	if (head==NULL){
		cout<<"List is Empty"<<endl;
	}
	else{
		temp=head;
	}
	while(temp->next!=head){
		cout<<"Roll Number:  "<<temp->roll_no<<"        Name:  "<<temp->name<<endl<<endl<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		temp=temp->next;
	}
	cout<<"Roll Number:  "<<temp->roll_no<<"        Name:  "<<temp->name<<endl<<endl<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
}
int main(){
	int a;
menu:
	cout <<"                               Student  Database"<<endl<<endl;
	cout<<"1. Add Student "<<endl;
	cout<<"2. Delete Student "<<endl;
	cout<<"3. Insert Student"<<endl;
	cout<<"4. Display List"<<endl;
	cout<<"5. Total Number of records"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"Enter your choice: "<<endl;
	cin>>a;

switch(a){
	case 1:
	    system("cls");
    	create();
    	goto menu;
    	break;
    case 2:
	    system("cls");
	    int b;
dlt:
	    	cout <<"                               Delete Record"<<endl<<endl;
            cout<<"1. Delete from Beginning "<<endl;
            cout<<"2. Delete from End "<<endl;
            cout<<"3. Delete from position"<<endl;
            cout<<"4. Main Menu"<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>b;
        switch(b){
            case 1:
                system("cls");
                del_beg();
                getchar();
                goto dlt;
                break;
            case 2:
                system("cls");
                del_end();
                getchar();
                goto dlt;
                break;
            case 3:
                system("cls");
                del_pos();
                getchar();
                goto dlt;
                break;
            case 4:
                system("cls");
                goto menu;
                break;

        }
        case 3:
	    system("cls");
	    int c;
inst:
	    	cout <<"                               Insert Record"<<endl<<endl;
            cout<<"1. Insert in the Beginning "<<endl;
            cout<<"2. Insert at the End "<<endl;
            cout<<"3. Insert at position"<<endl;
            cout<<"4. Main Menu"<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>c;
        switch(c){
            case 1:
                system("cls");
                insert_beg();
                getchar();
                goto inst;
                break;
            case 2:
                system("cls");
                insert_end();
                getchar();
                goto inst;;
                break;
            case 3:
                system("cls");
                insert_pos();
                getchar();
                goto inst;
                break;
            case 4:
                system("cls");
                goto menu;
                break;

        }

    case 4:
    	system("cls");
		display();
		goto menu;
		break;
    case 5:
		system ("cls");
		cout<<"------------------------------------------------------------------"<<endl<<endl;
		cout<<"             Total  Number  of  Records are :  "<<leng<<endl<<endl;
		cout<<"------------------------------------------------------------------"<<endl<<endl;
		getchar();
		goto menu;
	case 6:
		system ("cls");
		cout<<"              Thank You "<<endl;
	    exit(0);
		getchar();
	}
}
