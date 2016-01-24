
<!DOCTYPE html>
<html>

<body>
<?php
//  include 'mainmenu_admin.php';
  include 'view_attendance.php';

/*  echo "
  <h4><br><br><br><br>View attendance by: </h4>";
  include 'view_by.php';
*/
  echo "<form name='login' action='#' method='post'>
  <table align = 'center'>
  <tr>
  <td>Roll No </td>
  <td><input type='text' name='rollno' required></td>
  </tr>
  <td><input type='reset' value='Reset'/>
  <td><input name='submit_student' id = 'submit-btn' type='submit' value='Submit'/>
    
  </tr>
  </table>
</form> ";
  ?>
   <?php
    if(isset($_POST['submit_student']))   // this is a login page where we check Faculty ID and password are matched with the database.If so directed to welcome.php page else error is shown.
    {
      //session_start();
      $_SESSION['rollno']=$_POST['rollno'];
      $rollno=$_SESSION['rollno'];
  
      $con=mysqli_connect("localhost","root","root","attendance");
      // Check connection
      if (mysqli_connect_errno())
      {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
      }
      $sql="select * from ELE_401 where username='$rollno'";
      $result = mysqli_query($con,$sql);
      // Mysql_num_row counts table row
      $count=mysqli_num_rows($result);
      if($count > 0)
      {

        echo " <table align = 'center'>
        <tr>
        <td>Roll No </td>
        <td>Date </td>
        <td>Present</td>
        </tr>";
        while ($row = mysqli_fetch_array($result)) {
        echo "<tr>";
        echo "<td>" . $row['username'] . "</td>";
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
        echo "<center><font color = Red> No data available for this roll no. </font></center>";

    }
  ?>

</body>
</html>