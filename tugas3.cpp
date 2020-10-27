//  Anggota Kelompok :
//  1. Felipe    191402086
//  2. Christina 191402089
//  Implementasi Linked list


#include <iostream>

using namespace std;

struct node
{
    int num;
    node *nextptr;
} * stnode; //node defined

void makeList(int n);
void showList();
void searchList(int item, int n);
void insertPos(node** current, int pos, int data);
void deletePos(node **head_ref, int position);
int n;
int main()
{
    int num, pil, item, find, pos, data;
    bool status = true;

    cout << "Masukkan jumlah node : ";
    cin >> n;
    makeList(n);
    while (status)
    {
        cout << "\nMenu: \n";
        cout << "1. Tampilkan / Show \n";
        cout << "2. Hapus / Delete \n";
        cout << "3. Tambah / Insert \n";
        cout << "4. Cari / Search \n";
        cout << "5. Kembali \n";
        cout << "Pilihan :";
        cin >> pil;
        switch (pil)
        {
        case 1:
            cout << "\nData Linked list  \n";
            showList();
            break;
        case 2:
        cout << "Posisi data yang akan dihapus : ";
        cin >> pos;
        deletePos(&stnode, pos-1);
            break;
        case 3:
        cout << "Posisi data yang ingin di insert : ";
        cin >> pos;
        cout << "Data yang ingin di insert : ";
        cin >> data;
        insertPos(&stnode, pos, data);
            break;
        case 4:
            cout << "Masukkan angka yang ingin dicari dalam linked list : ";
            cin >> find;
            searchList(find, n);
            break;
        case 5:
            status = false;
            break;
        default:
            cout << "Pilihan anda salah !" << endl;
            break;
        }
    }
    return 0;
}

void makeList(int n) //function to create linked list.
{
    struct node *frntNode, *tmp;
    int num, i;

    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode == NULL)
    {
        cout << " Memori tidak dapat dialokasi";
    }
    else
    {
        cout << "Masukkan data untuk node 1: ";
        cin >> num;
        stnode->num = num;
        stnode->nextptr = NULL; //Links the address field to NULL
        tmp = stnode;

        for (i = 2; i <= n; i++)
        {
            frntNode = (struct node *)malloc(sizeof(struct node));

            if (frntNode == NULL) //If frntnode is null no memory cannot be allotted
            {
                cout << "Memori tidak dapat dialokasi";
                break;
            }
            else
            {
                cout << "Masukkan data untuk node " << i << ": "; // Entering data in nodes.
                cin >> num;
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
    if (stnode == NULL)
    {
        cout << "Tidak ada data dalam list";
    }
    else
    {
        tmp = stnode;
        cout << "myList : ";
        while (tmp != NULL)
        {
            cout << " " << tmp->num;
            tmp = tmp->nextptr;
        }
        cout << endl;
    }
}
void searchList(int item, int n) //function to search element in the linked list
{
    struct node *tmp;
    int i = 0, flag = 0;
    tmp = stnode;
    if (stnode == NULL)
    {
        cout << "\nList Kosong\n";
    }
    else
    {
        while (tmp != NULL)
        {
            if (tmp->num == item) //If element is present in the list
            {
                cout << "Item ditemukan pada posisi ke-" << (i + 1);
                flag = 0;
            }
            else
            {
                flag++;
            }
            i++;
            tmp = tmp->nextptr;
        }
        
        if (flag == n) //If element is not present in the list
        {
            cout << "Item tidak ditemukan\n";
        }
    }
}

node* getNode(int data) 
{ 
    // allocating space 
    node* newNode = new node(); 
  
    // inserting the required data 
    newNode->num = data; 
    newNode->nextptr = NULL; 
    return newNode; 
} 
  
// function to insert a Node at required position 
void insertPos(node** current, int pos, int data) 
{ 
    // This condition to check whether the 
    // position given is valid or not. 
    if (pos < 1 || pos > n + 1) 
        cout << "Invalid position!" << endl; 
    else { 
  
        // Keep looping until the pos is zero 
        while (pos--) { 
  
            if (pos == 0) { 
  
                // adding Node at required position 
                node* temp = getNode(data); 
  
                // Making the new Node to point to  
                // the old Node at the same position 
                temp->nextptr = *current; 
  
                // Changing the pointer of the Node previous  
                // to the old Node to point to the new Node 
                *current = temp; 
            } 
            else
              // Assign double pointer variable to point to the  
              // pointer pointing to the address of next Node  
              current = &(*current)->nextptr; 
        } 
        n++; 
    } 
} 

void deletePos(node **head_ref, int position) 
{ 
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   struct node* temp = *head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        *head_ref = temp->nextptr;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->nextptr; 
  
    // If position is more than number of nodes 
    if (temp == NULL || temp->nextptr == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct node *next = temp->nextptr->nextptr; 
  
    // Unlink the node from linked list 
    free(temp->nextptr);  // Free memory 
  
    temp->nextptr = next;  // Unlink the deleted node from list 
} 