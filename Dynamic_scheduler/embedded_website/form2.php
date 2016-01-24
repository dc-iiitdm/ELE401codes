<!--

/***************************************

Author: Ramesh krishnan, Sowmya jain, Anand, Avinash Kadimisetty
File: Form-1.php
Edited dates : 22/01/2015, 01/02/2015, 02/02/2015
Chages made:

1. Indented the code 
2. Input validations
3. 

*****************************************/
-->
<?php include 'externalLinks.php';?><!-- this file contains all the external css and js files and plugins if any --> 
<?php include 'check.php'; ?>
<?php include 'form_h.php'; ?>
<?php require_once('connect.php');require_once('functions.php'); ?>
<script type="text/javascript">
function myfunction(phonenumber)
{
	var reg = /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/;
	var OK = reg.exec(phonenumber.value); 
	if (!OK)
    {
    		document.getElementById("inputvalidation").innerHTML = "* Enter a valid phone number.";
    }
    else
    {
    	    document.getElementById("inputvalidation").innerHTML = "";
    }
}
</script>
<?php
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING ^ E_DEPRECATED ^ E_STRICT);
	require_once("./include/membersite_config.php");
	if($isAdmin)
		{
			$fgmembersite->RedirectToURL("admin_home.php");
		}
	
	$usrid1 = $_SESSION['userid'];
	?>

<html>
	<body>
		<div class="row">

			<div class="col-md-12">

				<form method="post" class="form" action="form3.php" enctype="multipart/form-data">
						<br/>
						<span style="color:red;" class="text-center">* required fields</span>
						<br/><br/>
						<table class="table table-striped" id="myTable">
							<tr>
								
								<!-- text field for entering current area of research -->							
								<td>
									<b>1. Enter mobile number</b> <span style="color:red;">*</span>
								</td>
								<td>
									<div class="col-md-6">
										<input id = "input" class="form-control" type="text" name="phone" onchange = "myfunction(this);" >
										<p style="color:red" id="inputvalidation"></p>
									</div>
								</td>
								<!-- end of current area of research -->

							</tr>
						</table>
						</br>
						<div class="text-center">
							<input type="submit" class="btn btn-sm btn-info" name = "submitted_val" value="Register"> <!-- button to save -->
						</div>
				</form>

			</div>

		</div><!-- end class row -->
<style>

	.table,tr,td
	{
		border-radius:5px;
	}

</style>

	</body>
	</br>
</html>

<?php include 'footer.php'; ?>