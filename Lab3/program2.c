#include <stdio.h>
#include <stdlib.h>

#define MAX_CLIENTS 50
#define TEST_ITEMS 55

typedef struct
{
    int id;
    int arrival;
    int duration;
} Client;

typedef struct Node
{
    Client data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} Queue;

void init(Queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

int is_empty(Queue *q) { return q->head == NULL; }

int is_full(Queue *q)
{
    (void) q;
    return 0;
}

int enqueue(Queue *q, Client c)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        return 0;
    }
    node->data = c;
    node->next = NULL;
    if (q->tail == NULL)
    {
        q->head = node;
    }
    else
    {
        q->tail->next = node;
    }
    q->tail = node;
    return 1;
}

int dequeue(Queue *q, Client *c)
{
    Node *old;
    if (is_empty(q))
    {
        return 0;
    }
    old = q->head;
    *c = old->data;
    q->head = old->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(old);
    return 1;
}

int peek_front(Queue *q, Client *c)
{
    if (is_empty(q))
    {
        return 0;
    }
    *c = q->head->data;
    return 1;
}

static void run_simulation(void)
{
    Queue q;
    Client clients[MAX_CLIENTS];
    Client c;
    int n, i, wait, finish;
    int next = 0;
    int done = 0;
    int time = 0;
    long long total_wait = 0;

    init(&q);
    printf("Number of clients (1..%d): ", MAX_CLIENTS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CLIENTS)
    {
        printf("Invalid number of clients\n");
        return;
    }
    printf("Enter arrival time and service duration for each client\n");
    printf("(arrival times in non-decreasing order, duration >= 1)\n");
    for (i = 0; i < n; i++)
    {
        printf("Client %d: ", i + 1);
        clients[i].id = i + 1;
        if (scanf("%d %d", &clients[i].arrival, &clients[i].duration) != 2
            || clients[i].arrival < 0 || clients[i].duration < 1
            || (i > 0 && clients[i].arrival < clients[i - 1].arrival))
        {
            printf("Invalid input\n");
            return;
        }
    }

    printf("\nClient  Arrival  Duration  Start  Waited  Leaves\n");
    while (done < n)
    {
        while (next < n && clients[next].arrival <= time)
        {
            if (!enqueue(&q, clients[next]))
            {
                printf("Queue is full\n");
                while (dequeue(&q, &c))
                {
                }
                return;
            }
            next++;
        }
        if (is_empty(&q))
        {
            time = clients[next].arrival;
            continue;
        }
        dequeue(&q, &c);
        wait = time - c.arrival;
        finish = time + c.duration;
        printf("%6d  %7d  %8d  %5d  %6d  %6d\n",
               c.id, c.arrival, c.duration, time, wait, finish);
        total_wait += wait;
        time = finish;
        done++;
    }
    printf("\nAverage waiting time: %.2f\n", (double) total_wait / n);
}

static void test_queue(void)
{
    Queue q;
    Client c;
    int i;
    int accepted = 0;

    init(&q);
    c.arrival = 0;
    c.duration = 1;

    printf("\nTest 1: dequeue from an empty queue\n");
    if (!dequeue(&q, &c))
    {
        printf("  queue is empty, nothing to remove\n");
    }

    printf("Test 2: add %d clients\n", TEST_ITEMS);
    for (i = 1; i <= TEST_ITEMS; i++)
    {
        c.id = i;
        if (enqueue(&q, c))
        {
            accepted++;
        }
    }
    printf("  accepted: %d, rejected: %d\n", accepted, TEST_ITEMS - accepted);
    if (is_full(&q))
    {
        printf("  queue is full, extra clients were not added\n");
    }

    printf("Test 3: remove 10 clients, add 10 new ones\n");
    for (i = 0; i < 10; i++)
    {
        dequeue(&q, &c);
    }
    for (i = 1; i <= 10; i++)
    {
        c.id = 100 + i;
        enqueue(&q, c);
    }
    peek_front(&q, &c);
    printf("  first in the queue: client %d\n", c.id);

    printf("Test 4: order of leaving (FIFO):\n  ");
    while (dequeue(&q, &c))
    {
        printf("%d ", c.id);
    }
    printf("\n");
}

int main(void)
{
    run_simulation();
    test_queue();
    return 0;
}
