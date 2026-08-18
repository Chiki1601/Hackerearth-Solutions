#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int to;
    int next;
} Edge;

typedef struct {
    int person;
    long long reward;
} Event;

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    /*
        Adjacency list
    */
    int *head = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    Edge *edges = (Edge *)malloc(2LL * m * sizeof(Edge));

    int edgeCount = 0;

    for (int i = 0; i < m; i++) {
        int a, b;

        scanf("%d %d", &a, &b);

        --a;
        --b;

        edges[edgeCount].to = b;
        edges[edgeCount].next = head[a];
        head[a] = edgeCount++;

        edges[edgeCount].to = a;
        edges[edgeCount].next = head[b];
        head[b] = edgeCount++;
    }

    int q;
    scanf("%d", &q);

    Event *events = (Event *)malloc(q * sizeof(Event));

    for (int i = 0; i < q; i++) {
        int person;
        long long reward;

        scanf("%d %lld", &person, &reward);

        events[i].person = person - 1;
        events[i].reward = reward;
    }

    /*
        We binary search the answer for every person.

        lo[i] = day known to be insufficient
        hi[i] = day known to be sufficient

        Initially:
            lo = 0
            hi = q + 1

        q + 1 means "never becomes happy".
    */
    int *lo = (int *)calloc(n, sizeof(int));
    int *hi = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        hi[i] = q + 1;

    /*
        Buckets for parallel binary search.

        bucketHead[day] contains people whose
        current midpoint is 'day'.
    */
    int *bucketHead = (int *)malloc((q + 1) * sizeof(int));
    int *bucketNext = (int *)malloc(n * sizeof(int));

    long long *rewardSum =
        (long long *)calloc(n, sizeof(long long));

    int changed = 1;

    while (changed) {
        changed = 0;

        /*
            Clear buckets.
        */
        for (int day = 0; day <= q; day++)
            bucketHead[day] = -1;

        /*
            Put every unresolved person into
            the bucket corresponding to their midpoint.
        */
        for (int person = 0; person < n; person++) {

            if (hi[person] - lo[person] > 1) {

                changed = 1;

                int mid = lo[person] +
                          (hi[person] - lo[person]) / 2;

                bucketNext[person] = bucketHead[mid];
                bucketHead[mid] = person;
            }
        }

        if (!changed)
            break;

        /*
            Reset accumulated rewards.
        */
        for (int i = 0; i < n; i++)
            rewardSum[i] = 0;

        /*
            Process days from 1 to Q.
        */
        for (int day = 1; day <= q; day++) {

            /*
                Apply today's reward.
            */
            int person = events[day - 1].person;
            long long reward = events[day - 1].reward;

            rewardSum[person] += reward;

            /*
                Check every person whose midpoint
                is this day.
            */
            for (int v = bucketHead[day];
                 v != -1;
                 v = bucketNext[v]) {

                long long total = 0;

                /*
                    Sum rewards of all friends of v
                    up to this day.
                */
                for (int e = head[v];
                     e != -1;
                     e = edges[e].next) {

                    int friend = edges[e].to;

                    total += rewardSum[friend];

                    /*
                        Since rewards are non-negative,
                        we can stop early.
                    */
                    if (total >= k)
                        break;
                }

                if (total >= k)
                    hi[v] = day;
                else
                    lo[v] = day;
            }
        }
    }

    /*
        Output answers.
        q + 1 means the person never becomes happy.
    */
    for (int i = 0; i < n; i++) {

        if (hi[i] == q + 1)
            printf("-1");
        else
            printf("%d", hi[i]);

        if (i != n - 1)
            printf(" ");
    }

    printf("\n");

    free(head);
    free(edges);
    free(events);
    free(lo);
    free(hi);
    free(bucketHead);
    free(bucketNext);
    free(rewardSum);

    return 0;
}
