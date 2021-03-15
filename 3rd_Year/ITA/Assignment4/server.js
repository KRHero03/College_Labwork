const express = require("express");
const mongoose = require("mongoose");
const bodyParser = require("body-parser");
const path = require('path')
require('dotenv').config({ path: path.join(__dirname + "/config/", '.env') })
const { env, firebaseApiKey, firebaseAuthDomain, firebaseProjectID, firebaseStorageBucket, firebaseMessagingSenderID, firebaseAppID } = require('./config/keys.js');

const firebase = require('firebase');
const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());


// require("./models/user.js");
// require("./models/tags.js");
// require("./models/stories.js");
// require("./models/comments.js");
// require("./models/upvotes.js");
// require("./models/followers.js");


// Initialize Firebase
var firebaseConfig = {
  apiKey: firebaseApiKey,
  authDomain: firebaseAuthDomain,
  projectId: firebaseProjectID,
  storageBucket: firebaseStorageBucket,
  messagingSenderId: firebaseMessagingSenderID,
  appId: firebaseAppID
};

firebase.initializeApp(firebaseConfig);



require("./routes/auth.js")(app);
// require("./routes/api/tags.js")(app);
// require("./routes/api/stories.js")(app);
// require("./routes/api/follower.js")(app);
// require("./routes/api/upvotes.js")(app);
// require("./routes/api/users.js")(app);

if (env === "production") {
  app.use(express.static("client/build"));
  app.get("*", (req, res) => {
    res.sendFile(path.resolve(__dirname, "client", "build", "index.html"));
  });
} else {

}

const port = process.env.PORT || 5000;

app.listen(port, () => console.log(`App running on port ${port}`));
