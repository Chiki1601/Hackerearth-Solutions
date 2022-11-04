process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
function main(input) {
    input = input.split('\n');
    var line = 0, T = parseInt(input[line++]);
    while (T--) {
        var [N, M] = input[line++].split(' ').map(Number);
        var A = new Array(N);
        for (var i = 0; i < N; i++)
            A[i] = input[line++].split(' ').map(Number);
        
        var length = new Array(N);
        for (var i = 0; i < N; i++)
            length[i] = new Array(M).fill(0);
        length[0][0] = 1;
        
        var result = 0;
        for (var i = 0; i < N; i++)
            for (var j = 0; j < M; j++)
                if (length[i][j]) {
                    if (i + 1 < N && A[i][j] < A[i + 1][j])
                        length[i + 1][j] = Math.max(length[i + 1][j], length[i][j] + 1);
                    if (j + 1 < M && A[i][j] < A[i][j + 1])
                        length[i][j + 1] = Math.max(length[i][j + 1], length[i][j] + 1);
                    result = Math.max(result, length[i][j]);
                }
        console.log(result);
    }
}
