<head><meta http-equiv="Content-Type" content="text/html;charset=utf-8"><head>
<?php
header('content-type:text/html;charset=utf-8');
if (isSet($_POST["name"]) && isSet($_POST["score"])) {
	echo "hello World";
}