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
		if (mysqli_connect_errno())
  		{
  			echo "Failed to connect to MySQL: " . mysqli_connect_error();
  		}
	?>
	<ul id="menu">
	<ld><a href="my_viewby_date.php">Date</a></ld>
	<ld><a href="my_viewby_course.php">Course</a> </ld>
	<ld><a href="my_viewby_summary.php">Summary</a></ld>
	</ul>
	<br><br>

</body>
</html>
