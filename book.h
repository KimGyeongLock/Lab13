#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	char author[50];
	int price;  
	int checkedOut;
	int star;
}Book;

int selectMenu();
int addBook(Book *b); 
void readBook(Book b);
int updateBook(Book *b);
int deleteBook(Book *b);
 
void listBook(Book *b, int count); 
int selectBookNum(Book *b, int count); 

void saveBookList(Book *b, int count); 
int loadBookList(Book *b); 

int sortBook(Book *b, int count);
void searchBookName(Book *s, int count); 
