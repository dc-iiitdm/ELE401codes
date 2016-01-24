<?php
//require("includes/functions.php");
include("connect.php");
/*
<!--
*************************************************

It is the header file of the entire project.Also  Shows navigation links to other pages based on the user.

*************************************************
-->
*/


?>
<!DOCTYPE html>
<html lang="en" >
<head>
    <title>IIITDM</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="css/bootstrap.css" rel="stylesheet" media="screen" >
    <link href="css/bootstrap-responsive.css" rel="stylesheet" media="screen" >
    <link href="css/docs.css" rel="stylesheet" media="screen"  media="screen" >
    <link href="css/prettify.css" rel="stylesheet" media="screen" >
    <link rel="stylesheet" href="css/style.css" type="text/css"  media="screen" >
    
   <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.4.4/jquery.min.js"></script>
    <script type="text/javascript" src="js/check_browser_close.js"></script>
  

<style>
      html,
      body {
        height: 96.8%;
        /* The html and body elements cannot have any padding or margin. */
      }

      /* Wrapper for page content to push down footer */
      #wrap {
        min-height: 100%;
        height: auto !important;
        height: 100%;
        /* Negative indent footer by it's height */
        margin: 0 auto -60px;
      }

      /* Set the fixed height of the footer here */
      #push,
      #footer {
        height: 60px;
      }
      #footer {
        background-color: #f5f5f5;
      }

      /* Lastly, apply responsive CSS fixes as necessary */
      @media (max-width: 767px) {
        #footer {
          margin-left: -20px;
          margin-right: -20px;
          padding-left: 20px;
          padding-right: 20px;
        }
      }
    
      #wrap > .container {
        padding-top: 60px;
      }
      .container .credit {
        margin: 20px 0;
      }

</style>
</head>
<body>
<div id="wrap" >
<div class="container">
<div class="row-fluid text-center">
<nav class="navbar navbar-inverse navbar-fixed-top">
<a class="navbar-brand" href="#">Department of Electricity</a>
<div class="text-right">
            <form class="navbar-form" action="index.php" method="post"  ><span style="color:white;padding:5px;" >Hello,<?php echo $_SESSION['name'];?> </span> <input type="submit" class="btn btn-warning" name="logout" value="LogOut" ></form>
            </div>
</div>
</nav>
</div>

<?php
if($_POST['logout'])
  {
    session_destroy();
    echo '<script>window.location="index.php";</script>';   //////Reddirect the use to homepage

  }

/////////////////form to fill the login data------start///////////////////////
?>
<div class="row-fluid text-center" >
<div class="panel panel-primary">
  <!-- Default panel contents -->
  <div class="panel-heading ">Chennai Area</div>
