#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "prio-q.h"

/* CMSC 216, Spring 2021, Project #7
 * Student test 1 (student01.c)
 * Tests basic case of clear() by comparing array to empty
 */

int main(void) {
  Prio_que prio_q;
  char *elements[]= {"AA", "CC", "DD", "BB", "EE", "FF"};
  int i, priorities[]= {9, 5, 4, 1, 6, 2};

  init(&prio_q);

  for (i= 0; i < (int) (sizeof(elements) / sizeof(elements[0])); i++)
    enqueue(&prio_q, elements[i], priorities[i]);

  assert(size(prio_q) == 6);

  clear(&prio_q);
  assert(is_empty(prio_q) == 1);

  printf("Student test worked right.\n");

  return 0;
}