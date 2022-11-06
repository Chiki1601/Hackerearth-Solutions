<?php
/*
// Sample code to perform I/O:
fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
fscanf(STDIN, "%d\n", $t);
 
for ($i = 0; $i < $t; $i++) {
    if ($i != 0) { print "\n"; }
 
    fscanf(STDIN, "%d %d\n", $N, $M);
 
    $A = array_map('intval', fscanf(STDIN, str_repeat("%s ", $M - 1) . "%s\n"));
	// print "A: " . implode(",", $A) . "\n";
 
    sort($A);
    // print "sortedA: " . implode(",", $A) . "\n";
 
    $totalSchools = 0;
    for ($j = 0; $j < $M; $j++) {
        // print "N: " . $N . ", tot: " . $totalSchools . "\n";
        if ($N >= $A[$j]) {
            $N -= $A[$j];
            $totalSchools++;
        } else {
            break;
        }
    }
    print $totalSchools;
}
?>
