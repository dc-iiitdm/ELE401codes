<?php
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "line";

$con=mysqli_connect($servername, $username, $password, $dbname);
if (mysqli_connect_errno($con))
{
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

	$retrieve = "SELECT * FROM waiting";
	$result = mysqli_query($con,$retrieve);
	$num_rows = mysqli_num_rows($result);

	while($row = mysqli_fetch_array($result))
  	{
		$sno[] = $row['sno'];
		$phone[] = $row['phone'];
  	}
  	if($num_rows == 0){
  		echo "no one in row";
  	}
  	else
  	{
  		echo "next one is ".$phone[0];
  	}
?>