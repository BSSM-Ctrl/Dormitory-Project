const express = require("express");
const morgan = require("morgan");
var admin = require("firebase-admin");
var serviceAccount = require("../server/smart-air-conditioner-63ffc-firebase-adminsdk-y0xm9-668edfefba.json");
require("dotenv").config();

const app = express();

app.set("port", process.env.PORT || 3000);

app.use(morgan("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://smart-air-conditioner-63ffc-default-rtdb.firebaseio.com"
});

var db = admin.database();

app.get('/temperature', (req, res) => {
  let ref = db.ref('Dormitory');

  ref.child('temperature').once('value')
      .then((snapshot) => {
          let temperature = snapshot.val();
          res.send(`Current temperature: ${temperature}`);
      })
      .catch((error) => {
          res.status(500).send(error);
      });
});

app.put('/update/temperature', (req, res) => {
  let newTemperature = req.body.temperature;

  let ref = db.ref('Dormitory');

  ref.child('temperature').set(newTemperature)
      .then(() => {
          res.send('updated successfully.');
      })
      .catch((error) => {
          res.status(500).send(error);
      });
});


app.listen(app.get("port"), () => {
    console.log(app.get("port"), "번 포트에서 대기 중");
  });