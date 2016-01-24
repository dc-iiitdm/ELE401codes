<?php
session_start();
/*
*************************************************

This page has code related to login. It authentictes the user as facuty or student and redirects to corresponding page.
It also starts the session.

*************************************************
*/
//include("header.php");
require("header.php");


/////////////////////////////when logout is clicked///////////////////////////////////////////////////
if($_POST['logout'])
  {
    
    echo '<script>window.location="index.php";</script>';   //////Reddirect the use to homepage
  	session_destroy();
  }
/////////////////////////////when logout is clicked///////////////////////////////////////////////////


/////////////////////////////when login is clicked////////////////////////////////////////////////////
if(isset($_POST['login']))
 {//////////Check for login credentials of students////////////////////////////////////////
 	$_SESSION['name']=$_SESSION['username'];
 	$_SESSION['password']=$_SESSION['password'];
 	echo '<script>window.location="main.php";</script>';
 }
////////////////redirecting faculty/student to correct page-------start//////////////
//else
{

/////////////////form to fill the login data------start///////////////////////
?>
<div class="row-fluid text-center" >
<br />
<h4><i class="icon-user"></i> User Login</h4>
<form action="index.php" method="post" name="UserLogin">
<table align=center >
<tr>
<td><input type="text" class="input-medium" name="username"  autocomplete="off" maxlength="9" placeholder="Your Username..."  required/></td>
</tr>
<tr>
<td><input type="password"  class="input-medium" autocomplete="on"  name="password" maxlength="15" placeholder="Your Password..."  required required/></td>
</tr>

<tr><td><label class="control-label" ><input type="checkbox"  class="checkbox" name="remember" value=1/> Remember me</label></td></tr>
<tr><td><a><input type="submit"  class="btn btn-primary" name="login" value="Login" /></a></td></tr>
</table>
</form>

<?php

/////////////////form to fill the login data --end///////////////////////
if(! isset($_POST['login']))
 {
 	
		{
			echo '<div class="alert fade in" ><button type="button" class="close" data-dismiss="alert" >&times;</button><strong>Sorry!!! </strong>Invalid username or password!</div>';
 		}
 }
echo '</div>';
}
  require("footer.php");
?>