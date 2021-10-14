<?php
if(isset($_POST['submit'])){
    echo $_POST['ta1'];
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Markdown Editor</title>
    <link rel="stylesheet" href="simplemde.min.css">
</head>
<body>

    <form action="<?php echo $_SERVER['PHP_SELF'];?>" method="post">
        <textarea name="ta1" id="ta1"></textarea>
        <input name="submit" type="submit">
    </form>


    <script src="simplemde.min.js"></script>
    <script>
        var simplemde = new SimpleMDE({ 
            element: document.getElementById("ta1"),
            placeholder: "Start Typing here...",
        });
    </script>
</body>
</html>