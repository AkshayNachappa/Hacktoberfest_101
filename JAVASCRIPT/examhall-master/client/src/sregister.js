
import React,{Component} from 'react';
import './App.css';
import { Button,Nav,NavbarBrand,NavDropdown,Navbar,FormControl } from 'react-bootstrap';
import {Form,Col,Card} from 'react-bootstrap';


class sregister extends React.Component {
  render()
  {
    return (
      <div className="App">
    <Navbar bg="secondary" expand="lg" variant="dark">
      <Navbar.Brand href="#home">Exam Hall Management</Navbar.Brand>
      <Navbar.Toggle aria-controls="basic-navbar-nav" />
      <Navbar.Collapse id="basic-navbar-nav">
        <Nav className="mr-auto">
          <Nav.Link href="#home">Home</Nav.Link>
          <Nav.Link href="#link">About Us</Nav.Link>
          <NavDropdown title="Procedures" id="basic-nav-dropdown">
            <NavDropdown.Item href="#action/3.1">Action</NavDropdown.Item>
            <NavDropdown.Item href="#action/3.2">Another action</NavDropdown.Item>
            <NavDropdown.Item href="#action/3.3">Something</NavDropdown.Item>
            <NavDropdown.Divider />
            <NavDropdown.Item href="#action/3.4">Separated link</NavDropdown.Item>
          </NavDropdown>
        </Nav>
        <Form inline>
          <FormControl type="text" placeholder="Search" className="mr-sm-2" />
          <Button variant="outline-success">Search</Button>
        </Form>
      </Navbar.Collapse>
    </Navbar>
    <div class="row">
    <div class="col-sm-4">
      
    </div>
  
    <div class="col-sm-4">
      <Form className="login-form" >
        <h1><b>Student Registration</b></h1>
        <br></br>
        
      

      <Form.Row>
        <Form.Group as={Col} controlId="formGridFirstName">
          <Form.Label>First Name</Form.Label>
          <Form.Control type="text" placeholder="Enter First Name" />
        </Form.Group>
    
        <Form.Group as={Col} controlId="formGridLastName">
          <Form.Label>Last Name</Form.Label>
          <Form.Control type="text" placeholder="Enter Last Name" />
        </Form.Group>
      </Form.Row>
      <Form.Row>
        <Form.Group as={Col} controlId="formGridEducational">
          <Form.Label>Examination Roll Number</Form.Label>
          <Form.Control type="text" placeholder="Enter Examination Roll Number" />
        </Form.Group>

        
        </Form.Row>

     
        <Form.Group as={Col} controlId="formGridEmail">
          <Form.Label>Email</Form.Label>
          <Form.Control type="email" placeholder="Enter email" />
        </Form.Group>
    
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Password</Form.Label>
          <Form.Control type="password" placeholder="Password" />
        </Form.Group>
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Confirm Password</Form.Label>
          <Form.Control type="password" placeholder="Password" />
        </Form.Group>

    
      <Form.Group id="formGridCheckbox">
        <Form.Check type="checkbox" label="Check me out" />
      </Form.Group>
    
      <Button variant="primary" type="submit">
        Submit
      </Button>
    </Form>
    </div>
    <div class="col-sm-4"></div>
    </div>
    </div>
  );
}
}
export default sregister; 
