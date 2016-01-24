<?php include 'externalLinks.php';?>
<?php include 'form_h.php'; ?>
<?php include 'check.php'; ?>
<?php

error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
    //echo "<script> add_row16(1); </script>";

$usrid1=$_SESSION['userid'];
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "line";

$phone =  $_POST["phone"]; //"9848022370"; 
/*
$servername = "mysql.hostinger.in";
$username = "u588040838_pru";
$password = "pruthvi";
$dbname = "u588040838_phone";
*/
// Create connection

$con1=mysqli_connect($servername, $username, $password, $dbname);
if (mysqli_connect_errno($con1))
{
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
if(strlen($phone)==10)
{

    $sql = "SELECT * FROM waiting ";
    $result = mysqli_query($con1,$sql);
    $num_rows = mysqli_num_rows($result);
    $flag = 0;
    while($row = mysqli_fetch_array($result))
            {
                if($row['phone'] == $phone)
                {
                    echo "phone number already in line";
                    $flag = 1;
                    break;
                }
            }
    if($flag == 0)
    {
        if ($num_rows >= 5)
        {
            echo "waitig list is already full";
        }
        else
        {
            $sno = $num_rows +1;
            $sql = "INSERT INTO waiting (sno,phone) VALUES ($sno,'$phone') ";
            mysqli_query($con1,$sql); 
            echo "added to line in " . $sno . " position";

        }
    }

}

else
{
echo "Press the given below button to go to registration.";
}
mysqli_close($con1);
?>  
<html>
    <body>
        <div class="row">

            <div class="col-md-12">

                <form method="post" class="form" action="form2.php" enctype="multipart/form-data">
                        <table class="table table-striped" id="myTable">
                        </table>
                        </br>
                        <div class="text-center">
                            <input type="submit" class="btn btn-sm btn-info" name = "submitted_val" value="Go back to Register">
                             <!-- button to save -->
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
