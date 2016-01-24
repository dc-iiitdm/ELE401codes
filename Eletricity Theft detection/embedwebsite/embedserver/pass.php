<?php
include "config.php";
//Get variables
$data = $_GET['data'];
$check = $_GET['check'];
$ip = $_SERVER['REMOTE_ADDR'];
$ip = ip2long($ip);

//SQL syntax
$sql="INSERT INTO data (data,ip,ts) VALUES ($data,$ip,NOW())";


//Compare security key
if($check == $security){
	$con=mysqli_connect($host,$user,$password,$db_name);
	
	// Check connection
	if (mysqli_connect_errno()) {
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}

	// Execute query
	if (mysqli_query($con,$sql)) {
		echo "Data written";
		echo long2ip($ip);
	}
	//Error message
	else {
		echo "Error creating table: " . mysqli_error($con);
	}
}
?>