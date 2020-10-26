#include <iostream>
#include <list>
using namespace std;

struct node 
{
    int num;                
    node *nextptr;             
}*stnode; //node defined

void makeList(int n);                 
void showList();
void searchList(int item, int n);
 
int main()
{
    int n,num,pil,item;
		
    cout<<"Masukkan jumlah node : ";
    cin>>n;
    makeList(n);

    cout<<"\nData Linked list : \n";		
    showList();

    cout<<"\nMenu: \n";
    cout<<"1. Hapus / Delete \n";
    cout<<"2. Tambah / Insert \n";
    cout<<"3. Cari / Search \n";
    cout<<"Pilihan :";
    cin>>pil;

    return 0;
}
void makeList(int n) //function to create linked list.
{
    struct node *frntNode, *tmp;
    int num, i;
 
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL)        
    {
        cout<<" Memory can not be allocated";
    }
    else
    {
        list<int> myList;

        cout<<"Masukkan data untuk node 1: ";
        cin>>num;
        stnode-> num = num;      
        stnode-> nextptr = NULL; //Links the address field to NULL
        tmp = stnode;
 
        for(i=2; i<=n; i++)
        {
            frntNode = (struct node *)malloc(sizeof(struct node)); 
 

            if(frntNode == NULL) //If frntnode is null no memory cannot be allotted
            {
                cout<<"Memory can not be allocated";
                break;
            }
            else
            {
                cout<<"Masukkan data untuk node "<<i<<": "; // Entering data in nodes.
                cin>>num;
                frntNode->num = num;         
                frntNode->nextptr = NULL;    
                tmp->nextptr = frntNode;     
                tmp = tmp->nextptr;
            }
        }
    }
} 


void showList() //function to print linked list
{
    struct node *tmp;
    if(stnode == NULL)
    {
        cout<<"No data found in the list";
    }
    else
    {
        tmp = stnode;
        cout<<"myList : ";
        while(tmp != NULL)
        {
            cout<< " " << tmp->num;         
            tmp = tmp->nextptr;         
        }
    }
} 
void searchList(int item , int n) //function to search element in the linked list 
{  
    struct node *tmp;  
    int i=0,flag;  
    tmp = stnode;   
    if(stnode == NULL)  
    {  
        cout<<"\nEmpty List\n";  
    }  
    else  
    {   
        while (tmp!=NULL)  
        {  
            if(tmp->num == item)  //If element is present in the list
            {  
                cout<<"Item found at location: "<<(i+1); flag=0; } else { flag++; } i++; tmp = tmp -> nextptr;  
        }  
        if(flag==n) //If element is not present in the list
        {  
            cout<<"Item not found\n";  
        }  
    }  
}