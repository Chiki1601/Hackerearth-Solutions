'use strict';

const fs = require('fs');

const input = fs.readFileSync(0, 'utf8').trim().split(/\s+/).map(Number);
let idx = 0;

const T = input[idx++];
const output = [];

for (let tc = 0; tc < T; tc++) {
    const N = input[idx++];

    // Adjacency list using arrays for better performance
    const head = new Int32Array(N + 1);
    head.fill(-1);

    const to = new Int32Array(2 * (N - 1));
    const next = new Int32Array(2 * (N - 1));

    let edgeIndex = 0;

    function addEdge(u, v) {
        to[edgeIndex] = v;
        next[edgeIndex] = head[u];
        head[u] = edgeIndex++;
    }

    for (let i = 0; i < N - 1; i++) {
        const u = input[idx++];
        const v = input[idx++];

        addEdge(u, v);
        addEdge(v, u);
    }

    // logN for binary lifting
    const LOG = Math.ceil(Math.log2(N + 1));

    // up[k][v] = 2^k-th ancestor of v
    const up = Array.from(
        { length: LOG },
        () => new Int32Array(N + 1)
    );

    const depth = new Int32Array(N + 1);

    // Iterative DFS/BFS to avoid recursion stack overflow
    const parent = new Int32Array(N + 1);
    parent.fill(0);

    const queue = new Int32Array(N);
    let qHead = 0;
    let qTail = 0;

    queue[qTail++] = 1;
    parent[1] = 1;
    depth[1] = 0;

    while (qHead < qTail) {
        const u = queue[qHead++];

        for (let e = head[u]; e !== -1; e = next[e]) {
            const v = to[e];

            if (v === parent[u]) continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;
            queue[qTail++] = v;
        }
    }

    // First ancestor level
    for (let v = 1; v <= N; v++) {
        up[0][v] = parent[v];
    }

    // Binary lifting table
    for (let k = 1; k < LOG; k++) {
        const prev = up[k - 1];
        const curr = up[k];

        for (let v = 1; v <= N; v++) {
            curr[v] = prev[prev[v]];
        }
    }

    function lca(a, b) {
        if (depth[a] < depth[b]) {
            [a, b] = [b, a];
        }

        // Bring a to the same depth as b
        let diff = depth[a] - depth[b];

        for (let k = 0; k < LOG; k++) {
            if (diff & (1 << k)) {
                a = up[k][a];
            }
        }

        if (a === b) return a;

        // Jump both nodes upwards
        for (let k = LOG - 1; k >= 0; k--) {
            if (up[k][a] !== up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    }

    function distance(a, b) {
        const c = lca(a, b);

        return depth[a] + depth[b] - 2 * depth[c];
    }

    const M = input[idx++];

    for (let q = 0; q < M; q++) {
        const u1 = input[idx++];
        const v1 = input[idx++];
        const u2 = input[idx++];
        const v2 = input[idx++];

        const path1 = distance(u1, v1);
        const path2 = distance(u2, v2);

        const option1 =
            distance(u1, u2) +
            distance(v1, v2);

        const option2 =
            distance(u1, v2) +
            distance(v1, u2);

        const minimum = Math.min(option1, option2);

        const answer = Math.max(
            0,
            (minimum - path1 - path2) / 2
        );

        output.push(String(answer));
    }
}

process.stdout.write(output.join('\n'));
