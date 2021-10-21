
import React,{Component} from 'react';
import './App.css';
import { Button,Nav,NavbarBrand,NavDropdown,Navbar,FormControl } from 'react-bootstrap';
import {Form,Col,Card} from 'react-bootstrap';
import { BrowserRouter as Router, Route, Link } from "react-router-dom";

class Log extends React.Component {

  render()
  {
    return (
      <div className="Hel">
      <div className="App">
    <div class="row">
    <div class="col-sm-4">
    </div>
  <div class="col-sm-4">
      <Form className="login-form" >
        <h1><b>Admin Login</b></h1>
        <br></br>
      <Form.Row>
        <Form.Group as={Col} controlId="formGridFirstName">
          <Form.Label>Username</Form.Label>
          <Form.Control type="text" placeholder="Enter UserName" />
        </Form.Group>
      </Form.Row>
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Password</Form.Label>
          <Form.Control type="password" placeholder="Password" />
        </Form.Group>
        <Button variant="danger" ><Link to ="/Admin" >Submit</Link></Button>
     
    </Form>
    </div>
    <div class="col-sm-4"></div>
    </div>
    </div>
    </div>
  );
}
}
export default Log; 
