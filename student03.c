#include <stdio.h>
#include <assert.h>
#include "prio-q.h"

/* CMSC 216, Spring 2021, Project #7
 * Student test 3 (student03.c)
 * Tests for memory leaks from dequeue()
 */

int main(void) {
  Prio_que prio_q;
  char *elements[]= {"AA", "CC", "DD", "BB", "EE", "FF"};
  int i, priorities[]= {9, 5, 4, 1, 6, 2};
  char *element;

  init(&prio_q);

  for (i= 0; i < (int) (sizeof(elements) / sizeof(elements[0])); i++)
    enqueue(&prio_q, elements[i], priorities[i]);

  assert(size(prio_q) == 6);

  element = dequeue(&prio_q);
  assert(element!=NULL);
  assert(size(prio_q) == 5);

  printf("Assertions worked. Check valgrind.\n");

  return 0;
}