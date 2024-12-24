#include <stdio.h>
#include <string.h>

typedef struct {
	int itemId;
	char itemName[50];
	float priceIn;
	float priceOut;
	int quantity;
} Item;

void addProd( Item item[], int *n );
void show( Item item[], int n);
void addItem( Item item[], int *n, float *income);
void updateItem( Item item[], int n);
void sort( Item item[], int n );
void search( Item item[], int n );
void sell( Item item[], int n, float *income );
void revenue( float income );

int main(){
	Item item[100];
	int choice, check = -1, n = 0;
	float income = 0;
	
	do{
		printf("\n\n------------Menu------------");
		printf("\n1. Nhap so luong va thong tin san pham ");
		printf("\n2. Hien thi danh sach san pham ");
		printf("\n3. Nhap san pham ");
		printf("\n4. Cap nhat thong tin san pham ");
		printf("\n5. Sap xep san pham theo gia(tang/giam) ");
		printf("\n6. Tim kiem san pham theo ten");
		printf("\n7. Ban san pham( co the nhap so luong can ban) ");
		printf("\n8. Doanh thu hien tai ");
		printf("\n9. Thoat ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice );
		fflush(stdin);
		
		switch( choice){
			case 1:{
				check = 1;
				addProd( item, &n );
				break;
			}
			case 2:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					show( item, n);
				}
				break;
			}
			case 3:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					addItem(item, &n, &income);
				}
				break;
			}
			case 4:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					updateItem(item, n);
				}
				break;
			}
			case 5:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sort(item, n);
				}
				break;
			}
			case 6:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					search(item, n);
				}
				break;
			}
			case 7:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sell(item, n, &income);
				}
				break;
			}
			case 8:{
				revenue(income);
				break;
			}
			case 9:{
				printf("\nBan chon thoat! ");
				break;
			}
			default:{
				printf("\nVui long chon dung menu(1-9)");
				break;
			}
		}
	}while( choice!=9);

	return 0;
}

void addProd( Item item[], int *n ){
	printf("\nNhap so luong san pham: ");
	scanf("%d", n);
	fflush(stdin);
	
	for ( int i = 0; i< *n ; i++){
		item[i].itemId = i+1 ;
		printf("\nNhap thong tin san pham thu %d: ", i+1);
		fflush(stdin);
		printf("\nNhap ten san pham: ");
		fgets(item[i].itemName , 50, stdin);
		item[i].itemName[strlen(item[i].itemName) -1] = '\0' ;
		
		printf("Gia nhap: ");
		scanf("%f", &item[i].priceIn);
		printf("Gia ban: ");
		scanf("%f", &item[i].priceOut);
		printf("So luong: ");
		scanf("%d", &item[i].quantity);
	}
}

void show( Item item[], int n){
	printf("\nDanh sach san pham: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n %d. %s", item[i].itemId, item[i].itemName );
		printf("\n Gia nhap: %.2f", item[i].priceIn);
		printf("\n Gia ban: %.2f", item[i].priceOut);
		printf("\n So luong: %d", item[i].quantity);
	}
}

void addItem( Item item[], int *n, float *income ){
	char input[50];
	int check = 0;
	
	printf("\nNhap thong tin san pham can them" );
	printf("\nNhap ten san pham: ");
	fgets(input, 50, stdin);
	input[strlen(input) -1] = '\0' ;
	
	for ( int i =0; i< *n; i++){
		if (  strcmp(item[i].itemName, input) == 0 ){
			check = 1;
			item[i].quantity += 1;
			*income -= item[i].priceIn  ;
			break;
		}
	}
	
	if ( check == 0 ){
		strcpy( item[*n].itemName, input );
		
		item[*n].itemId = (*n)+1;
		printf("Gia nhap: ");
		scanf("%f", &item[*n].priceIn);
		printf("Gia ban: ");
		scanf("%f", &item[*n].priceOut);
		printf("So luong: ");
		scanf("%d", &item[*n].quantity);
		
		*income -= item[*n].priceIn ;
		(*n)++ ;
	}
	
	printf("\nKet qua them san pham: ");
	for ( int i = 0; i< *n ; i++){
		printf("\n\n %d. %s", item[i].itemId, item[i].itemName );
		printf("\n Gia nhap: %.2f", item[i].priceIn);
		printf("\n Gia ban: %.2f", item[i].priceOut);
		printf("\n So luong: %d", item[i].quantity);
	}
}

