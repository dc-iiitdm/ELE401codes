<?php
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING ^ E_DEPRECATED ^ E_STRICT);
$servername = "mysql.hostinger.in";
$username = "u513693101_root";
$password = "123456";
$dbname = "u513693101_root";
$now = new DateTime();

$value = $_POST['value'];

$conn = mysql_connect($servername,$username,$password);
if (!$conn)
{
    die('Could not connect: ' . mysql_error());
}
$con_result = mysql_select_db($dbname, $conn);
if(!$con_result)
{
	die('Could not connect to specific database: ' . mysql_error());	
}
	$datenow = $now->format("Y-m-d H:i:s");

	//$sql = "INSERT INTO `stat`(`name`, `phone`, `email`) VALUES ('$name','$phone','$email')";
	$sql = "UPDATE `status` SET value = '$value', `logdata` = '$datenow' WHERE field = 'admin'";
	$result = mysql_query($sql);
	if (!$result) {
		die('Invalid query: ' . mysql_error());
	}
	echo "<h1>THE DATA HAS BEEN SENT!!</h1>";
	mysql_close($conn);
?>