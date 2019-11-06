module.exports = {
	"ports": {
		"server": 1337,
		"client": 80
	},
	"host": "http://localhost",
	"mail": {
		"service": "gmail",
		"host": "smtp.gmail.com",
		"auth": {
			"user": "",
			"pass": ""
		}
	},
	"path": "",
	"default_picture": "default-profile-picture.png",
	"session_secret": "9PgmBxjYTKGAzWxfkXspQ4tzPvPJPsM7",
	"oauth": {
		"fortytwo": {
			"clientID": "",
			"clientSecret": "",
			"callbackURL": "http://localhost:1337/sign/42/callback"
		},
		"google": {
			"clientID": "",
			"clientSecret": "",
			"callbackURL": "http://localhost:1337/sign/google/callback"
		},
		"github": {
			"clientID": "",
			"clientSecret": "",
			"callbackURL": "http://localhost:1337/sign/github/callback"
		}
	},
	"allowed_movie_extensions": [".mp4", ".webm", ".mkv"]
};
