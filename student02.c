#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "prio-q.h"

/* CMSC 216, Spring 2021, Project #7
 * Student test 2 (student02.c) tests free_name_list
 */

int main(void) {

  /*create a dynamically allocated array of 6 elements */
  int i;
  char *elements[] = {"AA", "CC", "DD", "BB", "EE", "FF"};
  char **str_arr; 
  str_arr = malloc (6 * sizeof (char *) );
  for(i = 0; i < 6; i++)
  {
      str_arr[i] = calloc(3, sizeof( *str_arr[i]) );
      strcpy(str_arr[i], elements[i]);
  }
  str_arr[6] = NULL;

  assert(ARRSIZE(str_arr) == 6);

  /*free the array */

  /*assert that the array is empty */
  /*assert(ARRSIZE(str_arr) == 0); */

  printf("Student test worked right.\n");

  return 0;
}