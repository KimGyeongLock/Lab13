#include "book.h"

void selectMenu(){
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
