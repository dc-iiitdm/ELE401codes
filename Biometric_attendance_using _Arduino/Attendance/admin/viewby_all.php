

<!DOCTYPE html>
<html>

<body>
  <?php
  include 'view_attendance.php';
  $sql1 = " SELECT `username`, count(`present`) as count FROM $course_id WHERE 1 GROUP BY `username` ";
  $result1 = mysqli_query($con,$sql1);  
  $count1=mysqli_num_rows($result1);

  $sql7b = " SELECT `username`,count(`present`) as present FROM $course_id where present = '1' GROUP BY `username` ";
  $result7b = mysqli_query($con,$sql7b);  
  $count7b=mysqli_num_rows($result7b);

  $row1 = mysqli_fetch_array($result1);


  if($count1 > 0)
  {
    echo"
    <form name='login' action='#' method='post'>
    <table align = 'center'>
    <tr>
    <td>Roll No </td>
    <td>Total Attendance </td>
    </tr>";
    while($row2 = mysqli_fetch_array($result7b))
    {

      echo "<tr>";
      echo "<td>" . $row2['username'] . "</td>";
      echo "<td>" . $row2['present']."/".$row1['count'] . "</td>";
      echo "</tr>";

    } 
    echo "
    </table>
    </form> ";
  }
  else
    echo "<center><font color = Red> No data available for this class/course. </font></center>";

  ?>

</body>
</html>