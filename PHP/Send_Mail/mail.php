<h1>Send Mail Useing PHP mail() Function</h1>

<?php

$email = "prorohit010@gmail.com";
$subject = "Testing Mail";
$message = "This is a Testing Mail From Localhost";

if(mail($email, $subject, $message))
    echo "Mail Sent";
else
    echo "Fail to Send Mail";
?>