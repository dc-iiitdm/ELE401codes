<?php

$servername = "mysql.hostinger.in";
$username = "u588040838_pru";
$password = "pruthvi";
$dbname = "u588040838_phone";

//$phone = "9848022370";  
$phone = $_GET["phone"];

// Create connection

$con=mysqli_connect($servername, $username, $password, $dbname);
if (mysqli_connect_errno($con))
{
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
if(strlen($phone)==10)
{

    $sql = "SELECT * FROM waiting ";
    $result = mysqli_query($con,$sql);
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
            mysqli_query($con,$sql); 
            echo "valid".$sno;
            //echo "added to line in " . $sno . " position";

        }
    }

}

else
{
echo "there is some problem in transmition or wrong input of number";
}
mysqli_close($con);
?>	