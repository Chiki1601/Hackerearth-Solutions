<?php
	/*
	// Sample code to perform I/O:
	fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
	echo "Hi, ".$name.".\n";                // Writing output to STDOUT
	// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
	*/
 
	// Write your code here
	fscanf(STDIN, "%d %d %d\n", $l, $r, $k);
	$res = 0;
	for ($i = $l; $i <= $r; $i++) {
		if ($i % $k == 0) {
			$res++;
			$i = $i + $k - 1;
		}
	}
	echo $res;
?>
