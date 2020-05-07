#include "book.h"

int selectMenu(){
	int menu;
	printf("\n*** 도서관리 시스템 ***\n");
	printf("1. 조회\n");
	printf("2. 반납\n");
	printf("3. 대출\n");
	printf("4. 수정\n");
	printf("5. 저장\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

int addBook(Book *b){
	printf("책의 제목은? ");
	scanf("%[^\n]s", b->name);
	printf("책의 저자는? ");
	scanf("%[^\n]s", b->author);
	printf("책의 가격은? ");
	scanf("%d", &b->price);
	printf("책의 별점? ");
	scanf("%d", &b->star);
	printf("=> 반납 되었습니다.\n");
	return 1;
}

void readBook(Book b){
	printf("『%s』(%s)\n  %d원\n  ★★★★★(%d)", b.name, b.author, b.price, b.star);
}

int updateBook(Book *b){
	printf("새 책의 제목은? ");
	scanf("%[^\n]s", b->name);
	printf("새 책의 저자는? ");
	scanf("%[^\n]s", b->author);
	printf("새 책의 가격은? ");
	scanf("%d", &b->price);
	printf("새 책의 별점? ");
	scanf("%d", &b->star);
	printf("=> 수정 되었습니다.\n");
	return 1;
}

int deleteBook(Book *b){
	b->price = -1;
	printf("=> 대출 되었습니다.\n");
	return 1;
}

void listBook(Book *b, int count){
	for(int i = 0; i < count; i++){
		if(b[i].price == -1) continue;
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
