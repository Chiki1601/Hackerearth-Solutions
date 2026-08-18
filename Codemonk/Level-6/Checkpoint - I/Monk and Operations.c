#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll absll(ll x) {
    return x < 0 ? -x : x;
}

ll max3(ll a, ll b, ll c) {
    ll ans = a;

    if (b > ans)
        ans = b;

    if (c > ans)
        ans = c;

    return ans;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    ll **A = (ll **)malloc(N * sizeof(ll *));

    for (int i = 0; i < N; i++) {
        A[i] = (ll *)malloc(M * sizeof(ll));
    }

    // Read matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lld", &A[i][j]);
        }
    }

    ll v1, v2, v3, v4;
    scanf("%lld %lld %lld %lld", &v1, &v2, &v3, &v4);

    /*
     * Calculate maximum using ROW operations.
     */
    ll bestRows = 0;

    for (int i = 0; i < N; i++) {

        ll original = 0;
        ll addV1 = 0;

        for (int j = 0; j < M; j++) {
            original += absll(A[i][j]);
            addV1 += absll(A[i][j] + v1);
        }

        // Type 2: set entire row to v2
        ll replaceV2 = (ll)M * absll(v2);

        ll bestRow = max3(original, addV1, replaceV2);

        bestRows += bestRow;
    }

    /*
     * Calculate maximum using COLUMN operations.
     */
    ll bestColumns = 0;

    for (int j = 0; j < M; j++) {

        ll original = 0;
        ll addV3 = 0;

        for (int i = 0; i < N; i++) {
            original += absll(A[i][j]);
            addV3 += absll(A[i][j] + v3);
        }

        // Type 4: set entire column to v4
        ll replaceV4 = (ll)N * absll(v4);

        ll bestColumn = max3(original, addV3, replaceV4);

        bestColumns += bestColumn;
    }

    /*
     * Row and column operations cannot be mixed.
     */
    ll answer = bestRows > bestColumns ? bestRows : bestColumns;

    printf("%lld\n", answer);

    for (int i = 0; i < N; i++) {
        free(A[i]);
    }

    free(A);

    return 0;
}