</div>
  <!-- Table -->
  <div class="row">
  <div class="col-md-4 col-md-offset-4">
  <table style="width:100%;border: 2px solid black">
  <tr> 
    <td>
    <?php 
    //$con=mysql_connect('localhost','root','') or die("Could not connect".mysql_error());
    //mysql_select_db("electricity");
    if(mysqli_connect_errno())
      echo "error";
    //else echo "connected";
    $sql="SELECT value from data where tag='10000'";
    $node0_elec=mysqli_fetch_array(mysqli_query($con,$sql));
    //var_dump($node1_elec);
    $node1_elec=mysqli_fetch_array(mysqli_query($con,"SELECT value from data where tag='10001'"));
    $node2_elec=mysqli_fetch_array(mysqli_query($con,"SELECT value from data where tag='10010'"));
    $node3_elec=mysqli_fetch_array(mysqli_query($con,"SELECT value from data where tag='10011'"));
    //var_dump($node1_elec);
    $node4_elec=mysqli_fetch_array(mysqli_query($con,"SELECT value from data where tag='10100'"));
    $node5_elec=mysqli_fetch_array(mysqli_query($con,"SELECT value from data where tag='10101'"));
    $node6_elec=mysqli_fetch_array(mysqli_query($con,"SELECT value from data where tag='10110'"));
  
   
    //echo $node3_elec[0],$node2_elec[0],$node1_elec[0],$node2_elec[0]+$node3_elec[0];
    $node0=(double)$node0_elec[0];
    $node1=(double)$node1_elec[0];
    $node2=(double)$node2_elec[0];
    $node3=(double)$node3_elec[0];
    $node4=(double)$node4_elec[0];
    $node5=(double)$node5_elec[0];
    $node6=(double)$node6_elec[0];
  //echo gettype($node1),gettype($node2n3);
   // echo $node0.'<>'.$node1.'<>'.$node2.'<>'.$node3.'<>'.$node4.'<>'.$node5.'<>'.$node6;
    //echo gettype($node0).'<>'.gettype($node1).'<>'.gettype($node2).'<>'.gettype($node3).'<>'.gettype($node4).'<>'.gettype($node5).'<>'.gettype($node6);
    $zero=0.0000001;
    if(($node0-($node1+$node2+$node3)<$zero) && (($node4-$node1)<$zero) && (($node5-$node2)<$zero) && (($node6-$node3)<$zero)) 
    {
     // echo "condn1";
      echo'</td>';
      echo '<td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td>
          <td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td></tr>
          <tr><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td></tr>
           <tr><td></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td></tr>';
         
    }
    else
      {
        if(($node0-($node1+$node2+$node3)<$zero) && (($node4-$node1)>$zero) && (($node5-$node2)<$zero) && (($node6-$node3)<$zero))
            {
           // echo "condn2";
              echo'</td>';
           echo '<td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td>
          <td><img src="public/red.png" alt="Node" style="height:100px;width:100px;"></td></tr>
          <tr><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td></tr>
           <tr><td></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td></tr>';
            }
        else {
            if(($node0-($node1+$node2+$node3)<$zero) && (($node4-$node1)<$zero) && (($node5-$node2)>$zero) && (($node6-$node3)<$zero))
            {//echo "condn3";
              echo'</td>';
            echo '<td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td>
           <td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td></tr>
           <tr><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/red.png" style="height:100px;width:100px;"></td></tr>
           <tr><td></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td></tr>';
           }
           else {
                  if(($node0-($node1+$node2+$node3)<$zero) && (($node4-$node1)<$zero) && (($node5-$node2)<$zero) && (($node6-$node3)>$zero))
                      {
                        echo'</td>';
            echo '<td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td>
           <td><img src="public/green.png" alt="Node" style="height:100px;width:100px;"></td></tr>
           <tr><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/green.png" style="height:100px;width:100px;"></td></tr>
           <tr><td></td><td><img src="public/green.png" style="height:100px;width:100px;"></td><td><img src="public/red.png" style="height:100px;width:100px;"></td></tr>';
          

                      }/*
                    else
                    {
                      if(($node0-($node1+$node2+$node3)<$zero) && (($node1-$node4)>$zero) && (($node2-$node5)<$zero) && (($node3-$node6)<$zero))
                        {}
                      else
                        {
                           if(($node0-($node1+$node2+$node3)<$zero) && (($node1-$node4)>$zero) && (($node2-$node5)<$zero) && (($node3-$node6)<$zero))
                              {}
                            else
                            {}

                        }

                    }*/
           } 
      }   
      } 
  
    ?>
    
  
  </table>

  </div>
  </div>

  <div class="row">
  <div class="col-md-4 col-md-offset-2">
  <table>
    <style type="text/css">
    table, th, td {
    border: 1px solid black;
     }
    </style>
    <tr><th>Tag</th><th>Rms Current</th></tr>
    <?php  
    $sql=mysqli_query($con,"SELECT tag,temp from temperature");

    while($value=mysqli_fetch_array($sql))
    {
                            //var_dump($value);
      echo '<tr><td>'.$value[0].'</td><td>'.$value[1].'</td></tr>';
                                                      
                                                      }
    ?>
  </table>
  </div>
    


    <div class="col-md-3 col-md-offset-2">
  <table>
    <style type="text/css">
    table, th, td {
    border: 1px solid black;
     }
    </style>
    <tr><th>Tag</th><th>Temperature</th></tr>
    <?php  
    $sql=mysqli_query($con,"SELECT tag,temp from temperature");

    while($value=mysqli_fetch_array($sql))
    {
                            //var_dump($value);
      echo '<tr><td>'.$value[0].'</td><td>'.$value[1].'</td></tr>';
                                                      
                                                      }
    ?>
  </table>
  </div>

  </div>

</div>


<?php

  require("footer.php");
?>