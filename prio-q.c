/* Brendan Hood, I Pledge on my Honor I have not given or recieved
   assistance on this project.*/

/*An implementation for a Priority Queue datastructure. Data values 
   can be enqueued into the list and dequeued from the list. A peek
   function allows access to the value of the highest priority data
   This implementation can also be used to know the size of a 
   priority queue, and wether it is empty.*/

#include <stdlib.h>
#include <string.h>
#include "prio-q.h"

static Node *new_node(const char *dat, int priority);
unsigned int clear_node(Node *ptr);

/*Helper, creates a new node given data and prio, returns ptr to node*/
static Node *new_node(const char *dat, int priority)
{

  Node *temp;
  if (dat == NULL || priority < 0)
    return NULL;
  else
  {
    temp = malloc(sizeof(Node));
    temp->data = calloc(strlen(dat) + 1, sizeof(char));
    strcpy(temp->data, dat);
    temp->prio = priority;
    temp->next = NULL;

    return temp;
  }
}

/*Initializes the Prio_que variable to point to an empty queue*/
void init(Prio_que *const prio_q)
{
  if(prio_q != NULL)
  {
    prio_q -> head = NULL;
    (*prio_q).num_nodes = 0;
  }
}

/*Method decription*/
unsigned int enqueue(Prio_que *const prio_q, const char new_element[],
        unsigned int priority)
{

  Node *curr, *temp;
  int queued = 0;

  /*null checks */
  if(prio_q == NULL || new_element == NULL)
    return queued;

  curr = prio_q -> head;
  temp = new_node(new_element, priority);
  if(prio_q -> head == NULL) /*empty list case */
  {
    prio_q -> head = temp;
    (prio_q -> num_nodes)++;
    queued = 1;
  }
  else if ( prio_q->head->prio < priority) /*list not empty, but adds first*/
  {
    temp -> next = prio_q -> head;
    prio_q -> head = temp;
    (prio_q -> num_nodes)++;
    queued = 1;
  }
  else
  {
    /*traverses to find where to insert*/
    while (curr->next != NULL && curr->next->prio > priority)
    {
      curr = curr->next;
    }

    /*short circtuis if prio used*/
    if ((curr -> next != NULL ) && (curr->next->prio == priority))
    {
      free(temp);
      return 0;
    }
    
    temp -> next = curr -> next;
    curr -> next = temp;
    (prio_q -> num_nodes)++;
    queued = 1;
  }

  return queued;
}

/*Returns 1 if the Priority queue is empty, 0 otherwise*/
unsigned int is_empty(const Prio_que prio_q)
{
  return (prio_q.num_nodes == 0);
}


/*Returns the current size of the priority queue*/
unsigned int size (const Prio_que prio_q)
{
  return (prio_q.num_nodes);
}

/*Returns the value of the highest priority element in the queue*/
char *peek(Prio_que prio_q)
{

  char *datcpy;
  if (prio_q.head != NULL)
  {
    datcpy = calloc(strlen(prio_q.head->data) + 1, sizeof(char));
    if (datcpy != NULL)
      strcpy(datcpy, (prio_q.head)->data);
  }
  return datcpy;
}

/*Removes the element with the highest priority from the queue. 
    Returns data of removed element*/
char *dequeue(Prio_que *const prio_q)
{
  Node *temp;
  char *dat;

  /*null checks*/
  if (prio_q == NULL || prio_q->head == NULL) /*if empty list */
      return NULL;

  /*hold just the string data, reassign head, clear old head node*/
  dat = calloc (strlen(prio_q->head->data) + 1, sizeof(char));
  strcpy(dat, prio_q->head->data);
  temp = prio_q->head;
  prio_q->head = prio_q->head->next;
  (prio_q -> num_nodes)--;
  
  clear_node(temp);
  return dat;
}

