<?php // content="text/plain; charset=utf-8"
require_once ('../jpgraph/src/jpgraph.php');
require_once ('../jpgraph/src/jpgraph_line.php');
include "config.php";
$con=mysqli_connect($host,$user,$password,$db_name);
$sql="SELECT data FROM data";

//Execute query
$result = mysqli_query($con,"SELECT * FROM data");

//Store column in array
$datay1 = array();
while($row = mysqli_fetch_array($result, MYSQLI_NUM)){
    $datay1[] = $row[1];
}

//Labels
$labels = array();
while($row = mysqli_fetch_array($result, MYSQLI_NUM)){
    $labels[] = $row[3];
}

//$datay1 = array($result1);
$datay2 = array(1);
$datay3 = array(1);


// Setup the graph
$graph = new Graph(700,700);
$graph->SetScale("textlin");

$theme_class=new UniversalTheme;

$graph->SetTheme($theme_class);
$graph->img->SetAntiAliasing(false);
$graph->title->Set('Temperatur von &uuml;berall');
$graph->SetBox(false);

$graph->img->SetAntiAliasing();

$graph->yaxis->HideZeroLabel();
$graph->yaxis->HideLine(false);
$graph->yaxis->HideTicks(false,false);

$graph->xgrid->Show();
$graph->xgrid->SetLineStyle("solid");
$graph->xaxis->SetTickLabels($labels);
$graph->xgrid->SetColor('#E3E3E3');

// Create the first line
$p1 = new LinePlot($datay1);
$graph->Add($p1);
$p1->SetColor("#6495ED");
$p1->SetLegend('Temperatur');
/*
// Create the second line
$p2 = new LinePlot($datay2);
$graph->Add($p2);
$p2->SetColor("#B22222");
$p2->SetLegend('Line 2');

// Create the third line
$p3 = new LinePlot($datay3);
$graph->Add($p3);
$p3->SetColor("#FF1493");
$p3->SetLegend('Line 3');
*/
$graph->legend->SetFrameWeight(1);

// Output line
$graph->Stroke();

?>