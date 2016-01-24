<?php
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING ^ E_DEPRECATED ^ E_STRICT);
$servername = "mysql.hostinger.in";
$username = "u513693101_root";
$password = "123456";
$dbname = "u513693101_root";

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

	$sql = "SELECT * from `status` WHERE field = 'esp'";
	$result = mysql_query($sql);

while($row = mysql_fetch_array($result))
{
	$out[]=$row;
}

print (json_encode($out));
mysql_close($conn);
?>