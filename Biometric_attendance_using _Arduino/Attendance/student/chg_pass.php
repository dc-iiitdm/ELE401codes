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
	</br>
	</br>
	</br>
	<?php
		$con=mysqli_connect("localhost","root","root","attendance");
		// Check connection
		if (mysqli_connect_errno())
  		{
  			echo "Failed to connect to MySQL: " . mysqli_connect_error();
  		}
		if(isset($_POST['chps_submit'])){
			$username = $_POST['username'];
			$password = $_POST['old_pass'];
      echo $username. "   ". $password;
			$sql="select * from login where username='$username' and password='$password'";
			$result = mysqli_query($con,$sql);
      $count=mysqli_num_rows($result);
      echo "count = ".$count;
			if($count != 1) {
				echo "<br><br><b><center> Invalid User </center></b><br><br>";
			}
			else if ($_POST['new_pass2'] != $_POST['new_pass1']) {
				echo "<br><br><b><center>Passwords don't match </center></b><br><br>";
			}
			else {
				$row = mysqli_fetch_array($result);
        $new_pass2 = $_POST['new_pass2'];
        $result1 = mysqli_query($con,"update login set password= '$new_pass2' where username='$username' ");
        if($result1 == TRUE) 
          {
            echo "DB updated successfully";
          }  
        else if($result1 == FALSE) echo "DB update failed";
        echo "result1 = ". $result1;
//            header("Location: http://localhost/Attendance/mainmenu.php");
			
      }
		}

	?>
	<center>
  	<form name='chps' action="chg_pass.php" method='post'>
    <table align = "center">
      <tr>
        <td> Username </td>
        <td><input type="text" name="username" required></td>
      </tr>
      <tr>
        <td> Password </td>
        <td><input type="password" name="old_pass" required></td>
      </tr>
      <tr>
        <td> New Password </td>
        <td><input type="password" name= "new_pass1" required></td>
      </tr>
      <tr>
        <td> Re-type Password </td>
        <td><input type="password" name= "new_pass2" required></td>
      </tr>
      <tr>
          <td><input name="chps_submit" id = "submit-btn" type="submit" value="Submit"/>   
      </tr>
    </table>
  </form>
  <form name='login' action="login.php" method='post'>
  </br>
  <center>
   <input name = "login again" type = "submit" id = "submit-btn" value = "Redirect to login page"/>
  </center>

  </form>
</center>

</body>

</html>