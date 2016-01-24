
<!DOCTYPE html>
<html>

<body>
  <?php

    include 'mainmenu.php';

    echo"
    <form name='MC' action='#' method='post'>
      <br><br><br><br><table align = 'center'>
      <center><font color = Blue><b>Fill in details to Request Medical Leave</center></font></b><br> 
        <tr>
          <td><b>Date </td>
          <td><input type='text' name='date' required></td>
        </tr>
        <tr>
          <td><b>Course </td>
          <td><input type='text' name='course' required></td>
        </tr>
        <tr>
          <td><input type='reset' value='Reset'/>
          <td><input name='submit_MC' id = 'submit-btn' type='submit' value='Submit'/>
        </tr>
      </table>
    </form> ";

    $username=$_SESSION['username'];
    $password=$_SESSION['password'];
    $sql="select * from login where username='$username' and password='$password'";
    $result = mysqli_query($con,$sql);
    $count=mysqli_num_rows($result);
    if($count!=1)
    {
      header("Location: http://localhost/Attendance/student/login.php");
    } 
    else
    if(isset($_POST['submit_MC']))
    {

      $_SESSION['date']=$_POST['date'];
      $date=$_SESSION['date'];
      $_SESSION['course']=$_POST['course'];
      $course=$_SESSION['course'];
      $rollno=$username;
      $con=mysqli_connect("localhost","root","root","attendance");

      if (mysqli_connect_errno())
      {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
      }

      $sql="INSERT INTO `MC_request` (`username`, `date`, `course_id`) VALUES ('$rollno', '$date', '$course')";

      if(mysqli_query($con,$sql))
        echo "<font color = Red><b><center> Request Submitted</center> </font>";
   
    }
  ?>

</body>
</html>