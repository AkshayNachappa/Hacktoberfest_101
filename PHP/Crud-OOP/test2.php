<?php
  $mysqli = new mysqli("localhost","root","","student_db");

  if ($mysqli->connect_errno) {
    die("Failed to connect to MySQL: " . $mysqli->connect_error);
  }

  // $query = "INSERT INTO students(enroll_no, name, branch_id, city) VALUES(?, ?, ?, ?)";
  // $query = "SELECT * FROM students";
  

  // Create a statement object
  $stmt = $mysqli -> stmt_init();
  
  // Preparing a statment 
  $stmt -> prepare($query) or die("Failed to Prepare Statement"); 
  
  // Execute query
  $stmt -> execute();

  $result = $stmt->get_result() or die("Error : ");

  // Prepare statement closed
  $stmt -> close();

  // Connection closed
  $mysqli -> close();
?>