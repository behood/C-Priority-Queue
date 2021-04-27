#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "prio-q.h"

/* CMSC 216, Spring 2021, Project #7
 * Student test 4 (student04.c)
 * Tests an even more basic case of clear() on single node queue
 */

int main(void)
{
    Prio_que prio_q;

    init(&prio_q);
    enqueue(&prio_q, "AA", 9);

    assert(size(prio_q) == 1);

    clear(&prio_q);
    assert(is_empty(prio_q) == 1);

    printf("Student test worked right.\n");

    return 0;
}