<?php
include "config.php";

$con=mysqli_connect($host,$user,$password,$db_name);
//SQL syntax
$sql="CREATE TABLE data ( ID int NOT NULL AUTO_INCREMENT PRIMARY KEY , data varchar(5) , ts timestamp(6) , ip varchar(12) NOT NULL )";

if (mysqli_query($con,$sql)) {
	echo "Table created successfully";
}

else {
	echo "Error creating table: " . mysqli_error($con);
//Error message
}
/*
// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

// Create database
$sql="CREATE DATABASE electricity";
if (mysqli_query($con,$sql)) {
	echo "Database created successfully, ";
}

else {
	echo "Error creating database: " . mysqli_error($con);
}
*/
// Execute query

?>