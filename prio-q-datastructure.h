#if (!defined(PRIO_Q_DATASTRUCTURES_H))
#define PRIO_Q_DATASTRUCTURES_H

/*Definition for the Data Structure for the priority queue
    implementation*/

typedef struct node {
  char *data;
  int prio;
  struct node *next;
} Node;

typedef struct prio_que{

    int num_nodes;
    Node *head;

} Prio_que;

#endif