const UserModel = require('../models/UserModel');
module.exports = {
  create: (req, res) => {
    let user = new UserModel({
      firstname: req.body.firstname,
      lastname: req.body.lastname,
      email: req.body.email,
      password: req.body.password
       });
     user.save()
      .then(result => {
        res.json({ success: true, result: result });
      })
      .catch(err => {
        res.json({ success: false, result: err });
      });
  },
  update: (req, res) => {
    UserModel.update({_id: req.body._id}, req.body)
      .then(user => {
        if (!user) res.json({ success: false, result: "User does not exist" });

        res.json(user);
      })
      .catch(err => {
        res.json({ success: false, result: err });
      });
  },
  retrieve: (req, res) => {
    UserModel.find()
      .then(result => {
        if (!result) res.json({ success: false, result: "No results found" });

        res.json({ success: true, result: result });
      })
      .catch(err => res.json({success: false, result: err}));
  },
  delete: (req, res) => {
    UserModel.remove({_id: req.body._id})
      .then(result => {
        if (!result) res.json({ success: false, result: "No user was found with the ID" });
        res.json({ success: true, result: result });
      })
      .catch(err => res.json({ success: false, result: err }));
  }
}