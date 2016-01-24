<?php include 'header1.php'; ?>
<?php include 'tab_style.php'; ?>
 <?php
     function curPageURL()
     {
         $pageURL = 'http';
         if (isset( $_SERVER["HTTPS"] ) && strtolower( $_SERVER["HTTPS"] ) == "on" ) {$pageURL .= "s";}
         $pageURL .= "://";
         if ($_SERVER["SERVER_PORT"] != "80") {
             $pageURL .=
             $_SERVER["SERVER_NAME"].":".$_SERVER["SERVER_PORT"].$_SERVER["REQUEST_URI"];
         }
         else {
             $pageURL .= $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"];
         }
         return $pageURL;
     }

     $pageurl =curPageURL();

     $arr = explode("/",$pageurl);
 ?>


<div class="row">
	<div class="col-md-12 text-center">
  <ul class="nav nav-tabs nav-justified">

  <?php 
  if($arr[sizeof($arr)-1]=="form1.php" or $arr[sizeof($arr)-1]=='form1.php?a=1')
    {?>

    <li class="active"><a href="form1.php">Waiting List</a></li>
    <?php
    }
  else
    {?>
    <li><a href="form1.php">Waiting List</a></li>
    <?php
    }?>


    <?php 
  if($arr[sizeof($arr)-1]=="form2.php" or $arr[sizeof($arr)-1]=='form2.php?a=1')
    {?>

    <li class="active"><a href="form2.php">Register</a></li>
    <?php
    }
  else
    {?>
    <li><a href="form2.php">Register</a></li>
    <?php
    }?>



    <?php
    if($arr[sizeof($arr)-1]=="form3.php" or $arr[sizeof($arr)-1]=='form3.php?a=1')
    {?>
    <li class="active"><a href="form3.php">feedback from Registration</a></li>
    <?php
    }
  else
    {?>
    <li><a href="form3.php">feedback from Registration</a></li>
    <?php
    }?>



    <?php
    if($arr[sizeof($arr)-1]=="logout.php")
    {?>

    <li class="active"><a href="logout.php">Logout</a></li>
    <?php
    }
    else
    {?>
    <li><a href="logout.php">Logout</a></li>
    <?php
    }?>
	<!--<li><a href="../pdf_final.php">Submit</a></li>-->
  </ul>
</div>
</div>
<br/>
