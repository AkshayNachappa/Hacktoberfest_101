const HallModel = require('../models/Hallmodel');

module.exports = {
  create: (req, res) => {
    let hall = new HallModel({
        room:req.body.room,
        capacity:req.body.capacity,
        row:req.body.row,
        col: req.body.col
      
    });

    hall.save()
      .then(result => {
        res.json({ success: true, result: result });
      })
      .catch(err => {
        res.json({ success: false, result: err });
      });
  },
  update: (req, res) => {
    HallModel.update({_id: req.body._id}, req.body)
      .then(staff => {
        if (!staff) res.json({ success: false, result: "User does not exist" });

        res.json(staff);
      })
      .catch(err => {
        res.json({ success: false, result: err });
      });
  },
  retrieve: (req, res) => {
    HallModel.find()
      .then(result => {
        if (!result) res.json({ success: false, result: "No results found" });

        res.json({ success: true, result: result });
      })
      .catch(err => res.json({success: false, result: err}));
  },
  delete: (req, res) => {
    HallModel.remove({_id: req.body._id})
      .then(result => {
        if (!result) res.json({ success: false, result: "No user was found with the ID" });
        res.json({ success: true, result: result });
      })
      .catch(err => res.json({ success: false, result: err }));
  }
}