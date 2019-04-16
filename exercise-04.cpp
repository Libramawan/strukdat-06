/*
 * Author	: Prayudha Adhitia Libramawan
 * NPM		: 140810180008
 * Kelas	: B
 * Tanggal	: 16/04/2019
 * Deskripsi: Program ini dapat Represent Phone book data in a multi linked list
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Contact{
	char nama[10];
	char phone[12];
	Contact *next;
};
struct Index{
	char index;
	Contact *nextContact;
    Index *next;
};

typedef Index* pointerIndex;
typedef Contact* pointerContact;
typedef pointerIndex list;

void createList(list& head){
	head=NULL;
}

void createIndex(pointerIndex& newIndex, char index){
	newIndex=new Index;
	newIndex->index=index;
	newIndex->next=NULL;
	newIndex->nextContact=NULL;
}

void createContact(pointerContact& newContact){
	newContact=new Contact;
	cout<<"Name\t: ";cin.ignore();cin.getline(newContact->nama,10);
	cout<<"Number\t: ";cin>>newContact->phone;
	newContact->next=NULL;
}

void insertLastIndex(list& head, pointerIndex newIndex){
	if(head==NULL){
		head=newIndex;
	}else{
		Index *last=head;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=newIndex;
	}
}

void createListIndex(list &head){
	pointerIndex newIndex;
	createList(head);
	for(char index='A'; index!='Z'+1; index++){
		createIndex(newIndex,index);
		insertLastIndex(head,newIndex);
	}
}

void insertLastContact(pointerIndex& index, pointerContact newContact){
	if(index->nextContact==NULL){
		index->nextContact=newContact;
	}else{
		Contact *last=index->nextContact;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=newContact;
	}
}

void insertContact(list& head, pointerContact newContact){
	pointerIndex idxTrav=head;
	bool isFound=0;
	while(idxTrav!=NULL){
		if(idxTrav->index==toupper(newContact->nama[0])){
			break;
		}
		idxTrav=idxTrav->next;
	}
	insertLastContact(idxTrav,newContact);
}

void deleteContact(list& head, pointerContact& delContact){
	char nama[10];
	pointerIndex idxSrc=head;
	bool isFound=0;
	cout<<"The Contact Name that you want to DELETE : ";cin.ignore();cin.getline(nama,10);
	while(idxSrc!=NULL && !isFound){
		if(idxSrc->index==toupper(nama[0])){
			isFound=1;
			break;
		}
		idxSrc=idxSrc->next;
	}
	Contact *ctcSrc=idxSrc->nextContact;
	if(ctcSrc==NULL){
		cout<<"Name not Found!"<<endl;
	}else{
		Contact *prev=NULL;
		while(ctcSrc!=NULL){
			if(strcmp(ctcSrc->nama,nama)==0){
				isFound=1;
				if(ctcSrc==idxSrc->nextContact){
					delContact=ctcSrc;
					idxSrc->nextContact=ctcSrc->next;
					delContact->next=NULL;
				}else if(ctcSrc->next==NULL){
					prev->next=NULL;
				}else{
					delContact=ctcSrc;
					prev->next=ctcSrc->next;
					delContact->next=NULL;
				}
			}
			prev=ctcSrc;
			ctcSrc=ctcSrc->next;
		}
	}
	if(!isFound){
		cout<<"Name not Found!"<<endl;
	}else{
		cout<<"Delete Succeeded!"<<endl;
    }
}

void updateContact(list& head){
	char nama[10];
	pointerIndex idxSrc=head;
	bool isFound=0;
	cout<<"The Contact Name that you want to UPDATE : ";cin.ignore();cin.getline(nama,10);
	while(idxSrc!=NULL && !isFound){
		if(idxSrc->index==toupper(nama[0])){
			isFound=1;
			break;
		}
		idxSrc=idxSrc->next;
	}
	Contact *ctcSrc=idxSrc->nextContact;
	if(ctcSrc==NULL){
		cout<<"Name not Found!"<<endl;
	}else{
		while(ctcSrc!=NULL){
			if(strcmp(ctcSrc->nama,nama)==0){
				isFound=1;
				cout<<"New Number : ";
				cin>>ctcSrc->phone;
			}
			ctcSrc=ctcSrc->next;
		}
	}
	if(!isFound){
		cout<<"Name not Found!"<<endl;
	}else{
		cout<<"Update Succeeded!"<<endl;
	}
}

void traversal(list head){
	pointerIndex idxTrav=head;
	cout<<endl;
	bool found=0;
	while(idxTrav!=NULL){
		Contact *ctcTrav=idxTrav->nextContact;
		if(idxTrav->nextContact!=NULL){
			cout<<"|- "<<idxTrav->index<<endl;
			found=1;
		}
		while(ctcTrav!=NULL){
			cout<<"\t|- "<<ctcTrav->nama<<" / "<<ctcTrav->phone<<endl;
			ctcTrav=ctcTrav->next;
		}
		idxTrav=idxTrav->next;
	}
	if(!found){
		cout<<"Empty Phone book List."<<endl;
	}
}

main(){
	pointerContact contact;
    list soal4=NULL;
	int opt; char pil;
	createList(soal4);
	createListIndex(soal4);
	do{
		system("cls");
		cout << "Menu:\n"
			 << "1. Insert Contact\n"
			 << "2. Delete Contact\n"
			 << "3. Update Contact\n"
			 << "4. Traversal\n"
			 << "Option: ";
		do{
			cin>>opt;
		}while(opt<1||opt>4);
		switch(opt){
			case 1:
				createContact(contact);
				insertContact(soal4,contact);
				break;
			case 2:
				deleteContact(soal4,contact);
				break;
			case 3:
				updateContact(soal4);
				break;
			case 4:
				traversal(soal4);
				break;
		}
		cout << "\nDo you want to still edit this Phone Book list? (Y/N) "; 
		do{
			cin>>pil;
		}while(pil!='Y'&&pil!='y'&&pil!='N'&&pil!='n');
	}while(pil=='Y'||pil=='y');
}

