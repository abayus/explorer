<?php
include("koneksi.php");

$sql = "INSERT INTO dbgas.sensor (value) 
		VALUES ('".$_GET["value"]."')";


mysqli_query($sql);
?>