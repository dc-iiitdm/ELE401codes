
<!DOCTYPE html>
<html>

<body>
  <?php
 include 'mainmenu.php';

 // session_start();
  $username=$_SESSION['username'];
  $password=$_SESSION['password'];

  $sql="select * from login where username='$username' and password='$password'";
  $result = mysqli_query($con,$sql);
  // Mysql_num_row is counting table row
  $count=mysqli_num_rows($result);

  if($count==1)
  {
    $row = mysqli_fetch_array($result);
    echo "<br><br><br><h3>Welcome ". $row['name']."</h3>";

  }
  else
  {
    header("Location: http://localhost/Attendance/student/login.php");
  }
  ?>

</body>
</html>