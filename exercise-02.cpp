/*
 * Author	: Prayudha Adhitia Libramawan
 * NPM		: 140810180008
 * Kelas	: B
 * Tanggal	: 16/04/2019
 * Deskripsi: Program ini dapat Represent below data in doubly linked list.
*/

#include <iostream>
using namespace std;

struct ureData{
	char data[10];
	ureData* next;
    ureData* prev;
};

typedef ureData* pointer;
typedef pointer List;

void createList (List& head){
	head=NULL;
}

void createNode (pointer& pNew){
	pNew=new ureData;
	cout << "data: "; cin >> pNew->data;
	pNew->next=NULL;
    pNew->prev=NULL;
}

void insertFirst (List& head, pointer pNew){
	if (head==NULL){
        head=pNew;
    }
	else{
		pNew->next=head;
        head->prev=pNew;
		head=pNew;
	}
}

void insertLast (List& head, pointer pNew){
	pointer last;
	last=head;
	if (head==NULL){
        head=pNew;
    }
	else{
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pNew;
        pNew->prev=last;
	}
}

void deleteFirst (List& head, pointer& pDel){
	if (head==NULL){
		pDel==NULL;
		cout << "List is empty." << endl;
	}
	else if (head->next==NULL){
		pDel=head;
		head=NULL;
	}
	else{
		pDel=head;
		head=head->next;
        head->prev=NULL;
		pDel->next=NULL;
	}
}

void deleteLast (List& head, pointer& pDel){
	pointer last;
	last=head;
	if (head==NULL){
		pDel=NULL;
		cout << "List is empty." << endl;
	}
	else if (head->next==NULL){
		pDel=head;
		head=NULL;
	}
	else{
		while (last->next!=NULL){
			last=last->next;
		}
		pDel=last;
        last->prev->next=NULL;
		pDel->prev=NULL;
	}
}

void traversal(List head){
	if(head!=NULL){
		pointer trav=head;
		while(trav!=NULL){
			cout<<"'"<<trav->data<<"'";
			if(trav->next!=NULL){
				cout<<" <--> ";
			}
			trav=trav->next;
		}
	}else{
		cout<<"Empty List!"<<endl;
	}
}

main(){
	pointer p, pDel;
	List soal2;
	int opt;
	char pil;
	
	createList(soal2);
	
	do{
		system("cls");
		cout << "Menu:\n"
			 << "1. Insert First\n"
			 << "2. Insert Last\n"
			 << "3. Delete First\n"
			 << "4. Delete Last\n"
			 << "5. Traversal\n"
			 << "Option: "; cin >> opt;
			 
		switch(opt)
		{
			case 1:  createNode(p);
					 insertFirst(soal2,p);
					 break;
			case 2:  createNode(p);
					 insertLast(soal2,p);
					 break;
			case 3:  deleteFirst(soal2,pDel);
					 break;
			case 4:  deleteLast(soal2,pDel);
					 break;
			case 5:  traversal(soal2);
					 break;
			default: cout << "Your option is not valid." << endl;
					 break;
		}
		cout << "\nDo you want to still edit this list? (Y/N) "; cin >> pil;
	}while (pil=='Y' || pil=='y');
}