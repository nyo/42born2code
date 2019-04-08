function findGetParameter(parameterName) {
	var result = null,
	tmp = [];
	var items = location.search.substr(1).split("&");
	for (var index = 0; index < items.length; index++) {
		tmp = items[index].split("=");
		if (tmp[0] === parameterName) result = decodeURIComponent(tmp[1]);
	}
	return result;
}

function printMessage(errorMessage, messageColor) {
	var div = document.createElement("div");
	div.id = "cr-message";
	div.innerHTML = errorMessage;
	div.style.backgroundColor = messageColor;
	var main = document.getElementById("cr-main");
	main.insertBefore(div, main.childNodes[0] || null);
	setTimeout(function () {
		div.style.top = "0px";
	}, 200);
	setTimeout(function () {
		div.style.top = "-50px";
	}, 3000);
}

function updateComments(comment, user, postId) {
		var comments = document.getElementByName(postId);
		comments.innerHTML = "<p><b>" + user + "</b>" + comment + "</p><hr>";
}	
