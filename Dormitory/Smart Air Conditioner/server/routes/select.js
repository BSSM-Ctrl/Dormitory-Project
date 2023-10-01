module.exports = (db) => {
  const express = require("express");
  const router = express.Router();

  router.get("/:id", (req, res) => {
    const select = req.params.id;

    const ref = db.ref("Dormitory");

    ref
      .child(select)
      .once("value")
      .then((snapshot) => {
        const val = {
          value: snapshot.val()
        };
        res.send(val);
      })
      .catch((error) => {
        res.status(500).send(error);
      });
  });

  return router;
};
