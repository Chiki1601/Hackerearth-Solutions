process.stdin.resume();
process.stdin.setEncoding("utf-8");

let input = "";

process.stdin.on("data", function (data) {
    input += data;
});

process.stdin.on("end", function () {
    solve(input);
});

function solve(input) {
    const data = input.trim().split(/\s+/);
    let idx = 0;

    const N = Number(data[idx++]);

    // ---------------------------------------------------------
    // Read values
    // ---------------------------------------------------------

    const A = new Float64Array(N + 1);

    for (let i = 1; i <= N; i++) {
        A[i] = Number(data[idx++]);
    }

    // ---------------------------------------------------------
    // Build adjacency list using arrays
    // ---------------------------------------------------------

    const head = new Int32Array(N + 1);
    head.fill(-1);

    const to = new Int32Array(2 * (N - 1));
    const next = new Int32Array(2 * (N - 1));

    let edgeCount = 0;

    function addEdge(u, v) {
        to[edgeCount] = v;
        next[edgeCount] = head[u];
        head[u] = edgeCount++;
    }

    for (let i = 0; i < N - 1; i++) {
        const u = Number(data[idx++]);
        const v = Number(data[idx++]);

        addEdge(u, v);
        addEdge(v, u);
    }

    // ---------------------------------------------------------
    // Coordinate compression
    // ---------------------------------------------------------

    const values = new Array(N);

    for (let i = 0; i < N; i++) {
        values[i] = A[i + 1];
    }

    values.sort((a, b) => a - b);

    const unique = [];

    for (let i = 0; i < N; i++) {
        if (i === 0 || values[i] !== values[i - 1]) {
            unique.push(values[i]);
        }
    }

    const M = unique.length;

    function lowerBound(x) {
        let left = 0;
        let right = M;

        while (left < right) {
            const mid = (left + right) >> 1;

            if (unique[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left + 1;
    }

    const rank = new Int32Array(N + 1);

    for (let i = 1; i <= N; i++) {
        rank[i] = lowerBound(A[i]);
    }

    // ---------------------------------------------------------
    // Segment tree
    //
    // We use one segment tree containing 3 independent values:
    //
    // tree1 -> best sequence of length 1
    // tree2 -> best sequence of length 2
    // tree3 -> best sequence of length 3
    //
    // Each leaf corresponds to a compressed A value.
    // ---------------------------------------------------------

    let size = 1;

    while (size < M) {
        size <<= 1;
    }

    const treeSize = size << 1;

    const tree1 = new Float64Array(treeSize);
    const tree2 = new Float64Array(treeSize);
    const tree3 = new Float64Array(treeSize);

    // ---------------------------------------------------------
    // Query maximum on [0, r]
    //
    // We need values strictly smaller than A[u].
    // Therefore query ranks [1, rank[u] - 1].
    // ---------------------------------------------------------

    function query(tree, r) {
        if (r <= 0) {
            return 0;
        }

        let l = size;
        let right = size + r - 1;

        let result = 0;

        while (l <= right) {
            if (l & 1) {
                if (tree[l] > result) {
                    result = tree[l];
                }
                l++;
            }

            if (!(right & 1)) {
                if (tree[right] > result) {
                    result = tree[right];
                }
                right--;
            }

            l >>= 1;
            right >>= 1;
        }

        return result;
    }

    // ---------------------------------------------------------
    // Update one leaf
    // ---------------------------------------------------------

    function update(tree, position, value) {
        if (value <= 0) {
            return;
        }

        let pos = size + position - 1;

        if (value > tree[pos]) {
            tree[pos] = value;
        } else {
            return;
        }

        pos >>= 1;

        while (pos > 0) {
            const newValue =
                tree[pos << 1] > tree[(pos << 1) | 1]
                    ? tree[pos << 1]
                    : tree[(pos << 1) | 1];

            if (tree[pos] === newValue) {
                // Ancestors cannot change anymore.
                break;
            }

            tree[pos] = newValue;
            pos >>= 1;
        }
    }

    // ---------------------------------------------------------
    // Root the tree at 1
    // ---------------------------------------------------------

    const parent = new Int32Array(N + 1);
    const order = new Int32Array(N);

    let orderCount = 0;

    const stack = new Int32Array(N);
    let top = 0;

    stack[top++] = 1;
    parent[1] = -1;

    while (top > 0) {
        const u = stack[--top];

        order[orderCount++] = u;

        for (let e = head[u]; e !== -1; e = next[e]) {
            const v = to[e];

            if (v === parent[u]) {
                continue;
            }

            parent[v] = u;
            stack[top++] = v;
        }
    }

    // ---------------------------------------------------------
    // DP arrays
    // ---------------------------------------------------------

    const dp2 = new Float64Array(N + 1);
    const dp3 = new Float64Array(N + 1);
    const dp4 = new Float64Array(N + 1);

    let answer = 0;

    // ---------------------------------------------------------
    // Iterative DFS with ENTER / EXIT
    //
    // ENTER u:
    //   query ancestors
    //   calculate dp
    //   insert u
    //
    // EXIT u:
    //   rollback u's insertion
    //
    // This keeps the segment tree equal to the current
    // root-to-node path.
    // ---------------------------------------------------------

    const dfsStack = new Int32Array(2 * N);
    let dfsTop = 0;

    // Positive = enter
    // Negative = exit
    dfsStack[dfsTop++] = 1;

    // For rollback we need the old value at each leaf.
    const old1 = new Float64Array(N + 1);
    const old2 = new Float64Array(N + 1);
    const old3 = new Float64Array(N + 1);

    while (dfsTop > 0) {
        const code = dfsStack[--dfsTop];

        if (code > 0) {
            // -------------------------------------------------
            // ENTER
            // -------------------------------------------------

            const u = code;
            const r = rank[u];

            // Query only values strictly smaller than A[u]
            const best1 = query(tree1, r - 1);
            const best2 = query(tree2, r - 1);
            const best3 = query(tree3, r - 1);

            // We need at least one previous node for dp2
            if (best1 > 0) {
                dp2[u] = best1 + A[u];
            }

            // We need a valid length-2 sequence
            if (best2 > 0) {
                dp3[u] = best2 + A[u];
            }

            // We need a valid length-3 sequence
            if (best3 > 0) {
                dp4[u] = best3 + A[u];

                if (dp4[u] > answer) {
                    answer = dp4[u];
                }
            }

            // -------------------------------------------------
            // Save old leaf values for rollback
            // -------------------------------------------------

            const pos = size + r - 1;

            old1[u] = tree1[pos];
            old2[u] = tree2[pos];
            old3[u] = tree3[pos];

            // -------------------------------------------------
            // Insert current node
            // -------------------------------------------------

            update(tree1, r, A[u]);

            if (dp2[u] > 0) {
                update(tree2, r, dp2[u]);
            }

            if (dp3[u] > 0) {
                update(tree3, r, dp3[u]);
            }

            // -------------------------------------------------
            // EXIT event
            // -------------------------------------------------

            dfsStack[dfsTop++] = -u;

            // -------------------------------------------------
            // ENTER children
            // -------------------------------------------------

            // Reverse order is not important.
            for (let e = head[u]; e !== -1; e = next[e]) {
                const v = to[e];

                if (v === parent[u]) {
                    continue;
                }

                dfsStack[dfsTop++] = v;
            }

        } else {
            // -------------------------------------------------
            // EXIT / ROLLBACK
            // -------------------------------------------------

            const u = -code;
            const r = rank[u];

            let pos = size + r - 1;

            tree1[pos] = old1[u];
            tree2[pos] = old2[u];
            tree3[pos] = old3[u];

            pos >>= 1;

            while (pos > 0) {
                tree1[pos] =
                    tree1[pos << 1] > tree1[(pos << 1) | 1]
                        ? tree1[pos << 1]
                        : tree1[(pos << 1) | 1];

                tree2[pos] =
                    tree2[pos << 1] > tree2[(pos << 1) | 1]
                        ? tree2[pos << 1]
                        : tree2[(pos << 1) | 1];

                tree3[pos] =
                    tree3[pos << 1] > tree3[(pos << 1) | 1]
                        ? tree3[pos << 1]
                        : tree3[(pos << 1) | 1];

                pos >>= 1;
            }
        }
    }

    console.log(answer);
}
