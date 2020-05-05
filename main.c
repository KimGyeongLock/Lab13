#include "book.h"
#include "saveload.h"

int main(void){
	Book b[100];
	int count = 0, menu = 0;
	int curcount = 0;

	count = loadBookList(s);
	curcount = count;

	while (1){
		menu = selectMenu();
		if (menu == 0) break;
		if (menu == 1 || menu == 3 || menu == 4){
			if(count == 0){
				continue;
			}
		}
		if (menu == 1){
			if(count > 0){
                        	listBook(s,curcount);
			}
                }
	
}
