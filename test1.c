/*
 * test1.c
 *
 *  Created on: Apr 4, 2015
 *      Author: kswa1
 */

#include <stdio.h>
#include <string.h>
#include "book_info_heap.h"

book_info *get_new_book_info(char *title, char *author, unsigned int year_published)
{
  book_info *info = new_book_info();
  if (info == NULL)
    {
      return NULL;
    }
  strncpy(info->title, title, sizeof(info->title) - 1);
  strncpy(info->author, author, sizeof(info->author) - 1);
  info->year_published = year_published;
  return info;
}

void print_info(const book_info *info)
{
  printf("Book Title: %s\n", info->title);
  printf("Book Author: %s\n", info->author);
  printf("Book Year Published: %u\n", info->year_published);
}

int main() {
  init_heap();
 
  book_info* arr[20];
  unsigned int i, j, k, l;

  for (i = 0; i < 20; i++) {
    arr[i] = get_new_book_info("Rant: The Oral Biography of Buster Casey", "Chuck Palahniuk", 2008);
  }

  dump_heap();

  for (j = 0; j < 20; j+=2) {
    del_book_info(arr[j]);
  }

  dump_heap();

  for (k = 0; k < 20; k+=2) {
    arr[k] = get_new_book_info("What If: Serious Scientific Answers to Absurd Hypothetical Questions", "Randall Monroe", 2014);
  }

  dump_heap();

  for (l = 0; l < 20; l++) {
    del_book_info(arr[l]);
  }

  dump_heap();
  return 0;
}
