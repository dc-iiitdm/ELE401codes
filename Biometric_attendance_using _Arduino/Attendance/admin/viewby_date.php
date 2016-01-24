
<!DOCTYPE html>
<html>

<body>
  <?php
//  include 'mainmenu_admin.php';
  include 'view_attendance.php';

  //  echo "<h4><center><br><br><br><br>View attendance by: </center></h4>";
//  echo "<h4><br><br><br><br>View attendance by: </h4>"; 
//  include 'viewby.php';
/*  <form name='login' action="<?php echo $_SERVER['PHP_SELF'];?>" method='post'>*/
  echo"
  <form name='login' action='#' method='post'>
    <table align = 'center'>
      <tr>
        <td>Date </td>
        <td><input type='text' name='date' required>yyyy-mm-dd</td>
      </tr>
        <td><input type='reset' value='Reset'/>
        <td><input name='submit_date' id = 'submit-btn' type='submit' value='Submit'/>
                  
      </tr>
    </table>
  </form> ";

  if(isset($_POST['submit_date']))   
  {
      $_SESSION['date']=$_POST['date'];
      $date=$_SESSION['date'];
  
      $con=mysqli_connect("localhost","root","root","attendance");
      // Check connection
      if (mysqli_connect_errno())
      {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
      }

      $sql="select * from ELE_401 where date='$date'";
      $result = mysqli_query($con,$sql);
      // Mysql_num_row counts table row
      $count=mysqli_num_rows($result);
      if($count > 0)
      {
    

        echo " <table align = 'center'>
        <tr>
        <td>Date </td>
        <td>Roll No </td>
        <td>Present</td>
        </tr>";
        while ($row = mysqli_fetch_array($result)) {
        echo "<tr>";
        echo "<td>" . $row['date'] . "</td>";
        echo "<td>" . $row['username'] . "</td>";
        if($row['present'] == 0)
          echo "<td>" . "NO" . "</td>";
        else
          echo "<td>" . "YES" . "</td>";
        echo "</tr> ";
        }
        echo " </table>";

      }
      else 
        echo "<center><font color = Red> No data available for this Date. </font></center>";      
    }
  ?>

</body>
</html>