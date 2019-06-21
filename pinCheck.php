<?php
if (isset($argc)) {
    if(password_verify($argc[1], $argc[2])){
        echo "true\n";
    }
    else{
        echo "false\n";
    }
}
else{
    echo "false\n";
}
?>