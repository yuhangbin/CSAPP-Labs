/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
	if (q == NULL) {
		return NULL;
	}
    q->head = NULL;
	q->tail = NULL;
	q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
	if (q == NULL) {
		return;
	}
    /* How about freeing the list elements? */
    /* Free queue structure */
	while (q->head != NULL) {
		list_ele_t *h = q->head;
		q->head = q->head->next;
		free(h);
	}
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    if (q == NULL) {
        return false;
    }
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if (newh == NULL) {
        return false;
    }
    newh->value = v;
    newh->next = q->head;
    q->head = newh;
	// update q->tail
	if (q->size == 0) {
		q->tail = newh;
	}
    q->size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    if (q == NULL) {
        return false;
    }
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *ele;
    ele = malloc(sizeof(list_ele_t));
    if (ele == NULL) {
        return false;
    }
    ele->value = v;
    ele->next = q->tail->next;
    q->tail->next = ele;
    q->tail = ele;
	if (q->size == 0) {
		q->head = ele;
	}
    q->size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (q == NULL || q->head == NULL) {
        return false;
    }
    /* You need to fix up this code. */
	if (vp) {
		*vp = q->head->value;
	}
	list_ele_t *head = q->head;
    q->head = q->head->next;
	q->size--;
	free(head);
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
	if (q == NULL) {
		return 0;
	}
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL || q->head == NULL) {
        return;
    }
    /* You need to write the code for this function */
    // don't use recursive
    list_ele_t *cur = q->head;
    q->head = NULL;
	q->tail = cur;
    while (cur != NULL) {
        list_ele_t *next = cur->next;
        cur->next = q->head;
        q->head = cur;
        cur = next;
    }
}

