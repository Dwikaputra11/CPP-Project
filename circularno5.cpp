#include <bits/stdc++.h>
using namespace std;

typedef struct typenode *typeptr;
#define allocationNode (typenode*)malloc(sizeof(typenode))
#define enter cout << "\n"
struct typenode{
	int jmlNode;
	string nim;
	string nama;
	int nilai;
	typeptr next;
};

int sumNode = 0;
typeptr head;

void createNewList();
void sisipnode(string nim, string nama, int nilai);
void display();

int main()
{
	int n;

	createNewList();
	cout << "Data Nilai (NIM, Nama, Nilai) :\n";
	sisipnode("12718", "akbar", 70);
	sisipnode("12719", "doni", 75);
	sisipnode("12720", "monic", 75);
	sisipnode("12721", "dela", 80);
	display();

	return 0;
}

void createNewList(){
	typeptr newList;
	head = new typenode();
	head->jmlNode = sumNode;
	head->next = head;
}


void sisipnode(string nim, string nama, int nilai){
	typeptr newNode,temp;
	newNode = new typenode();
	newNode->nim = nim;
	newNode->nama = nama;
	newNode->nilai = nilai;
	sumNode++;

	if(head->next == head){
		newNode->next = head;
		head-> next = newNode;
		head-> jmlNode = sumNode;
	}else{
		if(head->next->nim >= nim){
			newNode->next = head->next;
			head-> next = newNode;
		}else{
			temp = head;
			while(temp -> next != head && temp->next->nim <= nim)
				temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
		head->jmlNode = sumNode;
	}
}

void display(){
	typeptr temp = new typenode();
	int sum = 0;
	temp = head->next;

	while(temp != head){
		cout << temp->nim << " " << temp->nama << " " << temp->nilai << "\n";
		sum += temp->nilai;
		temp = temp->next;
	}
	enter;enter;
	cout << "Rata-rata Nilai : " << sum/head->jmlNode;
	enter;
}