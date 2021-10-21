
import React,{Component} from 'react';
import './App.css';
import { Button,Nav,NavbarBrand,NavDropdown,Navbar,FormControl } from 'react-bootstrap';
import {Form,Col,Card} from 'react-bootstrap';
import { BrowserRouter as Router, Route, Link } from "react-router-dom";


import axios from 'axios';


class Register extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
    firstname:"",
    lastname:"",
    email:"",
    password:""
    
    }
  }
  handleinputchange = (event) => {
    event.preventDefault()
    console.log(event.target.name)
    console.log(event.target.value)
    this.setState({
      [event.target.name]:event.target.value
    })
  }

  handlesubmit = (e) => { 
    e.preventDefault();

    const {  firstname,lastname,email,password} = this.state;

    axios.post('http://localhost:3001/api/user/create', { firstname,lastname,email,password })
      .then((result) => {
        this.props.history.push("/A")
        alert("Created")
      });
  }
  componentDidMount()
  {
    this.setState({
      firstname:"",
    lastname:"",
    email:"",
    password:""
    })
  }

  render()
  {
    const {firstname,lastname,email,password}=this.state;
    return (
      <div className="Hel">
      <div className="App">
   
    <div class="row">
    <div class="col-sm-4">
      
    </div>
  
    <div class="col-sm-4">
      <Form className="login-form" onSubmit={this.handlesubmit}>
        <h1><b>Admin Registration</b></h1>
      <Form.Row>
        <Form.Group as={Col} controlId="formGridFirstName">
          <Form.Label>First Name</Form.Label>
          <Form.Control type="text" placeholder="Enter First Name"  value={firstname} name='firstname' onChange={this.handleinputchange}/>
        </Form.Group>
    
        <Form.Group as={Col} controlId="formGridLastName">
          <Form.Label>Last Name</Form.Label>
          <Form.Control type="text" placeholder="Enter Last Name" value={lastname} name='lastname' onChange={this.handleinputchange} />
        </Form.Group>
      </Form.Row>
     

     
        <Form.Group as={Col} controlId="formGridEmail">
          <Form.Label>Email</Form.Label>
          <Form.Control type="email" placeholder="Enter email"  value={email} name='email' onChange={this.handleinputchange} />
        </Form.Group>
    
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Password</Form.Label>
          <Form.Control type="password" placeholder="Password"  value={password} name='password' onChange={this.handleinputchange}/>
        </Form.Group>
       

      <Form.Group id="formGridCheckbox">
        <Form.Check type="checkbox" label="Check me out" />
      </Form.Group>
      <Button variant="warning" type="submit">
        Submit
      </Button>
    </Form>
    </div>
    <div class="col-sm-4"></div>
    </div>
    </div>
    </div>
  );
}
}
export default Register; 
