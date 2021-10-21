const StaffModel = require('../models/Staffmodel');

module.exports = {
  create: (req, res) => {
    let staff = new StaffModel({
      uname: req.body.uname,
      department: req.body.department,
     designation: req.body.designation
      
    });

    staff.save()
      .then(result => {
        res.json({ success: true, result: result });
      })
      .catch(err => {
        res.json({ success: false, result: err });
      });
  },
  update: (req, res) => {
    StaffModel.update({_id: req.body._id}, req.body)
      .then(staff => {
        if (!staff) res.json({ success: false, result: "User does not exist" });

        res.json(staff);
      })
      .catch(err => {
        res.json({ success: false, result: err });
      });
  },
  retrieve: (req, res) => {
    StaffModel.find()
      .then(result => {
        if (!result) res.json({ success: false, result: "No results found" });

        res.json({ success: true, result: result });
      })
      .catch(err => res.json({success: false, result: err}));
  },
  delete: (req, res) => {
    StaffModel.remove({_id: req.body._id})
      .then(result => {
        if (!result) res.json({ success: false, result: "No user was found with the ID" });
        res.json({ success: true, result: result });
      })
      .catch(err => res.json({ success: false, result: err }));
  }
}