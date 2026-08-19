'use strict';

const fs = require('fs');

const input = fs.readFileSync(0, 'utf8');

let idx = 0;

function nextInt() {
    while (idx < input.length) {
        const c = input.charCodeAt(idx);
        if (c > 32) break;
        idx++;
    }

    let sign = 1;

    if (input.charCodeAt(idx) === 45) { // '-'
        sign = -1;
        idx++;
    }

    let num = 0;

    while (idx < input.length) {
        const c = input.charCodeAt(idx);

        if (c < 48 || c > 57) break;

        num = num * 10 + (c - 48);
        idx++;
    }

    return num * sign;
}

const N = nextInt();

// Stack stores:
// value -> type of opening bracket
// index -> position of opening bracket

const stackValue = new Int32Array(N);
const stackIndex = new Int32Array(N);

let top = 0;

// Last position where a balanced substring cannot start.
// We use 0-based indexes.
let lastInvalid = -1;

let answer = 0;

for (let i = 0; i < N; i++) {
    const x = nextInt();

    // Opening parenthesis
    if (x > 0) {
        stackValue[top] = x;
        stackIndex[top] = i;
        top++;
    }

    // Closing parenthesis
    else {
        const type = -x;

        // No opening parenthesis available
        // OR wrong type of opening parenthesis
        if (top === 0 || stackValue[top - 1] !== type) {
            top = 0;
            lastInvalid = i;
            continue;
        }

        // Correctly close the latest opening parenthesis
        top--;

        let start;

        if (top === 0) {
            // Everything after lastInvalid is balanced so far
            start = lastInvalid + 1;
        } else {
            // Cannot cross the remaining unmatched opening bracket
            start = stackIndex[top - 1] + 1;
        }

        const length = i - start + 1;

        if (length > answer) {
            answer = length;
        }
    }
}

console.log(answer);
