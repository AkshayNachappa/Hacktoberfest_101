import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import  {BrowserRouter}  from "react-router-dom";
//import App from './App';
//import A from './A';
import All from './All';
import * as serviceWorker from './serviceWorker';
import 'bootstrap/dist/css/bootstrap.css';

ReactDOM.render(<BrowserRouter><All/></BrowserRouter>, document.getElementById('root'));


serviceWorker.unregister();
