
import React from 'react';
import { Button } from 'react-bootstrap';
import {Form,Col} from 'react-bootstrap';
import './App.css';

import axios from 'axios';

class Addhall extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
    room:"",
    capacity:"",
    row:"",
    col:""
    
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

    const {  room, capacity, row,col} = this.state;

    axios.post('http://localhost:3001/api/hall/create', { room, capacity, row,col })
      .then((result) => {
        this.props.history.push("/Admin")
        alert("Created")
      });
  }
  componentDidMount()
  {
    this.setState({
      room:"",
      capacity:"",
      row:"",
      col:""
    })
  }

  render()
  {
    const {room, capacity, row,col}=this.state;
  return (
    
        <div className="App1" align="center" >
        <div class="row">
    <div class="col-sm-4">
      
    </div>
           
            <div class="col-sm-4">   
            <Form className="login-form" onSubmit={this.handlesubmit}>
            
        <h1><b>ADD HALL</b></h1>
        <br></br>
        
      
        <Form.Group as={Col} controlId="formGridEmail">
          <Form.Label>Room Number</Form.Label>
          <Form.Control type="text" placeholder="Enter Room Number" value={room} name='room' onChange={this.handleinputchange} />
        </Form.Group>
    
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Capacity</Form.Label>
          <Form.Control type="text" placeholder="Enter Capacity" value={capacity} name='capacity' onChange={this.handleinputchange} />
        </Form.Group>
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Rows</Form.Label>
          <Form.Control type="text" placeholder="Enter Rows" value={row} name='row' onChange={this.handleinputchange} />
        </Form.Group>
        <Form.Group as={Col} controlId="formGridPassword">
          <Form.Label>Column</Form.Label>
          <Form.Control type="text" placeholder="Enter Column" value={col} name='col' onChange={this.handleinputchange} />
        </Form.Group>
      
        <Button variant="warning" type="submit" size="lg" block>
        Submit
      </Button>
      <br></br>
     
      </Form>
</div></div>

        </div>
        
  );
}
}
export default Addhall;