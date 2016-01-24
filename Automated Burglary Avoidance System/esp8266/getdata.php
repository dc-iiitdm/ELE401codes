<?php

	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING ^ E_DEPRECATED ^ E_STRICT);
$servername = "mysql.hostinger.in";
$username = "u513693101_root";
$password = "123456";
$dbname = "u513693101_root";
$now = new DateTime();
$CRLF = "\n\r";

$fieldToGet = $_GET['field'];

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

/*
 *  Database was created with a table called "DataTable" and has
 *  a column called "field" and a column called "value" and a 
 *  column called "logdata"
 */
$sql = "SELECT * FROM `secure` ";
$result = mysql_query($sql);

if (!$result) {
	die('Invalid query: ' . mysql_error());
}
echo "<h1>THE DATA HAS BEEN RECEIVED!!</h1>";


while($row = mysql_fetch_array($result, MYSQL_ASSOC))
{
echo "timedate: " . $row["logdata"]. " - field: " . $row["field"]. " - value: " . $row["value"]. "<br>";
}

mysql_close($conn);
?>