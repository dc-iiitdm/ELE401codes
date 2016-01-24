
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
        <td>Course</td>
        <td><input type='text' name='view_course' required></td>
      </tr>
        <td><input type='reset' value='Reset'/>
        <td><input name='viewby_course' id = 'submit-btn' type='submit' value='Submit'/>
                  
      </tr>
    </table>
  </form> ";

  if(isset($_POST['viewby_course']))     {

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
        $_SESSION['view_course']=$_POST['view_course'];
        $course=$_SESSION['view_course'];
    
        $con=mysqli_connect("localhost","root","root","attendance");
        if (mysqli_connect_errno())
        {
          echo "Failed to connect to MySQL: " . mysqli_connect_error();
        }

        $sql="select * from $course where username = '$username' order by date ";
        if($result = mysqli_query($con,$sql))
        {   
          $count=mysqli_num_rows($result);
          if($count > 0)
          {
            echo "<h4><center><font color = Red> Attendance for ".$course."</font></center></h4>";
            echo " <table align = 'center'>
            <tr>
            <td>Date</td>
            <td>Present</td>
            </tr>";
            while ($row = mysqli_fetch_array($result)) 
            {
              echo "<tr>";
              echo "<td>" . $row['date'] . "</td>";
              if($row['present'] == 0)
                echo "<td>" . "NO" . "</td>";
              else
                echo "<td>" . "YES" . "</td>";
              echo "</tr> ";
            }
            echo " </table>";
          }
          else
            echo "<b><center><font color = Red> You are not enrolled to this course </b></center></font>";
        }
        else
          echo "<b><center><font color = Red> $course is not offered </b></center></font>";        
      }
    }
  ?>

</body>
</html>