void updateItem( Item item[], int n){
	int index, input, check = -1;
	printf("\n Nhap ma san pham muon sua: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< n; i++){
		if ( item[i].itemId == input ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == -1 ){
		printf("\n Khong co ma san pham can sua!");
	}else{
		printf("\nNhap ten san pham: ");
		fgets(item[index].itemName , 50, stdin);
		item[index].itemName[strlen(item[index].itemName) -1] = '\0' ;
		
		printf("Gia nhap: ");
		scanf("%f", &item[index].priceIn);
		printf("Gia ban: ");
		scanf("%f", &item[index].priceOut);
		printf("So luong: ");
		scanf("%d", &item[index].quantity);
		fflush(stdin);
			
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i< n ; i++){
			printf("\n\n %d. %s", item[i].itemId, item[i].itemName );
			printf("\n Gia nhap: %.2f", item[i].priceIn);
			printf("\n Gia ban: %.2f", item[i].priceOut);
			printf("\n So luong: %d", item[i].quantity);
		}
	}
}

void sort( Item item[], int n ){
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
				if ( item[j].priceOut > item[j+1].priceOut){
					Item temp = item[j];
	                item[j] = item[j+1];
	                item[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( item[j].priceOut < item[j+1].priceOut  ){
					Item temp = item[j];
	                item[j] = item[j+1];
	                item[j+1] = temp;
				}
			}
		}
	}
	
	printf("\nDanh sach sap xep: ");
	for ( int i = 0; i< n ; i++){
		printf("\n\n %d. %s", item[i].itemId, item[i].itemName );
		printf("\n Gia nhap: %.2f", item[i].priceIn);
		printf("\n Gia ban: %.2f", item[i].priceOut);
		printf("\n So luong: %d", item[i].quantity);
	}
}

void search( Item item[], int n ){
	char input[50];
	int count = 0;
	
	fflush(stdin);
	printf("\nNhap ten san pham can tim: ");
	fgets( input, 50, stdin);
	input[strlen(input) -1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strstr(item[i].itemName, input) != NULL ){
			count = 1;
			printf("\nKet qua tim kiem: ");
			printf("\n\n %d. %s", item[i].itemId, item[i].itemName );
			printf("\n Gia nhap: %.2f", item[i].priceIn);
			printf("\n Gia ban: %.2f", item[i].priceOut);
			printf("\n So luong: %d", item[i].quantity);
		}
	}

	if ( count == 0 ) printf("\n Khong tim thay san pham!");
}

void sell( Item item[], int n, float *income ){
	int id, check = 0, index, qty;
	printf("\nNhap ma san pham can ban: ");
	scanf("%d", &id);
	
	for ( int i = 0; i<n ; i++){
		if ( item[i].itemId == id ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == 0){
		printf("\n ID k ton tai!");
	}else{
		printf("\nNhap so luong ban: ");
		scanf("%d", &qty);
		
		if ( item[index].quantity == 0 ){
			printf("\nSan pham het hang!");
		}else if ( item[index].quantity < qty ){
			printf("\nSan pham khong du so luong!");
		}else{
			item[index].quantity -= qty;
			*income += item[index].priceOut * qty ;
			
			printf("\nKet qua ban san pham: ");
			for ( int i = 0; i< n ; i++){
				printf("\n\n %d. %s", item[i].itemId, item[i].itemName );
				printf("\n Gia nhap: %.2f", item[i].priceIn);
				printf("\n Gia ban: %.2f", item[i].priceOut);
				printf("\n So luong: %d", item[i].quantity);
			}
		}
	}
}

void revenue( float income ){
	printf("\nDoanh thu hien tai: %.2f", income);
}

