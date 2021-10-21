
import React,{Component} from 'react';
import './App.css';
import { Button,Nav,NavbarBrand,NavDropdown,Navbar,FormControl } from 'react-bootstrap';
import {Form,Col,Card} from 'react-bootstrap';
import { BrowserRouter as Router, Route, Link } from "react-router-dom";


const A=()=>
{
  return(
    <div className="App">
   <Navbar bg="dark" expand="lg" variant="dark">
      <Navbar.Brand  align="center"><h1 ><Link to="/Home">Home</Link>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</h1></Navbar.Brand>
      <Navbar.Toggle aria-controls="basic-navbar-nav" />
      <Navbar.Collapse id="basic-navbar-nav">
        <Form inline>
        <Button variant="danger"><Link to ="/Log">Login</Link></Button>
        <h1>&nbsp;</h1>
          <Button variant="danger" ><Link to ="/Register" >Signup</Link></Button>
        </Form>
        </Navbar.Collapse>
    </Navbar>
  <div className="App-header">
     
      <p >
       
        <h1><b><font color="white"> <b>EXAM HALL MANAGEMENT</b></font></b></h1>
    
          
      </p>
    </div>
    </div>
  );
}
export default A;









