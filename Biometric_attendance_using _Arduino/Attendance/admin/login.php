<!DOCTYPE html>
<html>
<head>
  <link rel = "stylesheet" href = "buttons.css"/>
  <style>
  table,th,td
  {
    width:350px; 
    padding:4px;
    border:2px solid blue;
    border-collapse:collapse;
    text-align:center;
  }
  </style>
</head>
<body>
  <center><img src="home.png" alt="some_text"></center>
  <br><br><br><br>

  <h2><center> Attendance Portal Login </center></h2> 
  <form name='login' action="<?php echo $_SERVER['PHP_SELF'];?>" method='post'>
    <table align = "center">
      <tr>
        <td> Username </td>
        <td><input type="text" name="username" required></td>
      </tr>
      <tr>
        <td> Password </td>
        <td><input type="password" name="password" required></td>
      </tr>
      <tr>
        <td><input type="reset" value="Reset"/>
        <td><input name="submit" id = "submit-btn" type="submit" value="Submit"/>
                  
      </tr>
    </table>
  </form>

  <form name='ch_pass' action="chg_pass.php" method='post'>
  </br>
  <center>
   <input name = "change_password" type = "submit" id = "submit-btn" value = "Change Password"/>
  </center>

  </form>

  <?php
    /*if($_SESSION['PASS_SUCCESS'] == 1) {
      echo "<br><br><b><center> PASSWORD CHANGED </center></b><br><br>";
    }*/
    if(isset($_POST['submit']))      {
      session_start();
      $_SESSION['username']=$_POST['username'];
      $_SESSION['password']=$_POST['password'];
      $username=$_SESSION['username'];
      $password=$_SESSION['password'];
  
      $con=mysqli_connect("localhost","root","root","attendance");
      // Check connection
      if (mysqli_connect_errno())
      {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
      } 
      $sql="select * from login where username='$username' and password='$password'";
      $result = mysqli_query($con,$sql);
      // Mysql_num_row counts table row
      $count=mysqli_num_rows($result);
      
      if($count==1)
      {
        $row = mysqli_fetch_array($result);
        if($row['admin'] == 1)
          header("Location: http://localhost/Attendance/admin/admin.php");          
      }
      else
      {
        echo "<br><br><b><font color='red'><center>Invalid username or Password</center></font></b>";
      }
    }
   ?>

</body>
</html>



