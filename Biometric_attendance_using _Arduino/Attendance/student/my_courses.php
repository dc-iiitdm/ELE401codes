
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
    $sql1="select course_id1,course_id2,course_id3 from student where rollno='$username' ";
    $result1 = mysqli_query($con,$sql1);
    $count1=mysqli_num_rows($result1); 
    if($count1 > 0)
    {
      $row = mysqli_fetch_array($result1);

      $course_id1 = $row['course_id1'];
      $sql2 = "SELECT course_name FROM `courses` WHERE course_id = '$course_id1'";
      $result2 = mysqli_query($con,$sql2);
      $row1 = mysqli_fetch_array($result2);
      $course_name1 = $row1['course_name'];  

      $course_id2 = $row['course_id2'];
      $sql3 = "SELECT course_name FROM `courses` WHERE course_id = '$course_id2'";
      $result3 = mysqli_query($con,$sql3);
      $row2 = mysqli_fetch_array($result3);
      $course_name2 = $row2['course_name']; 

      $course_id3 = $row['course_id3'];
      $sql4 = "SELECT course_name FROM `courses` WHERE course_id = '$course_id3'";
      $result4 = mysqli_query($con,$sql4);
      $row3 = mysqli_fetch_array($result4);
      $course_name3 = $row3['course_name']; 

      echo "<br><br><br><br><table align = 'center'>
      <center><font color = Blue><b>Courses you are enrolled to:</center></font></b><br> 
        <tr>
          <td><b>Course ID </td>
          <td><b>Course Name </td>
        </tr>
        <tr>
          <td>$course_id1</td>
          <td>$course_name1</td>
        </tr>
        <tr>
          <td>$course_id2</td>
          <td>$course_name2</td>
        </tr>
        <tr>
          <td>$course_id3</td>
          <td>$course_name3</td>
        </tr>
      </table>";

    }
    else 
      echo "<font color = Red><center>You are not enrolled to any course </center></font>";

  }   


    
?>

</body>
</html>