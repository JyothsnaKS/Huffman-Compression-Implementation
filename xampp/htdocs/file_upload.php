<!DOCTYPE html>
<html lang="en">
	<head>
		  <title>Huffman File Compresseor</title>
		  <meta charset="utf-8">
		  <meta name="viewport" content="width=device-width, initial-scale=1">
		  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
		  
		  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
		  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
		  <style>tr.e:hover{background-color:lightgray}</style>
	</head>
	<body>
	<div class="container">
<?php
	$target_dir = "";
	$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
	$uploadOk = 1;
	
	$fileType=explode(".",basename($_FILES["fileToUpload"]["name"]))[1];

	// Check if text file is empty
	if(isset($_POST["submit"])) {
		if($fileType=='txt'){
			$check = filesize($_FILES["fileToUpload"]["tmp_name"]);
			if($check) {
				echo "<h3>File uploaded successfully</h3>";
				$uploadOk = 1;
				$i=0;
				exec("a $target_file",$arr);
 			    echo "<table class=\"table table-bordered\">
				    <thead>
					<tr>
						<th>Character</th>
						<th>Huffman Code</th>
					</tr>
					</thead>
					<tbody>";
				for($i=0;$i<sizeof($arr);$i++){
					if($arr[$i]=='$')
						break;
					$s=explode(":",$arr[$i]);
					error_reporting(0);
					echo "<tr class=\"e\">
					<td>$s[0]</td>
					<td>$s[1]</td>
					</tr>";
				}
				$i=$i+1;
				echo "</tbody></table>";
				echo "<h4>Percentage Compression = $arr[$i] %</h4><div class=\"progress\"><div class=\"progress-bar progress-bar-striped active\" role=\"progressbar\" role=\"progressbar\"
				aria-valuenow=\"70\" aria-valuemin=\"0\" aria-valuemax=\"100\" style=\"width:$arr[$i]%\">
				</div><div class=\"container\">$arr[$i]</div></div> <div class=\"container\"><h3>Decompressed text</h3>";
				for($i=$i+1;$i<sizeof($arr);$i++){
						echo "$arr[$i]<br>";
				}
				echo "</div>";
			} 
			else {
				echo "<h3>Text file is empty</h3>";
				$uploadOk = 0;
			}
		}
		else
			echo "<h3>File uploaded is not a text file</h3>";
	}
?>
   </div>
	</body>
</html>