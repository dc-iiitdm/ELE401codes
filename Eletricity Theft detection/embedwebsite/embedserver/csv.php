<?php
include "config.php";
$i = 0; 
$csv_output =' ';
$link = mysql_connect($host, $user, $password) or die("Can not connect." . mysql_error());
mysql_select_db($db_name) or die("Can not connect.");
 
$csv_output = "id".";";
$csv_output .= "temperature".";";
$csv_output .= "date".";";
$csv_output .= "time".";";
$csv_output .= "ip".";";
$csv_output .= "\n";
 
$values = mysql_query("SELECT * FROM ".$table."");

while ($rowr = mysql_fetch_row($values)) {
	$csv_output .= $rowr[0].";";
	$csv_output .= $rowr[1].";";
	$csv_output .= date('d.m.Y',strtotime($rowr[2])).";";
	$csv_output .= date('H:i:s',strtotime($rowr[2])).";";
	$csv_output .= long2ip($rowr[3]).";";
	$csv_output .= "\n";
}
 
$filename = $file."_".date("Y-m-d_H-i",time());
header("Content-type: application/vnd.ms-excel");
header("Content-disposition: csv" . date("Y-m-d") . ".csv");
header("Content-disposition: filename=".$filename.".csv");
print $csv_output;
$error = mysql_error();
print($error);
exit;
?>