/*****************
 ** Katie Swanson
 ** 313 Proj 5
 ** book_info_heap.h
 *****************/

#ifndef BOOK_INFO_HEAP
#define BOOK_INFO_HEAP

typedef struct book_info {
  char title[50];
  char author[40];
  unsigned int year_published;
} book_info;

void init_heap();

book_info* new_book_info();

void del_book_info(book_info* info);

void dump_heap();

#endif
