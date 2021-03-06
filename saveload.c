#include "book.h"

void saveBookList(Book *b, int count){
	FILE *fp;
	fp = fopen("booklist.txt","wt");
	for(int i=0; i<count; i++){
		fprintf(fp,"%d %d %c %s\n %s\n", b[i].price, b[i].star, b[i].checkedOut, b[i].author, b[i].name);
	}
	fclose(fp);
	printf("=> 도서목록이 저장되었습니다\n");
}

int loadBookList(Book *b){
	int count = 0;
	FILE *fp; 
	fp = fopen("booklist.txt", "rt"); 
	if(fp == NULL){ 
		printf("=> 파일이 존재하지 않습니다\n");
		return 0;
	}
	for( ; ; count++){
		fscanf(fp,"%d %d %c %[^\n] %[^\n]", &b[count].price, &b[count].star, &b[count].checkedOut, b[count].author, b[count].name);
		if(feof(fp)){ 
			break;
		}
	}	
	fclose(fp);
	printf("=>도서목록을 불러왔습니다\n");
	return count;
}

