<head>
  <meta http-equiv="refresh" content="5">
</head> 
<?php

include ('koneksi.php');

    $temp= file_get_contents('http://192.168.43.12/mq2');
	$tampil = str_ireplace("Temperature:","",$temp);
	mysqli_query($koneksi, "insert into sensor (value) VALUES('" . $tampil . "')");
 	echo $tampil; 