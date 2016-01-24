
<!DOCTYPE html>
<html>

<body>
  <?php

  include 'mainmenu_admin.php';

  session_start();
  $username=$_SESSION['username'];
  $password=$_SESSION['password'];
  $course_id = 'ELE_401';
  $sql="select * from login where username='$username' and password='$password'";
  $result = mysqli_query($con,$sql);
  // Mysql_num_row is counting table row
  $count=mysqli_num_rows($result);
  if($count!=1)
  {
    header("Location: http://localhost/Attendance/admin/login.php");
  }
  else if(!isset($_POST['decline_request']) && !isset($_POST['accept_request'])) 
  {
    $sql1 = "select * from OD_request where course_id = '$course_id'";
    $result1 = mysqli_query($con,$sql1);  
    $count1=mysqli_num_rows($result1);
    if($count1 > 0){
    echo "<h4><center>OD Requests waiting for approval: </center></h4>";
    echo "<form action='#' method='post' >";
    echo "<table align='center'>
    <tr>

      <th> SELECT TO APPROVE </th>
      <th> ROLL NO </th>
      <th> DATE </th>
      <th> COURSE ID</th>
    </tr>";


    while($row1 = mysqli_fetch_array($result1))
    // each iteration of while loop corresponds to each record
    {
      $rollno = $row1['username'];
      echo "<tr>";
      echo "<td><input type='checkbox' name=$rollno value=$rollno ></input> </td>";
      echo "<td>" . $row1['username'] . "</td>";
      echo "<td>" . $row1['date'] . "</td>";
      echo "<td>" . $row1['course_id'] . "</td>";
      echo "</tr>";
    } 
  
    echo "</table>";
    echo "</br><center><input type = \"submit\" name = \"decline_request\" id = \"submit-btn\" value = \"Decline selected requests\">";//<\center>";
    echo "<input type = \"submit\" name = \"accept_request\" id = \"submit-btn\" value = \"Approve selected requests\" <\center>";
    echo "</form><br><br>";
    }
    else
      echo "<center><font color = Red><br><br><b>No requests waiting for approval </b> </font></center>";
   }
  ?>
  <?php
    if(isset($_POST['decline_request']))   // this is a login page where we check Faculty ID and password are matched with the database.If so directed to welcome.php page else error is shown.
    {
      echo "<h4><center>OD Requests waiting for approval: </center></h4>";

      $sql2 = "select * from OD_request where course_id = '$course_id'";
      $result2 = mysqli_query($con,$sql2);  
      $count2=mysqli_num_rows($result2);
      if($count2 > 0)
      {
        while ($row2 = mysqli_fetch_array($result2)) 
        {
          if(isset($_POST[$row2['username']]))
          {
            //echo "Delete username from table : ". $row2['username']; 
            $rollno1 = $row2['username'];
            $date1 = $row2['date'];
            $course_id1 = $row2['course_id'];
            $sql3 = "delete from OD_request where username = '$rollno1' AND date = '$date1' AND course_id = '$course_id1' ";    
            $result3 =  mysqli_query($con,$sql3); 
          }
        }
      }

      $sql4 = "select * from OD_request where course_id = '$course_id'";
      $result4 = mysqli_query($con,$sql4);  
      $count4=mysqli_num_rows($result4);
      if($count4 > 0)
      {
        echo "<form action='#' method='post' >";
        echo "<table align='center'>";
        //uncomment this. delete declined OD from the table.
        
        echo "<tr>
        <th> SELECT TO APPROVE </th>        
        <th> ROLL NO </th>
        <th> DATE </th>
        <th> COURSE ID</th>
        </tr>";

        while($row4 = mysqli_fetch_array($result4))
        // each iteration of while loop corresponds to each record
        {    
          $rollno = $row4['username'];
          echo "<tr>";
          echo "<td><input type='checkbox' name=$rollno value=$rollno ></input> </td>";
          echo "<td>" . $row4['username'] . "</td>";
          echo "<td>" . $row4['date'] . "</td>";
          echo "<td>" . $row4['course_id'] . "</td>";
          echo "</tr>";
        }
        echo "</table>";
        echo "</br><center><input type = \"submit\" name = \"decline_request\" id = \"submit-btn\" value = \"Decline selected requests\">";//<\center>";
        echo "<input type = \"submit\" name = \"accept_request\" id = \"submit-btn\" value = \"Approve selected requests\" <\center>";
        echo "</form><br><br>";
      } 
    }    
    if(isset($_POST['accept_request']))   // this is a login page where we check Faculty ID and password are matched with the database.If so directed to welcome.php page else error is shown.
    {
      echo "<h4><center>OD Requests waiting for approval: </center></h4>";
      $sql2 = "select * from OD_request where course_id = '$course_id'";
      $result2 = mysqli_query($con,$sql2);  
      $count2=mysqli_num_rows($result2);
      if($count2 > 0)
      {
        while ($row2 = mysqli_fetch_array($result2)) 
        {
          if(isset($_POST[$row2['username']]))
          {
            //echo "Delete username from table : ". $row2['username']; 
            $rollno1 = $row2['username'];
            $date1 = $row2['date'];
            $course_id1 = $row2['course_id'];
            $sql3a = "delete from OD_request where username = '$rollno1' AND date = '$date1' AND course_id = '$course_id1' ";    
            $result3a =  mysqli_query($con,$sql3a); 
            $sql3b = "INSERT INTO `ELE_401`(`username`, `date`, `present`, `MC_OD`) VALUES ('$rollno1', '$date1', '1', '2')";    
            $result3b =  mysqli_query($con,$sql3b); 
          }
        }
      }

      $sql4 = "select * from OD_request where course_id = '$course_id'";
      $result4 = mysqli_query($con,$sql4);  
      $count4=mysqli_num_rows($result4);
      if($count4 > 0)
      {
        echo "<form action='#' method='post' >";
        echo "<table align='center'>";
        //uncomment this. delete declined OD from the table.
        
        echo "<tr>
        <th> SELECT TO APPROVE </th>        
        <th> ROLL NO </th>
        <th> DATE </th>
        <th> COURSE ID</th>
        </tr>";

        while($row4 = mysqli_fetch_array($result4))
        // each iteration of while loop corresponds to each record
        {    
          $rollno = $row4['username'];
          echo "<tr>";
          echo "<td><input type='checkbox' name=$rollno value=$rollno ></input> </td>";
          echo "<td>" . $row4['username'] . "</td>";
          echo "<td>" . $row4['date'] . "</td>";
          echo "<td>" . $row4['course_id'] . "</td>";
          echo "</tr>";
        }
        echo "</table>";
        echo "</br><center><input type = \"submit\" name = \"decline_request\" id = \"submit-btn\" value = \"Decline selected requests\">";//<\center>";
        echo "<input type = \"submit\" name = \"accept_request\" id = \"submit-btn\" value = \"Approve selected requests\" <\center>";
        echo "</form><br><br>";
      } 
    }    
  ?>



</body>
</html>