'use strict';

const fs = require('fs');

const input = fs.readFileSync(0, 'utf8').trim().split(/\s+/).map(Number);
let idx = 0;

const n = input[idx++];
const k = input[idx++];

// ------------------------------------------------------------
// Read the complete graph
// ------------------------------------------------------------

const edges = [];

for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
        const w = input[idx++];

        if (i < j) {
            edges.push({
                u: i,
                v: j,
                w: w
            });
        }
    }
}

// ------------------------------------------------------------
// DSU
// ------------------------------------------------------------

class DSU {
    constructor(n) {
        this.parent = new Int32Array(n);
        this.size = new Int32Array(n);

        for (let i = 0; i < n; i++) {
            this.parent[i] = i;
            this.size[i] = 1;
        }
    }

    find(x) {
        let root = x;

        while (this.parent[root] !== root) {
            root = this.parent[root];
        }

        // Path compression
        while (this.parent[x] !== x) {
            const p = this.parent[x];
            this.parent[x] = root;
            x = p;
        }

        return root;
    }

    union(a, b) {
        a = this.find(a);
        b = this.find(b);

        if (a === b) {
            return false;
        }

        if (this.size[a] < this.size[b]) {
            [a, b] = [b, a];
        }

        this.parent[b] = a;
        this.size[a] += this.size[b];

        return true;
    }
}

// ------------------------------------------------------------
// Build Maximum Spanning Tree
// ------------------------------------------------------------

// Largest weights first
edges.sort((a, b) => b.w - a.w);

const dsu = new DSU(n);

const inTree = new Uint8Array(edges.length);

let treeEdges = 0;

for (let i = 0; i < edges.length && treeEdges < n - 1; i++) {
    const e = edges[i];

    if (dsu.union(e.u, e.v)) {
        inTree[i] = 1;
        treeEdges++;
    }
}

// ------------------------------------------------------------
// Non-tree edges
// ------------------------------------------------------------

// These edges can safely be removed because the MaxST
// remains connected.

const removable = [];

for (let i = 0; i < edges.length; i++) {
    if (!inTree[i]) {
        removable.push(edges[i]);
    }
}

// ------------------------------------------------------------
// Choose edges to delete
// ------------------------------------------------------------

// Delete high-weight edges first.
//
// Since the graph already contains the Maximum Spanning Tree,
// none of these deletions can disconnect the graph.

removable.sort((a, b) => {
    if (b.w !== a.w) {
        return b.w - a.w;
    }

    if (a.u !== b.u) {
        return a.u - b.u;
    }

    return a.v - b.v;
});

const q = Math.min(k, removable.length);

// ------------------------------------------------------------
// Output
// ------------------------------------------------------------

const output = [];

output.push(String(q));

for (let i = 0; i < q; i++) {
    const e = removable[i];

    // Problem expects 1-indexed vertices
    output.push(`${e.u + 1} ${e.v + 1}`);
}

process.stdout.write(output.join('\n'));
