#include <iostream>
#include <cstring>

using namespace std;

typedef struct typenode *typeptr;
typedef char typechar;
struct typenode{
	typechar karakter;
	typeptr next;
};

typeptr head,tail;
int l;

void mulai();
void moveCharacter(char kata[], int pindah);
void cetaklist();

int main()
{
	int pindah;string kata; 
	mulai();
	cout << "pindah : "; cin >> pindah;
	cout << "Kata : "; cin >> kata;
	l = kata.length();
	char str[l];
	strcpy(str,kata.c_str());
	moveCharacter(str,pindah);
	cetaklist();
}

void mulai(){
	typeptr newList;
	head = new typenode();
	tail = new typenode();
	head = NULL;
	tail = NULL;
}

void moveCharacter(char kata[], int pindah){
	typeptr Node,temp,temp1;
	int i = 0;
	while(i < l){
		Node = new typenode();
		Node->karakter = kata[i];
		if(head == NULL){
			head = Node;
			tail = Node;
		}else{
			tail -> next = Node;
		}

		tail = Node;
		tail -> next = NULL;
		i++;
		// cout << Node->karakter << " ";
	}

	int move = 0;
	while(move < pindah){
		temp = head;
		temp1 = tail;
		temp1->next = head;
		head = head->next;
		tail = temp;
		tail->next = NULL;
		move++;
	}
}

void cetaklist(){
	typeptr bantu;
	bantu = head;

	while(bantu != NULL){
		cout << bantu -> karakter << " ";
		bantu = bantu -> next;
	}
}