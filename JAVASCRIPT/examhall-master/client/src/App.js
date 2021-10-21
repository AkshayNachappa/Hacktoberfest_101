import React,{Component} from 'react';
import { BrowserRouter as Route } from "react-router-dom";
import './App.css';
import {Switch} from "react-router-dom";
import A from './A';
import Home from './Home';
import Log from './Log';
import Admin from './Admin';
import Addhall from './Addhall';
import Addstaff from './Addstaff';
import Register from './Register';
function App() {
  return (
  <Switch>
     <Route path="/" exact component={A} /> 
    <Route path="/Home" exact component={Home} /> 
    <Route path="/Log" exact component={Log} />
    <Route path="/Admin" exact component={Admin} /> 
    <Route path="/Addhall" exact component={Addhall} />
    <Route path="/Addstaff" exact component={Addstaff} /> 
    <Route path="/Register" exact component={Register} />
  </Switch>  
  );
}
 export default App;
