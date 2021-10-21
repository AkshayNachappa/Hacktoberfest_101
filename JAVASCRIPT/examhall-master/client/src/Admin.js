import React,{Component} from 'react';
import './App.css';
import { Button,Nav,NavbarBrand,NavDropdown,Navbar,FormControl } from 'react-bootstrap';
import {Form,Col,Card} from 'react-bootstrap';
import { BrowserRouter as Router, Route, Link } from "react-router-dom";
class Log extends React.Component {
  render()
  {
    return (
       
        <div>
         
          <Navbar bg="dark" expand="lg" variant="dark">
        <Navbar.Brand  align="center"><h1 ><Link to="/Addstaff">Add/Edit Staff</Link>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <Link to="/Addhall">Add/Edit Hall</Link>&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;Duty/Arrangement  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;  <Button variant="danger"  ><Link to ="/A" >Logout</Link></Button></h1></Navbar.Brand>
      
        <Navbar.Toggle aria-controls="basic-navbar-nav" />
        <Navbar.Collapse id="basic-navbar-nav">
          <Form inline>
          
          
          
           
          </Form>
          
        </Navbar.Collapse>
      </Navbar>
      
      <div>
       
       </div>
        </div>
       
  );
}
}
export default Log; 
