<?php
 
/*
*   Problem Link - https://www.hackerearth.com/problem/algorithm/sherlock-and-date/
*/
 
 
fscanf(STDIN, "%s\n", $tc);
 
while(intval($tc--) > 0) {
	
	$input_date = fgets(STDIN);
	$date_time = new DateTime($input_date);
	$date_time->modify('-1 Day');
	echo $date_time->format('j F Y') . "\n";
	
}
 
?>
