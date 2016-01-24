
<!DOCTYPE html>
<html>

<body>
<?php
 
  include 'mainmenu.php';

  $username=$_SESSION['username'];
  $password=$_SESSION['password'];

  $sql="select * from login where username='$username' and password='$password'";
  $result = mysqli_query($con,$sql);
  // Mysql_num_row is counting table row
  $count=mysqli_num_rows($result);

  if($count!=1)
  {
    header("Location: http://localhost/Attendance/student/login.php");
  }

  else
  {

    echo "<br><h4>View attendace by: </h4>"; 
    include 'my_viewby.php';
  }   


    
?>

</body>
</html>