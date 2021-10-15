<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CRUD PHP</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    
<?php
require_once 'database.php';

$db = new Database();

// TODO:- Insert Data
// $data = [
//         "enroll_no" => "186450307001",
//         "name" => "New Student",
//         "branch" => 6,
//         "city" => "Bharuch"
// ];

// $db->insert("students", $data);


// TODO:- Update Data

// $data = [
//         "enroll_no" => "186450307033",
//         "name" => "Rohit Kanojiya",
//         "branch_id" => 1,
//         "city" => "Vadodara"
// ];
// $where = "id = 12"; 

// $db->update("students", $data, $where);


 // TODO:- Delete Data

// $db->delete("students", "id = 8");


// TODO:- SQL 
// $query = "INSERT INTO students(enroll_no, name, branch_id, city) VALUES
//             (186450307005, 'Abhishek Bhatt', 4 ,'Bharuch')";
// $db->sql($query);

// echo "<h4>Query:</h4>";
// echo $db->getQuery();

// echo "<h4>Result:</h4>";
// echo "<pre>";
// print_r($db->getResult());
// echo "</pre>";



// TODO:- Fetch Data & Pagination

$columns = "students.id, students.enroll_no, students.name, students.city, branch.b_name as branch";
$join = " branch ON students.branch_id = branch.b_id";

$db->select("students", $columns, $join, null, null, 5);

// echo "<h4>Query:</h4>";
// echo $db->getQuery();

echo "<h4>Result:</h4>";

// echo "<pre>";
// print_r($db->getResult());
// echo "</pre>";

$data = $db->getResult();

echo "<table class='table'>";
echo "<tr>
        <th>ID</th>
        <th>ENROLLMENT</th>
        <th>NAME</th>
        <th>BRANCH</th>
        <th>CITY</th>
    </tr>";

foreach($data as list("id"=>$id, "enroll_no"=>$enrollNo, "name"=>$name, "branch"=>$branch, "city"=>$city)){
    echo "<tr>
        <td>$id</td>
        <td>$enrollNo</td>
        <td>$name</td>
        <td>$branch</td>
        <td>$city</td>
    </tr>";
}

echo "</table>";

$db->pagination("students",$join, null, 5);

?>

</body>
</html>