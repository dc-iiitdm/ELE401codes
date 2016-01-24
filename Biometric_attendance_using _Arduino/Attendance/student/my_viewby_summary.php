
<!DOCTYPE html>
<html>

<body>
  <?php
  include 'mainmenu.php';
  echo "<br><h4>View attendace by: </h4>"; 
  include 'my_viewby.php';  

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

      $sql5 = " SELECT count(`present`) as Total_Attendance1 FROM $course_id1 where username = '$username' ";
      $result5 = mysqli_query($con,$sql5);  
      $count5=mysqli_num_rows($result5);
      if($count5 > 0)
      {
        $row4 = mysqli_fetch_array($result5);
        $total_attendance1 = $row4['Total_Attendance1'];  
      }
      $sql5b = " SELECT count(`present`) as Present1 FROM $course_id1 where username = '$username' and present = '1' ";
      $result5b = mysqli_query($con,$sql5b);  
      $count5b=mysqli_num_rows($result5b);
      if($count5b > 0)
      {
        $row4b = mysqli_fetch_array($result5b);
        $total_present1 = $row4b['Present1'];  
      }

      $sql6a = " SELECT count(`present`) as Total_Attendance2 FROM $course_id2 where username = '$username'  ";
      $result6a = mysqli_query($con,$sql6a);  
      $count6a=mysqli_num_rows($result6a);
      if($count6a > 0)
      {
        $row5a = mysqli_fetch_array($result6a);
        $total_attendance2 = $row5a['Total_Attendance2'];  
      }
      $sql6b = " SELECT count(`present`) as Present2 FROM $course_id2 where username = '$username' and present = '1' ";
      $result6b = mysqli_query($con,$sql6b);  
      $count6b=mysqli_num_rows($result6b);
      if($count6b > 0)
      {
        $row5b = mysqli_fetch_array($result6b);
        $total_present2 = $row5b['Present2'];  
      }

      $sql7 = " SELECT count(`present`) as Total_Attendance3 FROM $course_id3 where username = '$username'  ";
      $result7 = mysqli_query($con,$sql7);  
      $count7=mysqli_num_rows($result7);
      if($count7 > 0)
      {
        $row6 = mysqli_fetch_array($result7);
        $total_attendance3 = $row6['Total_Attendance3'];  
      }
      $sql7b = " SELECT count(`present`) as Present3 FROM $course_id3 where username = '$username' and present = '1' ";
      $result7b = mysqli_query($con,$sql7b);  
      $count7b=mysqli_num_rows($result7b);
      if($count7b > 0)
      {
        $row6b = mysqli_fetch_array($result7b);
        $total_present3 = $row6b['Present3'];  
      }

      echo "<table align = 'center'>
      <center><font color = Blue><b>Attendance summary of all courses you are enrolled to:</center></font></b><br> 
        <tr>
          <td><b>Course ID </td>
          <td><b>Course Name </td>
          <td><b>Total Attendance</td>
        </tr>
        <tr>
          <td>$course_id1</td>
          <td>$course_name1</td>
          <td>$total_present1/$total_attendance1</td>
        </tr>
        <tr>
          <td>$course_id2</td>
          <td>$course_name2</td>
          <td>$total_present2/$total_attendance2</td>

        </tr>
        <tr>
          <td>$course_id3</td>
          <td>$course_name3</td>
          <td>$total_present3/$total_attendance3</td>
        </tr>
      </table>";

    }
    else 
      echo "<font color = Red><center>You are not enrolled to any course </center></font>";
    

  }
  ?>

</body>
</html>