process.stdin.resume();
process.stdin.setEncoding("utf-8");

let stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;
});

process.stdin.on("end", function () {
    main(stdin_input);
});

function main(input) {
    const data = input.trim().split(/\s+/).map(Number);
    let pos = 0;

    const N = data[pos++];
    const K = data[pos++];

    const A = new Array(N);
    for (let i = 0; i < N; i++) {
        A[i] = data[pos++];
    }

    /*
     * Create K consecutive non-empty segments.
     *
     * We distribute the extra elements among the first
     * segments, so the sizes differ by at most 1.
     */
    const segments = [];

    const base = Math.floor(N / K);
    const extra = N % K;

    let start = 0;

    for (let i = 0; i < K; i++) {
        const size = base + (i < extra ? 1 : 0);

        segments.push({
            start: start,
            end: start + size
        });

        start += size;
    }

    /*
     * Return V for a particular permutation of segments.
     */
    function buildArray(order) {
        const V = new Array(N);
        let p = 0;

        for (const id of order) {
            const seg = segments[id];

            for (let i = seg.start; i < seg.end; i++) {
                V[p++] = A[i];
            }
        }

        return V;
    }

    /*
     * Longest Increasing Subsequence.
     * Strictly increasing.
     */
    function LIS(arr) {
        const tails = [];

        for (const x of arr) {
            let left = 0;
            let right = tails.length;

            while (left < right) {
                const mid = (left + right) >> 1;

                if (tails[mid] < x) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            tails[left] = x;
        }

        return tails.length;
    }

    /*
     * Longest Decreasing Subsequence.
     */
    function LDS(arr) {
        const tails = [];

        for (const x of arr) {
            const value = -x;

            let left = 0;
            let right = tails.length;

            while (left < right) {
                const mid = (left + right) >> 1;

                if (tails[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            tails[left] = value;
        }

        return tails.length;
    }

    function score(order) {
        const V = buildArray(order);

        const lis = LIS(V);
        const lds = LDS(V);

        // ^ is bitwise XOR in JavaScript
        return lis * lds - (lis ^ lds);
    }

    /*
     * Initial order.
     */
    let bestOrder = new Array(K);

    for (let i = 0; i < K; i++) {
        bestOrder[i] = i;
    }

    let bestScore = score(bestOrder);

    /*
     * Also try reverse order.
     */
    const reverseOrder = [...bestOrder].reverse();
    const reverseScore = score(reverseOrder);

    if (reverseScore > bestScore) {
        bestScore = reverseScore;
        bestOrder = reverseOrder;
    }

    /*
     * Randomized search.
     *
     * Since this is an approximate problem, trying many
     * different permutations of the K segments can give
     * considerably better scores.
     */
    const ITERATIONS = 300;

    for (let it = 0; it < ITERATIONS; it++) {
        const order = new Array(K);

        for (let i = 0; i < K; i++) {
            order[i] = i;
        }

        // Fisher-Yates shuffle
        for (let i = K - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));

            const temp = order[i];
            order[i] = order[j];
            order[j] = temp;
        }

        const currentScore = score(order);

        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestOrder = order;
        }
    }

    /*
     * Local improvement.
     *
     * Try swapping two segments. If the score improves,
     * keep the swap.
     */
    let improved = true;
    let rounds = 0;

    while (improved && rounds < 3) {
        improved = false;
        rounds++;

        for (let i = 0; i < K && !improved; i++) {
            for (let j = i + 1; j < K; j++) {
                const temp = bestOrder[i];
                bestOrder[i] = bestOrder[j];
                bestOrder[j] = temp;

                const newScore = score(bestOrder);

                if (newScore > bestScore) {
                    bestScore = newScore;
                    improved = true;
                    break;
                }

                // Undo swap
                bestOrder[j] = bestOrder[i];
                bestOrder[i] = temp;
            }
        }
    }

    /*
     * Output:
     *
     * First K lines = ending index of each segment.
     *
     * Last line = permutation B.
     *
     * Segment boundaries are fixed by the original array,
     * so their ending indices are simply:
     */
    const output = [];

    let end = 0;

    for (let i = 0; i < K; i++) {
        const size = base + (i < extra ? 1 : 0);
        end += size;
        output.push(String(end));
    }

    /*
     * B is the order in which segments are concatenated.
     * Convert 0-based IDs to 1-based.
     */
    output.push(bestOrder.map(x => x + 1).join(" "));

    process.stdout.write(output.join("\n"));
}
