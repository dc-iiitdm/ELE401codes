<?php include 'externalLinks.php';?>
<?php include 'form_h.php'; ?>
<?php include 'check.php'; ?>
<?php
error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	//echo "<script> add_row16(1); </script>";

$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "line";

$con1 = mysqli_connect($servername, $username, $password, $dbname);
if (mysqli_connect_errno($con1))
{
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
		$usrid1=$_SESSION['userid'];
		$retrieve = "SELECT * FROM waiting";
		$result = mysqli_query($con1,$retrieve);
		$num_rows = mysqli_num_rows($result);
		while($row = mysqli_fetch_array($result))
  		{
		$sno[] = $row['sno'];
		$phone[] = $row['phone'];
		$name[] = $row['name'];
  		}
 function create_row1()
	{
		global $num_rows;
		if($num_rows == 0)  //empty table
		{
			echo "No one is currently in waiting list";
		}
		else
		{
		echo "<script> add_row16(".$num_rows."); </script>";
		}
	}

 ?>

 <html>
 	<body>
		<div class="row">

			<div class="col-md-12">
			<script type="text/javascript">
						// function to create new row and to show the previously entered data
						function add_row16(cnt)
						{
									var sno= <?php echo json_encode($sno); ?>;
									var phone= <?php echo json_encode($phone); ?>;
									var name= <?php echo json_encode($name); ?>;
								for(var i=1;i<=cnt;i++)
								{
									var table=document.getElementById("Table");
									var row=table.insertRow(i);
									var cell1=row.insertCell(0);
									var cell2=row.insertCell(1);
									var cell3=row.insertCell(2);
									
									//alert(sno[i-1]);
									cell1.innerHTML=sno[i-1]+".";
									cell2.innerHTML="<td><input class=\"form-control\" type=\"text\" name=\"degree"+i+"\" value = \""+phone[i-1]+"\"  size=\"10\" readonly></td>";
									cell3.innerHTML="<td><input class=\"form-control\" type=\"text\" name=\"insti"+i+"\" value = \""+name[i-1]+"\" size=\"50\" readonly></td>";
								}
						}
			</script>
					 <table id="Table" border ="1">
					<tr>
											<th class="col-md-1">Sl.No</th>
											<th class="col-md-2">Phone</th>
											<th class="col-md-2">Name</th>
					</tr>
					<?php 	create_row1(); ?>
			</div>
		</div>
	</body>
</html>