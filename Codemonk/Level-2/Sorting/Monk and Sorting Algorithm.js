process.stdin.resume();
process.stdin.setEncoding("utf-8");

let input = "";

process.stdin.on("data", function (data) {
    input += data;
});

process.stdin.on("end", function () {
    const data = input.trim().split(/\s+/);

    const n = Number(data[0]);

    // Keep numbers as strings so we don't lose digits
    let arr = data.slice(1, n + 1);

    let i = 1;
    let result = [];

    while (true) {
        const weighted = [];

        // Starting position from the right
        // i = 1 -> last 5 digits
        // i = 2 -> previous 5 digits
        const end = arr[0].length - (i - 1) * 5;
        let allZero = true;

        for (let j = 0; j < n; j++) {
            const num = arr[j];

            const endPos = num.length - (i - 1) * 5;
            const startPos = endPos - 5;

            let chunk = "";

            if (endPos > 0) {
                const start = Math.max(0, startPos);
                chunk = num.substring(start, endPos);
            }

            const weight = chunk === "" ? 0 : Number(chunk);

            if (weight !== 0) {
                allZero = false;
            }

            weighted.push({
                value: num,
                weight: weight,
                order: j
            });
        }

        // If every weight is 0, stop
        if (allZero) {
            break;
        }

        // Stable sort by weight
        // If weights are equal, preserve previous order
        weighted.sort((a, b) => {
            if (a.weight !== b.weight) {
                return a.weight - b.weight;
            }

            return a.order - b.order;
        });

        arr = weighted.map(item => item.value);

        result.push(arr.join(" "));

        i++;
    }

    process.stdout.write(result.join("\n"));
});
