
<!DOCTYPE html>
<html>

<body>
  <?php
  include 'mainmenu.php';

  //  echo "<h4><center><br><br><br><br>View attendance by: </center></h4>";
  echo "<br><h4>View attendace by: </h4>"; 
  include 'my_viewby.php';
/*  <form name='login' action="<?php echo $_SERVER['PHP_SELF'];?>" method='post'>*/
  echo"
  <form name='login' action='#' method='post'>
    <table align = 'center'>
      <tr>
        <td>Date </td>
        <td><input type='text' name='view_date' required>yyyy-mm-dd</td>
      </tr>
        <td><input type='reset' value='Reset'/>
        <td><input name='viewby_date' id = 'submit-btn' type='submit' value='Submit'/>
                  
      </tr>
    </table>
  </form> ";

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
  if(isset($_POST['viewby_date']))   
  {
    $_SESSION['view_date']=$_POST['view_date'];
    $date=$_SESSION['view_date'];

    $con=mysqli_connect("localhost","root","root","attendance");
    // Check connection
    if (mysqli_connect_errno())
    {
      echo "Failed to connect to MySQL: " . mysqli_connect_error();
    }
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

        $sql5="select present from $course_id1 where date='$date' and username = '$username'";
        $result5 = mysqli_query($con,$sql5);
        $count5=mysqli_num_rows($result5);
        if($count5 > 0)
        {
          while ($row5 = mysqli_fetch_array($result5)) {
          if($row5['present'] == 1)
            $present1 = "YES";  
          else
            $present1 = "NO";        
          }
        }
        else
            $present1 = "No lecture";  

        $sql6="select present from $course_id2 where date='$date' and username = '$username'";
        $result6 = mysqli_query($con,$sql6);
        $count6=mysqli_num_rows($result6);
        if($count6 > 0)
        {
          while ($row6 = mysqli_fetch_array($result6)) {
          if($row6['present'] == 1)
            $present2 = "YES";  
          else
            $present2 = "NO";        
          }
        }
        else
            $present2 = "No lecture";  

        $sql7="select present from $course_id3 where date='$date' and username = '$username'";
        $result7 = mysqli_query($con,$sql7);
        $count7=mysqli_num_rows($result7);
        if($count7 > 0)
        {
          while ($row7 = mysqli_fetch_array($result7)) {
          if($row7['present'] == 1)
            $present3 = "YES";  
          else
            $present3 = "NO";        
          }
        }
        else
            $present3 = "No lecture"; 

        echo "<table align = 'center'>
        <center><font color = Blue><b>Your attendance on $date:</center></font></b><br> 
          <tr>
            <td><b>Course ID </td>
            <td><b>Course Name </td>
            <td><b>Present</td>
          </tr>
          <tr>
            <td>$course_id1</td>
            <td>$course_name1</td>
            <td>$present1</td>
          </tr>
          <tr>
            <td>$course_id2</td>
            <td>$course_name2</td>
            <td>$present2</td>

          </tr>
          <tr>
            <td>$course_id3</td>
            <td>$course_name3</td>
            <td>$present3</td>
          </tr>
        </table>";                       
      }
      else  //If data not available in student table
        echo "<font color = Red><center>You are not enrolled to any course </center></font>";
    }
  }
  ?>

</body>
</html>