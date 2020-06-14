#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
}

struct pcb_t* dequeue(struct queue_t *q) {
    struct pcb_t* proc = NULL;
    if (empty(q)) {
        proc = NULL;
    }
    else {
        int max = 0;
        uint32_t priorMax = q->proc[0]->priority;
        for (int i = 0; i < q->size; i++) {
            if (q->proc[i]->priority > priorMax) {
                priorMax = q->proc[i]->priority;
                max = i;
            }
        }
        proc = q->proc[max];
        for (int i = max; i < q->size - 1; i++) {
            q->proc[i] = q->proc[i + 1];
        }
        q->size--;
    }
    return proc;
}
