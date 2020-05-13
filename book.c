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
	else printf("\t대출 불가능(%c)\n",b.checkedOut);
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
	printf("\n=> 대출 되었습니다.\n");
	printf("『%s』(%s)\n\t%d원\n\t★★★★★(%d)\n", b->name, b->author, b->price, b->star);
	if(b->checkedOut == 'X') printf("\t대출 불가능(%c)\n",b->checkedOut);
	return 1;
}

void listBook(Book *b, int count){
	printf("\n**현재 도서관의 책 목록입니다**\n");
	for(int i = 0; i < count; i++){
		printf("[%d] ", i+1);
		readBook(b[i]);
	}
	char choose;
	printf("\n대출 가능한 책만 보시겠습니까? (y/n) ");
	getchar();
	scanf("%c", &choose);
	if(choose == 'y'|| choose == 'Y') sortBook(b,count);
	
}

int selectBookNum(Book *b, int count){
	int no;
	listBook(b, count);
	while(1){
		printf("\n번호는 (취소 :0)? ");
		scanf("%d", &no);
		if(b[no-1].checkedOut == 'X') printf("이 책은 대출중입니다!\n");
		else break;
	}
	return no;
}

void sortBook(Book *b, int count){
	Book temp;
	for(int i = 0;i < count ;i++){
		for(int j=i+1;j<count;j++){
				if(strcmp(b[i].name, b[j].name)>0){
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}	
		}
	}
	int c=0;
	printf("\n");
	for(int i=0;i<count;i++){
		if(b[i].checkedOut == 'O'){
			c++;
			printf("[%d]『%s』(%s)\n\t%d원\n\t★★★★★(%d)\n",c, b[i].name, b[i].author, b[i].price, b[i].star);
		}
	}


}
