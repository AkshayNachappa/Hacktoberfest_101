
import React from 'react';
import { Button } from 'react-bootstrap';
import {Form,Col} from 'react-bootstrap';
import './App.css';

import axios from 'axios';

class Addstaff extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
    uname:"",
    department:"",
    designation:""
    
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

    const {  uname,department,desgination} = this.state;

    axios.post('http://localhost:3001/api/staff/create', { uname,department,desgination })
      .then((result) => {
       // this.props.history.push("/Admin")
        alert("Created")
      })
      .catch(err => {
       alert("error")
      });

  }
  componentDidMount()
  {
    this.setState({
      uname:"",
      department:"",
      designation:""
    })
  }
  render()
  {   const {uname,department,designation}=this.state;
  return (
 
        <div className="App1" align="center" >
        <div class="row">
    <div class="col-sm-4">
      
    </div>
           
            <div class="col-sm-4">   
            <Form className="login-form" onSubmit={this.handlesubmit} >
            
        <h1><b>ADD STAFF</b></h1>
        <br></br>
        
      
        <Form.Group as={Col} controlId="formGridEmail">
          <Form.Label>Name</Form.Label>
          <Form.Control type="text" placeholder="Enter Name" value={uname} name='uname' onChange={this.handleinputchange} />
        </Form.Group>
    
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Department</Form.Label>
          <Form.Control type="text" placeholder="Enter Department" value={department} name='department' onChange={this.handleinputchange}/>
        </Form.Group>
        <Form.Group as={Col} controlId="formGridtext">
          <Form.Label>Designation</Form.Label>
          <Form.Control type="text" placeholder="Enter Designation" value={designation} name='designation' onChange={this.handleinputchange}/>
        </Form.Group>
        <Button variant="warning" type="submit">
        Submit
      </Button>
      <br></br>
     </Form>
</div></div>
</div>
     
  );
}
}
export default Addstaff;