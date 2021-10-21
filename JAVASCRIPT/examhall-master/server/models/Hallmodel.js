const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const   HallSchema = new Schema({
  room: String,
  capacity: String,
  row: String,
  col: String
 
});

module.exports = mongoose.model('hall', HallSchema); 