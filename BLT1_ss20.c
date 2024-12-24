#include <stdio.h>
#include <string.h>

typedef struct {
	int bookId;
	char bookName[50];
	char author[30];
	float price;
	char kind[20];
} Book;

void addInfo( Book book[], int *n );
void show( Book book[], int n);
void addItem( Book book[], int *n );
void updateItem( Book book[], int n);
void delItem( Book book[], int *n );
void sort( Book book[], int n );
void search( Book book[], int n );


int main(){
	Book book[100];
	int choice, check = -1, n = 0;
	do{
		printf("\n*********Menu*********");
		printf("\n1. Nhap so luong va thong tin sach ");
		printf("\n2. Hien thi thong tin sach ");
		printf("\n3. Them sach vao vi tri ");
		printf("\n4. Xoa sach theo ma sach ");
		printf("\n5. Cap nhat thong tin theo ma sach ");
		printf("\n6. Sap xep sach theo gia(tang/giam) ");
		printf("\n7. Tim kiem sach theo ten ");
		printf("\n8. Thoat ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice );
		fflush(stdin);
		
		switch( choice){
			case 1:{
				check = 1;
				addInfo(book, &n);
				break;
			}
			case 2:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					show(book, n);
				}
				break;
			}
			case 3:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					addItem(book, &n);
				}
				break;
			}
			case 4:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					delItem(book, &n);
				}
				break;
			}
			case 5:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					updateItem(book, n);
				}
				break;
			}
			case 6:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sort(book, n);
				}
				break;
			}
			case 7:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					search(book, n);
				}
				break;
			}
			case 8:{
				printf("\nThoat!!! ");
				break;
			}
			default:{
				printf("\nVui long chon dung menu(1-8)");
				break;
			}
		}
	}while( choice!=8);

	return 0;
}

void addInfo( Book book[], int *n ){
	printf("\nNhap so luong sach: ");
	scanf("%d", n);
	fflush(stdin);
	
	for ( int i = 0; i< *n ; i++){
		book[i].bookId = i+1 ;
		printf("\nNhap thong tin sach thu %d: ", i+1);
		printf("\nNhap ten sach: ");
		fgets(book[i].bookName , 50, stdin);
		book[i].bookName[strlen(book[i].bookName) -1] = '\0' ;
		
		printf("Nhap tac gia: ");
		fgets(book[i].author , 30, stdin);
		book[i].author[strlen(book[i].author) -1] = '\0' ;
		
		printf("Nhap the loai: ");
		fgets(book[i].kind , 30, stdin);
		book[i].kind[strlen(book[i].kind) -1] = '\0' ;
		
		printf("Nhap gia tien: ");
		scanf("%f", &book[i].price);
		fflush(stdin);
	}
}

void show( Book book[], int n){
	printf("\nDanh sach: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n %d. %s", book[i].bookId, book[i].bookName);
		printf("\n Tac gia: %s", book[i].author);
		printf("\n The loai: %s", book[i].kind);
		printf("\n Gia tien: %.2f", book[i].price);
	}
}

void addItem( Book book[], int *n ){
	int index;
	do{
		printf("\n Nhap vi tri muon them(1-%d): ", (*n)+1);
		scanf("%d", &index);
	}while(index<1 || index> (*n)+1);
	fflush(stdin);
	
	for ( int i = *n; i>= index ; i--){
		book[i] = book[i-1];
		book[i].bookId  = book[i-1].bookId + 1 ;
	}
	
	book[index-1].bookId = index ;
	printf("\nNhap ten sach: ");
	fgets(book[index-1].bookName , 50, stdin);
	book[index-1].bookName[strlen(book[index-1].bookName) -1] = '\0' ;
	
	printf("Nhap tac gia: ");
	fgets(book[index-1].author , 30, stdin);
	book[index-1].author[strlen(book[index-1].author) -1] = '\0' ;
	
	printf("Nhap the loai: ");
	fgets(book[index-1].kind , 30, stdin);
	book[index-1].kind[strlen(book[index-1].kind) -1] = '\0' ;
	
	printf("Nhap gia tien: ");
	scanf("%f", &book[index-1].price);
	fflush(stdin);
	
	(*n)++;	
	printf("\nDanh sach ket qua: ");
	for ( int i = 0; i< *n ; i++){
		printf("\n\n %d. %s", book[i].bookId, book[i].bookName);
		printf("\n Tac gia: %s", book[i].author);
		printf("\n The loai: %s", book[i].kind);
		printf("\n Gia tien: %.2f", book[i].price);
	}
}

