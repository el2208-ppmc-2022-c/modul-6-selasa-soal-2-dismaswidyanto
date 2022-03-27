/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : -
*Hari dan Tanggal : Selasa, 29 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi variabel dan tipe data bentukan
struct node{
	int nilai;
	char NIM[9];
	struct node *next;
};

struct node *linkedList1Head;
struct node *current;
int N;

// Fungsi: appendNode()
// Deskripsi: Menambahkan (append) node baru ke sebuah linked list dengan head **head.
// Parameter:
//     **head : pointer dari pointer header sebuah linked list
//     *nilai : input yang akan menjadi data nilai dari node baru
//     *NIM : input yang akan menjadi data NIM dari node baru
void appendNode(struct node **head, int *nilai, char *NIM){
	struct node *linkedListPointer;
	struct node *newNode;

	// Mengalokasikan blok memori baru
	newNode = malloc(sizeof(struct node));

	// Memindahkan nilai variabel nilai dan NIM ke blok memori baru
	newNode->nilai = *nilai;
	strcpy(newNode->NIM, NIM);
	newNode->next = NULL;

	// Apabila linked list belum terisi data apapun
	if(*head == NULL){
		*head = newNode;
	}
	//Apabila linked list sudah terisi data
	else{
		linkedListPointer = *head;
		while(linkedListPointer->next != NULL){
			linkedListPointer = linkedListPointer->next;
		}
		linkedListPointer->next = newNode;
	}
}

// Fungsi: freelinkedList()
// Deskripsi: Dealokasi memori linked list
// Parameter:
//     **head : pointer dari pointer header sebuah linked list
void freeLinkedList(struct node **head){
	struct node *linkedListPointer;

	// Dealokasi setiap blok memori linked list dengan iterasi sampai linked list kosong
	while(*head != NULL){
		linkedListPointer = *head;
		*head = (*head)->next;
		free(linkedListPointer);
	}
}

// Fungsi: inputData()
// Deskripsi: Untuk menerima masukan user
void inputData(){
	char NIMTemp[9];
	int nilaiTemp;
	int i = 1;

	printf("Masukkan NIM mahasiswa ke-%d:", i);
	scanf("%s", NIMTemp); 

	while(strcmp(NIMTemp,"99999999") != 0){   
		printf("Masukkan nilai mahasiswa ke-%d:", i);
		scanf("%d", &nilaiTemp); 
		appendNode(&linkedList1Head, &nilaiTemp, NIMTemp);
		i++;
		printf("Masukkan NIM mahasiswa ke-%d:", i);
		scanf("%s", NIMTemp);
	}
}

// Fungsi: sortData()
// Deskripsi: Mengurutkan linked list **head dari urutan nilai tertinggi ke nilai terendah
// Parameter:
//     **head : pointer dari pointer header sebuah linked list
void sortData(struct node **head){
	//Algoritma bubble sort digunakan untuk mengurutkan data
	struct node *linkedListPointer;
	int size = 0;
	struct node *swapTemp;

	// Mencari banyaknya node dari linked list
	linkedListPointer = *head;
	while(linkedListPointer != NULL){
		size++;
		linkedListPointer = linkedListPointer->next;    
	}

	// Algoritma bubble sort
	// Intinya membandingkan data yang bersebelahan. Kalo data EXAMPLE[n] < EXAMPLE[n+1], maka akan diswap.
	// Pada akhirnya, data dengan nilai terkecil akan berada di node paling akhir
	for(int i=size-1; i>0; i--){
		for(int j = 0; j<i; j++){
			if(j == 0){
				if((*head)->nilai < (*head)->next->nilai){
					// Ini ngeswap
					swapTemp = *head;
					*head = (*head)->next;
					swapTemp->next = (*head)->next;
					(*head)->next = swapTemp;
				}
				linkedListPointer = *head;
			}
			else{
				if(linkedListPointer->next->nilai < linkedListPointer->next->next->nilai){
					// Ini juga ngeswap
					swapTemp = linkedListPointer->next;
					linkedListPointer->next = linkedListPointer->next->next;
					swapTemp->next = linkedListPointer->next->next;
					linkedListPointer->next->next = swapTemp;
					
				}
				linkedListPointer = linkedListPointer->next;
			}
			
		}
	}
}

// Fungsi: printData()
// Deskripsi: Mencetak linked list
// Parameter:
//     **head : pointer dari pointer header sebuah linked list
void printData(struct node **head){
	struct node *linkedListPointer;
	
	linkedListPointer = *head;
	while(linkedListPointer != NULL){
		printf("%s, %d\n", linkedListPointer->NIM, linkedListPointer->nilai);
		linkedListPointer = linkedListPointer->next;
	}
}

// Fungsi: main()
// Deskripsi: Program utama
int main(){
	// User memasukkan data terlebih dahulu dan program menyimpannya ke dalam linked list
	inputData();

	// Mengurutkan data yang dimasukkan user
	sortData(&linkedList1Head);

	// Mencetak data yang telah diurutkan
	printData(&linkedList1Head);

	// Mendealokasikan memori linked list
	freeLinkedList(&linkedList1Head);

	return 0;
}
