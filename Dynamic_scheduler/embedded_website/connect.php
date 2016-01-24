<?php


	$con=mysqli_connect("localhost","root","root","faculty_recruitment");
	if (mysqli_connect_errno($con))
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

?>