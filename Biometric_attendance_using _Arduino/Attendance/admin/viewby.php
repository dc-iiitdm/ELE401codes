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
		border:2px solid green;
		border-collapse:collapse;
		text-align:center;
	}
	</style>
</head>

<body>

	<?
		$con=mysqli_connect("localhost","root","root","attendance");
		// Check connection
		if (mysqli_connect_errno())
  		{
  			echo "Failed to connect to MySQL: " . mysqli_connect_error();
  		}
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
		}

	?>
<!-- 	<form name='viewby' action="<?php echo $_SERVER['PHP_SELF'];?>" method='post'> -->
<!-- 	<form name='viewby' action="#" method='post'> -->
	<ul id="menu">
<!-- 	<center>
	<ld><a href="home.php">Date</a></ld>
	<ld><a href="courses.php">Roll no</a> </ld>
	<ld><a href="courses.php">All Students</a></ld>
	</center> -->
	<ld><a href="viewby_date.php">Date</a></ld>
	<ld><a href="viewby_student.php">Roll no</a> </ld>
	<ld><a href="viewby_all.php">All Students</a></ld>
<!-- 	</center> -->
	</ul>
<!-- 	</form>
 -->

</body>
</html>
