const express = require("express");
const morgan = require("morgan");
const admin = require('firebase-admin');
const serviceAccount = require('./smart-air-conditioner-63ffc-firebase-adminsdk-y0xm9-668edfefba.json');

const app = express();

app.set("port", process.env.PORT || 3000);

app.use(morgan("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL:
    "https://smart-air-conditioner-63ffc-default-rtdb.firebaseio.com",
});

const db = admin.database();

const UpdateRouter = require("./routes/update")(db);
const SelectRouter = require("./routes/select")(db);

app.use("/update", UpdateRouter);
app.use("/select", SelectRouter);

app.listen(app.get("port"), () => {
  console.log(app.get("port"), "번 포트에서 대기 중");
});
