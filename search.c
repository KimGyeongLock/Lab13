#include "book.h"

void searchBookName(Book *b, int count){
	int bcount = 0;
	char search[100];
	printf("검색할도서의 이름은? ");
	getchar();
	fgets(search, 100, stdin);
	search[strlen(search)-1]='\0';
	for(int i =0; i<count; i++){
		if(strstr(b[i].name, search)){
			readBook(b[i]);
			if(b[i].checkedOut == 'X'){
				printf("\t*대출 중인 도서입니다*\n");
			}
			bcount++;
		}
	}
	if(bcount == 0){
                printf("=> 검색한 도서가 존재하지 않습니다");
	} 
	printf("\n");
}
