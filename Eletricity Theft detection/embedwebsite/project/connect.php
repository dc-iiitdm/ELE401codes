<?php
/*
<!--
*************************************************

Establish a connection to MySQL database.

*************************************************
-->
*/
$con=mysqli_connect('localhost','root','',"electricity") or die("Could not connect".mysql_error());
//mysqli_select_db("electricity");
?>