const express = require("express");
const app = express();
const firebase = require('firebase');

module.exports = app => {
	app.get("/auth/test", (req, res) => {
		res.send("Auth Working properly");
	});
	app.get(
		"/auth/google", async (req, res) => {
			try{
				var provider = new firebase.auth.GoogleAuthProvider();
				firebase.auth().useDeviceLanguage();
				var result = await firebase.auth()
					.signInWithRedirect(provider)
				var credential = result.credential
				var token = credential.accessToken
				var user = result.user
				res.send(user)
			}catch(e){
				console.log(e)
				res.send('error')
			}
		}
	);

	app.get(
		"/auth/google/callback",
	);

	app.get("/api/logout", (req, res) => {
		req.logout();
		res.redirect("/");
	});

	app.get("/api/current_user", (req, res) => {
		res.send(req.user);
	});
};