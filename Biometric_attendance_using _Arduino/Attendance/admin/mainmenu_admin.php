<!DOCTYPE html>
<html>

<head>
    <link rel = "stylesheet" href = "navbar.css"/>
    <link rel = "stylesheet" href = "buttons.css"/>
	<style>
	table,th,td
	{
		align:center;
		padding:4px;
		border:2px solid blue;
		border-collapse:collapse;
		text-align:center;
	}
	</style>
</head>

<body>
	<center><img src="home.png" alt="some_text"></center>

	<?php         
		// this page consists of main menu which is included in every other page;            
		echo "<br><br>";
		// connect to the database iiitdm
		$con=mysqli_connect("localhost","root","root","attendance");
		// Check connection
		if (mysqli_connect_errno())
  		{
  			echo "Failed to connect to MySQL: " . mysqli_connect_error();
  		}
/*
  		session_start();
		$username=$_SESSION['username'];
		$password=$_SESSION['password'];
		$con=mysqli_connect("localhost","root","root","attendance");

		$sql="select * from login where username='$username' and password='$password'";
		$result = mysqli_query($con,$sql);
		// Mysql_num_row is counting table row
		$count=mysqli_num_rows($result);

		if($count!=1)
		{
		header("Location: http://localhost/Attendance/admin/login.php");
		}*/
	?>
	<ul id="menu">
	<li><a href="admin.php">Home</a></li>
	<li><a href="update_attendance.php">Update Attendance </a> </li>
	<li><a href="view_attendance.php">View Attendance</a></li>
	<li><a href="approve_OD.php">Approve OD</a></li>
	<li><a href="approve_MC.php">Approve MC</a></li>
	<li><a href="logout.php">Logout</a></li> 
	</ul>
	<br><br>

</body>
</html>
