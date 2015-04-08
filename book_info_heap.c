/*****************                                                                 
 ** Katie Swanson                                                                  
 ** 313 Proj 5                                                                     
 ** book_info_heap.c
 *****************/

#include <stdio.h>
#include <string.h>
#include "book_info_heap.h"
#define SIZE_BOOK_ARRAY 20

static book_info book_array[SIZE_BOOK_ARRAY];

static book_info* free_block_list;

// Housekeeping - initialize linked list of free blocks
void init_heap() {
  unsigned int i;
  for (i = 0; i < SIZE_BOOK_ARRAY; i++) {
    memset(book_array[i].title, '\0', sizeof(book_array[i].title));
    memset(book_array[i].author, '\0', sizeof(book_array[i].author));
    book_array[i].year_published = i+1;
  }
  free_block_list = &book_array[0];
}

// returns a pointer to item in free_block_list, removes it from the list
book_info* new_book_info() {
  book_info* temp;
  book_info* p1 = &book_array[0];
  int j;
  unsigned int i;

  if (free_block_list == NULL)
    return NULL;

  // return what is the current free pointer
  temp = free_block_list;
  // j is now index of slot about to be taken
  j = temp - p1;
  if (free_block_list->year_published < SIZE_BOOK_ARRAY) {
    // set free pointer to next free (pointed to by free pointer year published)
    free_block_list = &book_array[free_block_list->year_published];
  }
  else {
    free_block_list = NULL;
  }
  // return the initial free pointer
  return temp;
}

// adds info to free_block_list
void del_book_info(book_info* info) {
  book_info* p1 = &book_array[0];
  int j;
  j = info - p1;
  if (j >= SIZE_BOOK_ARRAY || j < 0) {
    printf("%s", "Error: This book is not in our memory.");
    exit(-1);
  }

  book_info* temp = free_block_list;
  int k;
  k = temp - p1;

  // clear out all 
  char temp1[50];
  char temp2[40];
  memset(book_array[j].title, '\0', sizeof(book_array[j].title));
  memset(book_array[j].author, '\0',sizeof(book_array[j].author));
  strcpy(temp1, "");
  strcpy(book_array[j].title, temp1);
  strcpy(temp2, "");
  strcpy(book_array[j].author, temp2);
  if (free_block_list != NULL) {
    // clear title and author, set year to index of current free_block_list
    book_array[j].year_published = k;
  }
  else {
    // use 20 to indicate end of linked list
    book_array[j].year_published = 20;
  }
  // set head pointer to current empty slot
  free_block_list = &book_array[j];
  info = NULL;
}

// print contents of global array & head of free_block_list
void dump_heap() {
  printf("%s\n", "*Dumping Heap.*");
  unsigned int i;

  if (free_block_list != NULL)
    printf("%s%u\n", "FreeSpot: ", free_block_list->year_published);

  for (i = 0; i < SIZE_BOOK_ARRAY; i++) {
    printf("Book Year Published: %u, ", book_array[i].year_published);
    printf("Book Title: %s, ", book_array[i].title);
    printf("Book Author: %s\n", book_array[i].author);
  }
  printf("%s\n\n", "*End dump heap.*");
}
