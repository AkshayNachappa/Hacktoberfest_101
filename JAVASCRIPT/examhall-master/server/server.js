const express = require('express');
const mongoose = require('mongoose');
var cors = require('cors');
const app = express();

// Local Database
mongoose.connect('mongodb://127.0.0.1:27017/user-manager', { useNewUrlParser: true })
  .then(() => console.log('Connected to database...'))
  .catch(err => console.error(err));

  //user.get('/', function(req, res, next) {
    //user.find(function (err, products) {
      //if (err) return next(err);
      //res.json(products);
    //});
  //});


// Mlab Database
// mongoose.connect('mongodb://nikhil:nikhil001@ds263107.mlab.com:63107/bciit', {
//   auth: {
//     user: 'nikhil',
//     password: 'nikhil001'
//   }}
// )
// .then(() => console.log('Connected to database...'))
// .catch(err => console.error(err));




// mongoose.connect('mongodb://nikhilkumar:Nikhil@001@ds263107.mlab.com:63107/bciit', { useNewUrlParser: true })



// Middleware
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(cors());
// Controllers
const UserControl = require('./controllers/UserControl');
const StaffControl = require('./controllers/StaffControl');
const HallControl = require('./controllers/HallControl');
// Routes
app.post('/api/user/create', UserControl.create);
app.post('/api/user/update', UserControl.update);
//app.get('/api/user/retrieve', UserControl.retrieve);
app.delete('/api/user/delete', UserControl.delete);
app.post('/api/staff/create', StaffControl.create);
app.post('/api/staff/update', StaffControl.update);
//app.get('/api/staff/retrieve', StaffControl.retrieve);
app.delete('/api/staff/delete', StaffControl.delete);
app.post('/api/hall/create', HallControl.create);

// Start Server
app.listen(3001, () => console.log('Server has started on port 3001...'));