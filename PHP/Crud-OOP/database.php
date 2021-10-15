<?php
class Database{

    private const HOST_NAME = "localhost";     // MySQL Host
    private const USER_NAME = "root";          // MySQL username
    private const USER_PASSWORD = "";          // MySQL user passowrd
    private const DB_NAME = "student_db";      // Database Name

    private $result = array();              // Any results from a query will be stored here
    private $mysqli = "";                   // This will be our mysqli object
    private $myQuery = "";                  // used for debugging process with SQL return

    private $conn = false;

    // Open Connection with Database
    public function __construct(){
        if(!$this->conn){
            $this->mysqli = new mysqli(self::HOST_NAME, self::USER_NAME, self::USER_PASSWORD, self::DB_NAME);
            if ($this->mysqli->connect_error) {
                array_push($this->result,$this->mysqli->connect_error);
            }
        }
    }
	
    // Function to Insert Data into the Database
    public function insert($table, $params=array()){
    	 if($this->tableExists($table)){

    	 	$tableColumns = implode(', ',array_keys($params));
    	 	$columnsValue = implode("', '", $params);
    	 	
			$query ="INSERT INTO $table ($tableColumns) VALUES ('$columnsValue')";

    	 	$this->myQuery = $query; 

            if($this->mysqli->query($query)){
                array_push($this->result,"Inserted Row ID: ".$this->mysqli->insert_id);
            }else{
                array_push($this->result,$this->mysqli->error);
            }
        }
    }

    // Function to Update data in Database
    public function update($table, $params=array(), $where = null){

    	if($this->tableExists($table)){
	        $args=array();
            foreach($params as $key=>$value){
                $args[] = "$key='$value'";   // Seperate each column out with it's corresponding value
            }
					
		    $query = "UPDATE $table SET " . implode(', ',$args);
			
            if($where != null){
		        $query .= " WHERE $where";
			}

            $this->myQuery = $query;
            
            if($this->mysqli->query($query)){
          	    array_push($this->result,"Rows Updated: " . $this->mysqli->affected_rows);
            }else{
            	array_push($this->result,$this->mysqli->error);
            }
        }
    }

    //Function to Delete table or row(s) from Database
    public function delete($table,$where = null){
        if($this->tableExists($table)){
           $query = "DELETE FROM $table"; 
            
           if($where != null){
               $query .= " WHERE $where";
           }

           $this->myQuery = $query;
         
           if($this->mysqli->query($query)){
                 array_push($this->result,"Rows Deleted: ".$this->mysqli->affected_rows);
           }else{
                 array_push($this->result,$this->mysqli->error);
           }
       }
    }

    // Function to Fetch Data from the Database
	public function select($table, $rows = '*', $join = null, $where = null, $order = null, $limit){
        if($this->tableExists($table)){ 
            
            $query = "SELECT $rows FROM  $table";

            if($join != null)
                $query .= " JOIN ".$join;

            if($where != null)
                $query .= " WHERE ".$where;
            
            if($order != null)
                $query .= " ORDER BY ".$order;
            
            if($limit != null){
                $page = isset($_GET["page"]) ? $_GET["page"] : 1;
               
                $start = ($page-1) * $limit;

                $query .= " LIMIT $start , $limit";
            } 
                
            $this->myQuery = $query; 

            $mysqliResult = $this->mysqli->query($query);   

            if($mysqliResult){
                $this->result = $mysqliResult->fetch_all(MYSQLI_ASSOC);
            }else{
                array_push($this->result, $this->mysqli->error);
            }
        }
    }

    // Function to perform operation from Query
    public function sql($query){
		$query = trim($query);
        $this->myQuery = $query; 
		$mysqliResult = $this->mysqli->query($query);

		if($mysqliResult){
            $sql_array = explode(' ',$query);
            $sql_array[0];
            switch ($sql_array[0]) {
                case "INSERT":
                    array_push($this->result,"Inserted Row ID: ". $this->mysqli->insert_id);
                    break;
                case "UPDATE":
                    array_push($this->result,"Rows Updated: " . $this->mysqli->affected_rows);
                    break;
                case "DELETE":
                    array_push($this->result,"Rows Deleted: ". $this->mysqli->affected_rows);
                    break;
                case "SELECT":
                    $this->result = $mysqliResult->fetch_all(MYSQLI_ASSOC);
                    break;
            }
		}else{
			array_push($this->result,$this->mysqli->error);
		}
	} 

    // Function to show Pagination
    public function pagination($table, $join = null, $where = null, $limit){

        if($this->tableExists($table) && $limit != null){

            $query = "SELECT COUNT(*) as total_record FROM $table";
      
            if($join != null){
                $query .= ' JOIN '.$join;
            }
            if($where != null){
                $query .= " WHERE $where";
            }
            
            $mysqliResult = $this->mysqli->query($query);
            $row = $mysqliResult->fetch_array();
            
            $totalRecord = $row['total_record'];
            $totalPage = ceil($totalRecord / $limit);

            $page = isset($_GET["page"]) ? $_GET["page"] : 1;

            $url = basename($_SERVER['PHP_SELF']);

            // Current Page is greater than Total page
            if($page > $totalPage){
                header("Location: $url?page=1");
            }
            
            // Show pagination
            $output = "<ul class='pagination'>";
            
            if($totalRecord > $limit){
                
                if($page > 1)
                $output .="<li><a href='$url?page=".($page-1)."'>Prev</a></li>";

                for ($i=1; $i <= $totalPage ; $i++) {
                    $class = ($i == $page) ? "class='active'" : "";

                    $output .="<li><a $class href='$url?page=$i'>$i</a></li>";
                }

                if($totalPage > $page)
                $output .="<li> <a class='page-link' href='$url?page=".($page+1)."'>Next</a></li>";
            }

            $output .= "</ul>";

            echo $output;
        }
    }

	// Function to check if table exists or not
	private function tableExists($table){
        $query = "SHOW TABLES FROM " . self::DB_NAME . " LIKE '$table'";

		$mysqliResult = $this->mysqli->query($query);
        if($mysqliResult){
        	if($mysqliResult->num_rows == 1)
                return true;
            else{
            	array_push($this->result,$table." table does not exist in this database");
                return false;
            }
        }
    }
	   
    // Function to return the Result
    public function getResult(){
        $val = $this->result;
        $this->result = array();
        return $val;
    }

    // Return the SQL for debugging
    public function getQuery(){
        $query = $this->myQuery;
        $this->myQuery = array();
        return $query;
    }

    // Escape your string (Prevent SQL Injection)
    public function escapeString($data){
      $data = trim($data);
      $data = stripslashes($data);
      $data = htmlspecialchars($data);
      return $this->mysqli->real_escape_string($data);
    }

    // Close connection with Database
    public function __destruct(){
        if($this->conn){
            if($this->mysqli->close()){
                $this->conn = false;
            }
        }
    }

}

?>