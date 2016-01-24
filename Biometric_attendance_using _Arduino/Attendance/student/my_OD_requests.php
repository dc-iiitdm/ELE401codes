
<!DOCTYPE html>
<html>

<body>
  <?php

    include 'mainmenu.php';

    echo"
    <form name='OD' action='#' method='post'>
      <br><br><br><br><table align = 'center'>
      <center><font color = Blue><b>Fill in details to Request OD</center></font></b><br> 
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
          <td><input name='submit_OD' id = 'submit-btn' type='submit' value='Submit'/>
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
    if(isset($_POST['submit_OD']))
    {
      $_SESSION['date']=$_POST['date'];
      $date=$_SESSION['date'];
      $_SESSION['course']=$_POST['course'];
      $course=$_SESSION['course'];
      $rollno=$username;
      $con=mysqli_connect("localhost","root","root","attendance");


      $sql="INSERT INTO `OD_request` (`username`, `date`, `course_id`) VALUES ('$rollno', '$date', '$course')";

      if(mysqli_query($con,$sql))
        echo "<font color = Red><b><center> Request Submitted</center> </font>";

   
    }
  ?>

</body>
</html>