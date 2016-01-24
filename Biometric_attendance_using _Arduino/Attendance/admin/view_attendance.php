
<!DOCTYPE html>
<html>

<body>
  <?php


  include 'mainmenu_admin.php';
  session_start();
  $username=$_SESSION['username'];
  $password=$_SESSION['password'];
  $con=mysqli_connect("localhost","root","root","attendance");
  $course_id = str_replace('admin_', '', $username);

  $sql="select * from login where username='$username' and password='$password'";
  $result = mysqli_query($con,$sql);
  // Mysql_num_row is counting table row
  $count=mysqli_num_rows($result);

  if($count!=1)
  {
    header("Location: http://localhost/Attendance/admin/login.php");
  }
  else
  {

    echo "<h4>View attendance by: </h4>"; 
    /*  include 'mainmenu_admin.php';*/
    include 'viewby.php';
  }   

  ?>

</body>
</html>
