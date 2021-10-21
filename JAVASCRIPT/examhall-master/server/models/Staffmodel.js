const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const   StaffSchema = new Schema({
  uname: String,
  department: String,
  designation: String
 
});

module.exports = mongoose.model('staff', StaffSchema); 