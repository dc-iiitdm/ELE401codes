<?php
$servername = "mysql.hostinger.in";
$username = "u588040838_pru";
$password = "pruthvi";
$dbname = "u588040838_phone";

/*
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "line";
*/

$done = "yes"; //$_GET["finish"];

$con=mysqli_connect($servername, $username, $password, $dbname);
if (mysqli_connect_errno($con))
{
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
if($done == "yes")
{
	$retrieve = "SELECT * FROM waiting";
	$result = mysqli_query($con,$retrieve);
	$num_rows = mysqli_num_rows($result);

	while($row = mysqli_fetch_array($result))
  	{
		$sno[] = $row['sno'];
		$phone[] = $row['phone'];
  	}
  	mysqli_query($con,"delete from waiting");
  	$i = 1;
  	for($i=1;$i<$num_rows;$i++)
  	{
  		$query = "INSERT INTO waiting (sno,phone) VALUES ($i,'$phone[$i]')";
        mysqli_query($con,$query);
  	}
  	if($num_rows == 0){
  		echo "no one in row";
  	}
  	else if($num_rows == 1){
  		echo "the one in row is finished,no one else is waiting";
  	}
  	else
  	{
  		echo "next one is".$phone[1];
  	}
}
else
{
	echo "some problem in receiving data";
}
?>