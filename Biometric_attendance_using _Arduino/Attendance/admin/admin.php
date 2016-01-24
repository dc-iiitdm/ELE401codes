
<!DOCTYPE html>
<html>

<body>
  <?php
  
  include 'mainmenu_admin.php';
    session_start();
//  $_SESSION['username']=$_POST['username'];
//  $_SESSION['password']=$_POST['password'];
  $username=$_SESSION['username'];
  $password=$_SESSION['password'];
  $course_id = str_replace('admin_', '', $username);
  $sql="select * from login where username='$username' and password='$password'";
  $result = mysqli_query($con,$sql);
  $count=mysqli_num_rows($result);

  if($count!=1)
  {
    header("Location: http://localhost/Attendance/admin/login.php");
  }
  else
  {
    $row = mysqli_fetch_array($result);
    echo "<br><br><br><h2>Welcome ". $row['name']."</h2>";
    $sql1 = "select * from OD_request where course_id = '$course_id'";
    $result1 = mysqli_query($con,$sql1);  
    $count1=mysqli_num_rows($result1);
    if($count1 > 0)
      echo "<h3><font color='red'><center>". $count1 . " OD request/requests waiting for approval</center></font></h3> ";

    $sql2 = "select * from MC_request where course_id = '$course_id'";
    $result2 = mysqli_query($con,$sql2);  
    $count2=mysqli_num_rows($result2);
    if($count2 > 0)
      echo "<h3><font color='red'><center>". $count2 . " MC request/requests waiting for approval</center></font></h3> ";
  }
  ?>

</body>
</html>