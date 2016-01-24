
<!DOCTYPE html>
<html>

<body>
<?php
 

  include 'mainmenu_admin.php';

  session_start();
  $username=$_SESSION['username'];
  $password=$_SESSION['password'];

  $sql="select * from login where username='$username' and password='$password'";
  $result = mysqli_query($con,$sql);
  // Mysql_num_row is counting table row
  $count=mysqli_num_rows($result);

  $course_id = str_replace('admin_', '', $username);

  if($count!=1)
  {
    header("Location: http://localhost/Attendance/admin/login.php");
  }
  else
  {
    $sql1 = "select max(date) from $course_id";
    $result1 = mysqli_query($con,$sql1);  
    $count1=mysqli_num_rows($result1);
    if($count1 > 0)
    {
      $row = mysqli_fetch_array($result1);
      $lastupdate = $row[0];
      echo "<h3><font color='red'>Last update was on: ".$lastupdate ."</font></h3> ";

    }
    echo "<h3><font color='blue'><center> Please ensure to name the text file: ".$course_id." </center></font></h3> ";
    echo "<form action='#' method='post' >";
    echo "<center><input type = \"submit\" name = \"update\" id = \"submit-btn\" value = \"Update Attendance\" <\center>";
    echo "</center></form>";

  }
?>
<?php
if(isset($_POST['update']))  
{ 
  $filename = $course_id.".txt";

  $myfile = fopen($filename, "r") or die("Unable to open file! Please put the file with filename as course_id: Eg: ELE_401");
  $sql2="select count(userid) as total_strength from student";
  $result2 = mysqli_query($con,$sql2);
  $row2 = mysqli_fetch_array($result2);
  $total_strength = $row2['total_strength'];
  $i = 0;
  $str = fgets($myfile,20);
  $flag = 0;
  while(!feof($myfile))
  {
    if($i % ($total_strength+1) == 0)
    { $date = $str; 
    }
    else 
    {
      $userid = $i % ($total_strength+1);
      $sql3="select rollno from student where userid = '$userid'";
      $result3 = mysqli_query($con,$sql3);
      $row3 = mysqli_fetch_array($result3);
      $rollno = $row3['rollno'];
      if($str == 1)
      {  
        $sql4="INSERT INTO `$course_id`(`username`, `date`, `present`, `MC_OD`) VALUES ('$rollno','$date',1,0)";
        if(mysqli_query($con,$sql4))   $flag = 1;
      }
      else
      {
        $sql4="INSERT INTO `$course_id`(`username`, `date`, `present`, `MC_OD`) VALUES ('$rollno','$date',0,0)";
        if(mysqli_query($con,$sql4))   $flag = 1;
      }
    }
    $i = $i + 1;
    $str = fgets($myfile,20);
  }
  fclose($myfile);  
  if($flag == 1)
    echo "<h3><font color='red'><center><b>Database updated! </center></font></h3>";

}
?>


</body>
</html>
