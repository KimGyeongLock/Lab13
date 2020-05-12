#include "book.h"

int main(void){
	Book b[100];
	int count = 0, menu = 0;
	int curcount = 0;

	count = loadBookList(b);
	curcount = count;
	
	while (1){
		menu = selectMenu();
		if (menu == 0) break;
		if (menu == 1 || menu == 3 || menu == 4){
			if(count == 0) {
				printf("조회할 목록이 없습니다!\n");
				continue;
			}
		}
		if (menu == 1){
			if(count > 0){
                        	listBook(b,curcount);
			}
                }
		if (menu == 2){
			count += addBook(&b[curcount++]);
		}
		else if (menu == 3){
                	int no = selectBookNum(b, curcount);
			if(no == 0){
				printf("취소되었습니다.");
                                continue;
                        }
                        updateBook(&b[no-1]);
                }
                else if (menu == 4){
                        int no, deleteok;
                        no = selectBookNum(b, curcount);
                        if(no==0){
                                printf("취소되었습니다.\n");
                                continue;
                        }
                        printf("이 책을 대출하시겠습니까?(예:1) ");
                        scanf("%d", &deleteok);
                        if(deleteok == 1){
                                deleteBook(&b[no-1]);
                                count--;
                        }
                }
		else if (menu == 5){
			if(count ==0){
                                printf("데이터가 없습니다.\n");
			}
			else{
				saveBookList(b, curcount);
			}
		}
		else if(menu == 6){
			if(count == 0)
				printf("데이터가 없습니다.\n");
			else
				searchBookName(b, curcount);
        	}
	}
        printf("종료됨!\n");
        return 0;
}
