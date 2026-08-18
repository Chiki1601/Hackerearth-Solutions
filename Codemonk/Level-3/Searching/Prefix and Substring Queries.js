process.stdin.resume();
process.stdin.setEncoding("utf-8");

let input = "";

process.stdin.on("data", function (data) {
    input += data;
});

process.stdin.on("end", function () {
    main(input);
});

function main(input) {
    const tokens = input.trim().split(/\s+/);
    let ptr = 0;

    const N = Number(tokens[ptr++]);
    const Q = Number(tokens[ptr++]);

    let S = tokens[ptr++];

    const queries = [];

    // Read all queries first.
    // We need the final string to build the prefix-function tree.
    for (let i = 0; i < Q; i++) {
        const type = Number(tokens[ptr++]);

        if (type === 1) {
            const c = tokens[ptr++];
            S += c;

            queries.push({
                type: 1
            });
        } 
        else if (type === 2) {
            const x = Number(tokens[ptr++]);
            const y = Number(tokens[ptr++]);

            queries.push({
                type: 2,
                x: x,
                y: y,
                id: i
            });
        } 
        else {
            const p = Number(tokens[ptr++]);
            const l = Number(tokens[ptr++]);
            const r = Number(tokens[ptr++]);

            queries.push({
                type: 3,
                p: p,
                l: l,
                r: r,
                id: i
            });
        }
    }

    const M = S.length;

    // ------------------------------------------------------------
    // 1. Build Prefix Function
    // ------------------------------------------------------------

    const pi = new Int32Array(M + 1);

    for (let i = 2; i <= M; i++) {
        let j = pi[i - 1];

        while (j > 0 && S[i - 1] !== S[j]) {
            j = pi[j];
        }

        if (S[i - 1] === S[j]) {
            j++;
        }

        pi[i] = j;
    }

    // ------------------------------------------------------------
    // 2. Build Prefix Function Tree
    //
    // node i -> parent pi[i]
    // ------------------------------------------------------------

    const children = Array.from({ length: M + 1 }, () => []);

    for (let i = 1; i <= M; i++) {
        children[pi[i]].push(i);
    }

    // ------------------------------------------------------------
    // 3. Euler Tour
    //
    // Every subtree becomes a continuous interval:
    // [tin[node], tout[node]]
    // ------------------------------------------------------------

    const tin = new Int32Array(M + 1);
    const tout = new Int32Array(M + 1);

    let timer = 0;

    // Iterative DFS to avoid recursion stack overflow.
    const stack = [[0, 0]];

    while (stack.length > 0) {
        const top = stack[stack.length - 1];
        const node = top[0];
        const state = top[1];

        if (state === 0) {
            tin[node] = ++timer;
            top[1] = 1;

            // Add children in reverse order
            for (let i = children[node].length - 1; i >= 0; i--) {
                stack.push([children[node][i], 0]);
            }
        } else {
            tout[node] = timer;
            stack.pop();
        }
    }

    // ------------------------------------------------------------
    // 4. Binary Lifting for LCA
    // ------------------------------------------------------------

    const LOG = Math.ceil(Math.log2(M + 1)) + 1;

    const up = Array.from(
        { length: LOG },
        () => new Int32Array(M + 1)
    );

    for (let i = 0; i <= M; i++) {
        up[0][i] = pi[i];
    }

    for (let k = 1; k < LOG; k++) {
        for (let i = 0; i <= M; i++) {
            up[k][i] = up[k - 1][up[k - 1][i]];
        }
    }

    function lca(a, b) {
        if (a === b) {
            return a;
        }

        if (tin[a] <= tin[b] && tout[b] <= tout[a]) {
            return a;
        }

        if (tin[b] <= tin[a] && tout[a] <= tout[b]) {
            return b;
        }

        let node = a;

        for (let k = LOG - 1; k >= 0; k--) {
            const ancestor = up[k][node];

            if (
                !(tin[ancestor] <= tin[b] &&
                  tout[b] <= tout[ancestor])
            ) {
                node = ancestor;
            }
        }

        return pi[node];
    }

    // ------------------------------------------------------------
    // 5. Fenwick Tree
    //
    // Used for type-3 range counting.
    // ------------------------------------------------------------

    class Fenwick {
        constructor(n) {
            this.n = n;
            this.bit = new Int32Array(n + 1);
        }

        add(index, value) {
            while (index <= this.n) {
                this.bit[index] += value;
                index += index & -index;
            }
        }

        sum(index) {
            let result = 0;

            while (index > 0) {
                result += this.bit[index];
                index -= index & -index;
            }

            return result;
        }

        rangeSum(left, right) {
            if (left > right) return 0;

            return this.sum(right) - this.sum(left - 1);
        }
    }

    // ------------------------------------------------------------
    // 6. Prepare Type-3 queries
    //
    // An occurrence of prefix p ending at position e means:
    //
    // p is an ancestor of e
    //
    // Therefore:
    //
    // tin[p] <= tin[e] <= tout[p]
    //
    // and
    //
    // l + p - 1 <= e <= r
    //
    // This is a 2D range query.
    // ------------------------------------------------------------

    const type3 = [];

    for (const q of queries) {
        if (q.type === 3) {
            const leftEnd = q.l + q.p - 1;
            const rightEnd = q.r;

            // If the substring cannot fit, answer is 0.
            if (leftEnd > rightEnd) {
                q.empty = true;
                continue;
            }

            type3.push({
                x: rightEnd,
                y1: tin[q.p],
                y2: tout[q.p],
                id: q.id,
                sign: 1
            });

            type3.push({
                x: leftEnd - 1,
                y1: tin[q.p],
                y2: tout[q.p],
                id: q.id,
                sign: -1
            });
        }
    }

    // Sort rectangle queries by ending position.
    type3.sort((a, b) => a.x - b.x);

    // ------------------------------------------------------------
    // 7. Process positions using Fenwick Tree
    // ------------------------------------------------------------

    const answers = new Array(Q);

    const bit = new Fenwick(M + 1);

    let position = 1;

    for (const event of type3) {
        while (position <= event.x) {
            bit.add(tin[position], 1);
            position++;
        }

        const count =
            bit.rangeSum(event.y1, event.y2);

        if (answers[event.id] === undefined) {
            answers[event.id] = 0;
        }

        answers[event.id] += event.sign * count;
    }

    // Empty type-3 queries
    for (const q of queries) {
        if (q.type === 3 && q.empty) {
            answers[q.id] = 0;
        }
    }

    // ------------------------------------------------------------
    // 8. Answer queries in original order
    // ------------------------------------------------------------

    const output = [];

    for (const q of queries) {
        if (q.type === 2) {
            // LCA gives the longest common border.
            output.push(String(lca(q.x, q.y)));
        }
        else if (q.type === 3) {
            output.push(String(answers[q.id] || 0));
        }
    }

    process.stdout.write(output.join("\n"));
}
