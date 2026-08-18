#include <stdio.h>

#define MOD 1000000007LL

int parent[1005];
int size[1005];

/* Find the representative of a set */
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }

    return parent[x];
}

/* Merge two sets */
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    /* Union by size */
    if (size[a] < size[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    size[a] += size[b];
}

/* Fast power: calculates (base^exp) % MOD */
long long power(long long base, int exp) {
    long long result = 1;

    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return result;
}

int main() {

    int N, Q;

    scanf("%d", &N);
    scanf("%d", &Q);

    /*
     * Initially every position is its own component.
     */
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    /*
     * Process every palindrome condition.
     */
    for (int q = 0; q < Q; q++) {

        int A, B;

        scanf("%d %d", &A, &B);

        /*
         * For A B to be a palindrome:
         *
         * A       == B
         * A + 1   == B - 1
         * A + 2   == B - 2
         * ...
         */
        while (A < B) {
            unite(A, B);

            A++;
            B--;
        }
    }

    /*
     * Count the number of independent components.
     */
    int components = 0;

    for (int i = 1; i <= N; i++) {
        if (find(i) == i) {
            components++;
        }
    }

    /*
     * Each component can independently contain
     * any of the 10 digits (0 to 9).
     */
    long long answer = power(10, components);

    printf("%lld\n", answer);

    return 0;
}
