module.exports = (db) => {
  const express = require("express");
  const router = express.Router();

  router.put("/", (req, res) => {
    const select = req.body.select;
    const newVal = req.body.value;

    const ref = db.ref("Dormitory");

    ref
      .child(select)
      .set(newVal)
      .then(() => {
        res.send("updated successfully.");
      })
      .catch((error) => {
        res.status(500).send(error);
      });
  });

  return router;
};