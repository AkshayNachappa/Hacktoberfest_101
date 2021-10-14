<?php
    require_once "phpmailer/PHPMailerAutoload.php";
    $senderMail = "pardeepnarwal079@gmail.com";
    $senderPswd = "propardeep";

    $mail = new PHPMailer;

    //Server settings
    $mail->SMTPDebug = 4;                      //Enable verbose debug output
    $mail->isSMTP();                                            //Send using SMTP
    $mail->Host       = 'smtp.gmail.com';                     //Set the SMTP server to send through
    $mail->SMTPAuth   = true;                                   //Enable SMTP authentication
    $mail->Username   = $senderMail;                     //SMTP username
    $mail->Password   = $senderPswd;                               //SMTP password
    $mail->SMTPSecure = 'tls';         //Enable TLS encryption; `PHPMailer::ENCRYPTION_SMTPS` encouraged
    $mail->Port       = 587;                                    //TCP port to connect to, use 465 for `PHPMailer::ENCRYPTION_SMTPS` above

    //Recipients
    $mail->setFrom($senderMail, "Tester");
    $mail->addAddress("rohit777kanojiya@gmail.com");     //Add a recipient
    $mail->addReplyTo($senderMail, 'Information');
    

    $mail->isHTML(true);                                  //Set email format to HTML
    $mail->Subject = "Testing PHP Mailer";
    $mail->Body    = "<h1 style='color:blue;'>Message Body of Testing Mail Using PHP Mailer Library.</h1>";
    $mail->AltBody = "This is the Alternate body of Mail.";

    if($mail->send())
        echo '<h1>Message has been sent</h1>';
    else{
        echo '<h1>Failed to send Message</h1>';
        echo "Mailer Error: ". $mail->ErrorInfo;
    }
?>