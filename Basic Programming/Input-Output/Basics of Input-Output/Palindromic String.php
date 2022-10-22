<?php
	/*
	// Sample code to perform I/O:
	fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
	echo "Hi, ".$name.".\n";                // Writing output to STDOUT
	// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
	*/
 
	// Write your code here
	fscanf(STDIN, "%s\n", $S);
	$res = true;
	for ($i = 0; $i <= strlen($S) / 2 - 1; $i++) {
		if ($S[$i] != $S[strlen($S) - $i - 1]) {
			$res = false;
			break;
		}
	}
	if ($res) {
		echo "YES";
	} else {
		echo "NO";
	}
?>
