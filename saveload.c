#include <book.h>

void saveBookList(Book *b, int count){
	FILE *fp;
	fp = fopen("booklist.txt","wt");
	for(int i=0; i<count; i++){
		if(){
			fprintf(fp,"%d %d %s %s", b[i].price, b[i].star, b[i].author, b[i].name);
		}
	}
	fclose(fp);
	printf("도서목록이 저장되었습니다\n");
}