void updateItem( Book book[], int n ){
	int index, input, check = -1;
	printf("\n Nhap ma sach muon sua: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< n; i++){
		if ( book[i].bookId == input ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == -1 ){
		printf("\n Khong co ma sach can sua!");
	}else{
		printf("\nNhap ten sach: ");
		fgets(book[index].bookName , 50, stdin);
		book[index].bookName[strlen(book[index].bookName) -1] = '\0' ;
		
		printf("Nhap tac gia: ");
		fgets(book[index].author , 30, stdin);
		book[index].author[strlen(book[index].author) -1] = '\0' ;
		
		printf("Nhap the loai: ");
		fgets(book[index].kind , 30, stdin);
		book[index].kind[strlen(book[index].kind) -1] = '\0' ;
		
		printf("Nhap gia tien: ");
		scanf("%f", &book[index].price);
		fflush(stdin);
			
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i<n ; i++){
			printf("\n\n %d. %s", book[i].bookId, book[i].bookName);
			printf("\n Tac gia: %s", book[i].author);
			printf("\n The loai: %s", book[i].kind);
			printf("\n Gia tien: %.2f", book[i].price);
		}
	}
}

void delItem( Book book[], int *n ){
	int index, input, check = -1;
	printf("\n Nhap ma sach muon xoa: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< *n; i++){
		if ( book[i].bookId == input ){
			index = i;
			check = 1;
			break;
		} 
	}
	
	if ( check == -1 ){
		printf("\n Khong co ma sach can sua!");
	}else {
		for ( int i = index ; i < *n ; i++){
			book[i].bookId  = book[i+1].bookId - 1 ;
			book[i] = book[i+1];
		}
		
		(*n)--;	
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i< *n ; i++){
			printf("\n\n %d. %s", book[i].bookId, book[i].bookName);
			printf("\n Tac gia: %s", book[i].author);
			printf("\n The loai: %s", book[i].kind);
			printf("\n Gia tien: %.2f", book[i].price);
		}
	}
}

void sort( Book book[], int n){
	char choice;
	do{
		printf("\na. Gia tang dan");
		printf("\nb. Gia giam dan");
		printf("\nLua chon cua ban: ");
		scanf("%c", &choice );
		fflush(stdin);
	}while( choice != 'a' && choice != 'b' );
	fflush(stdin);
	
	if ( choice == 'a' ){
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( book[j].price > book[j+1].price  ){
					Book temp = book[j];
	                book[j] = book[j+1];
	                book[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( book[j].price < book[j+1].price  ){
					Book temp = book[j];
	                book[j] = book[j+1];
	                book[j+1] = temp;
				}
			}
		}
	}
	
	printf("\nDanh sach: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n %d. %s", book[i].bookId, book[i].bookName);
		printf("\n Tac gia: %s", book[i].author);
		printf("\n The loai: %s", book[i].kind);
		printf("\n Gia tien: %.2f", book[i].price);
	}
}

void search( Book book[], int n){
	char input[50];
	int count = 0;
	
	fflush(stdin);
	printf("\nNhap ten sach can tim: ");
	
	fgets( input, 50, stdin);
	input[strlen(input) -1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strstr(book[i].bookName, input) != NULL ){
			count = 1;
			printf("\nKet qua tim kiem: ");
			printf("\n\n %d. %s", book[i].bookId, book[i].bookName);
			printf("\n Tac gia: %s", book[i].author);
			printf("\n The loai: %s", book[i].kind);
			printf("\n Gia tien: %.2f", book[i].price);
		}
	}

	if ( count == 0 ) printf("\n Khong tim thay sach!");
}