/* Returns a new array of copies of elements of a queue */
char **get_all_elements(Prio_que prio_q)
{

  char **nodes; /*new array of node data */
  int index = 0;
  Node *curr;
  char *temp;
  if (is_empty(prio_q))
    nodes = calloc(1, sizeof(char *)); /*needs room for one NULL*/
  else
  {
    /*adds space for num_nodes and a null terminator*/
    nodes = calloc((prio_q.num_nodes + 1), sizeof(char *)); 
    curr = prio_q.head;
    while (curr != NULL)
    {
  
      temp = calloc(strlen(curr->data) + 1, sizeof(char));
      strcpy(temp, curr->data);
      nodes[index] = temp;

      index++;
      curr = curr->next;
    }
  }

  nodes[index] = NULL;
  return nodes;
}

/* Free all dynamically allocated memory, then free the array*/
void free_name_list(char *name_list[])
{
  int index = 0;

  if(name_list == NULL)
    return;

  while (name_list[index] != NULL)
  {
    free(name_list[index++]);
  }

  free(name_list);
}

/*Helper, clears node at given location*/
unsigned int clear_node(Node *ptr)
{
  /*NULL check*/
  if (ptr != NULL)
  {
    ptr -> prio = 0;

    /*clears data, sets ptr to null*/
    free(ptr -> data);
    ptr -> data = NULL;
    ptr -> next = NULL;

    /*clears ptr, sets it to null*/
    free(ptr);
    ptr = NULL;

    return 1;
  }
  return 0;
}

/*Deallocates all memory used in prio_q, destroying the queue and its data*/
void clear(Prio_que *const prio_q)
{
  Node *curr, *prev;

  if(prio_q != NULL && prio_q->head != NULL)
  {
    curr = prio_q ->head;
    prev = curr;
    while (curr != NULL)
    {
      curr = curr -> next;
      clear_node(prev);
      (prio_q -> num_nodes)--;
      prev = curr;
    }
    clear_node(curr);
    prio_q->head = NULL;
  }
}

/* Searches for element and returns its prio if found. Returns
    the highest prio if multiple of element. -1 if not present */
int get_priority(Prio_que prio_q, char element[])
{
  Node *curr;

  /*null checks*/
  if( is_empty(prio_q) || element == NULL)
    return -1;

  /*traverse prio_q until string found*/
  curr = prio_q.head;
  while ( curr != NULL )
  {
    if(strcmp(curr -> data, element) == 0)
      return curr -> prio;
    
    curr = curr -> next;
  }
  
  return -1;
}

/*Removes any Nodes with prio between lo and hi inclusive from the queue*/
unsigned int remove_elements_between(Prio_que *const prio_q, unsigned int low,
                                     unsigned int high)
{

  Node *curr, *prev = NULL, *temp = NULL;
  int num_cleared = 0;

  /*NULL CHECKS */
  if(prio_q == NULL || is_empty(*prio_q))
    return 0;

  /*Traverses the list*/
  curr = prio_q -> head;
  while(curr != NULL)
  {
    /*if node is in the range delete it */
    if( curr->prio >= low && curr->prio <= high)
    {
      num_cleared++;
      (prio_q->num_nodes)--;

      if (prev == NULL) /* if first node */
        prio_q -> head = curr -> next;
      else 
        prev -> next = curr -> next;

      temp = curr;
      curr = curr -> next;
      clear_node(temp);
      
    } else {
      prev = curr;
      curr = curr -> next;
    }
    
  }
  return num_cleared;
}

/* Searches the queue for an element, and then updates its prio*/
unsigned int change_priority(Prio_que *prio_q, char element[],
                             unsigned int new_priority)
{
  Node *curr;
  
  /*null checks*/
  if ( (prio_q == NULL) || (element == NULL) )
    return -1;

  /*traverse prio_q until string found*/
  curr = prio_q -> head;
  while (curr != NULL)
  {
    if (strcmp(curr->data, element) == 0)
    {
      curr -> prio = new_priority;
      return 1;
    }

    curr = curr->next;
  }
  return 0;
}

/*-----------------------------------------------------------------------------*/