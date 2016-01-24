<?php
include("connect.php");
//require("includes/functions.php");
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
    <title>Online Examination Portal</title>
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
<div class="text-right">
            <form class="navbar-form" action="index.php" method="post"  ><span style="color:white;padding:5px;" >Hello Mr. Guest </span> 
            </div>
</div>
</nav>
<h1> Department of Electricity</h1>
<h3>Welcome</h3>
</div>