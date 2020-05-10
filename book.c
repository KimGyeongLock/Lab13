#include "book.h"

int selectMenu(){
	int menu;
	printf("\n*** 도서관리 시스템 ***\n");
	printf("1. 조회\n");
	printf("2. 반납\n");
	printf("3. 수정\n");
	printf("4. 대출\n");
	printf("5. 저장\n");
	printf("6. 검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

int addBook(Book *b){
	printf("책의 제목은? ");
	getchar();
	scanf("%[^\n]s", b->name);
	printf("책의 저자는? ");
	getchar();
	scanf("%[^\n]s", b->author);
	printf("책의 가격은? ");
	scanf("%d", &b->price);
	printf("책의 별점? ");
	scanf("%d", &b->star);
	printf("=> 반납 되었습니다.\n");
	b->checkedOut = 'O';
	return 1;
}

void readBook(Book b){
	printf("『%s』(%s)\n\t%d원\n\t★★★★★(%d)\n", b.name, b.author, b.price, b.star);
	if(b.checkedOut == 'O') printf("\t대출 가능(%c)\n",b.checkedOut);
}

int updateBook(Book *b){
	printf("새 책의 제목은? ");
	getchar();
	scanf("%[^\n]s", b->name);
	printf("새 책의 저자는? ");
	getchar();
	scanf("%[^\n]s", b->author);
	printf("새 책의 가격은? ");
	scanf("%d", &b->price);
	printf("새 책의 별점? ");
	scanf("%d", &b->star);
	printf("=> 수정 되었습니다.\n");
	return 1;
}

int deleteBook(Book *b){	
	b->checkedOut = 'X';
	printf("=> 대출 되었습니다.\n");
	printf("『%s』(%s)\n\t%d원\n\t★★★★★(%d)\n", b->name, b->author, b->price, b->star);
	if(b->checkedOut == 'X') printf("\t대출 불가능(%c)\n",b->checkedOut);
	return 1;
}

void listBook(Book *b, int count){
	printf(" **현재 도서관의 책 목록입니다**\n");
	for(int i = 0; i < count; i++){
		if(b[i].checkedOut == 'X') continue;
		printf("[%d] ", i+1);
		readBook(b[i]);
	}
}

int selectBookNum(Book *b, int count){
	int no;
	listBook(b, count);
	printf("\n번호는 (취소 :0)? ");
	scanf("%d", &no);
	return no;
}
