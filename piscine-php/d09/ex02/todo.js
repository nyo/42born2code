var ft_list;

window.onload = function() {
	ft_list = document.getElementById("ft_list");
	if (document.cookie) {
		var cookies = JSON.parse(document.cookie);
		cookies.forEach(function(c) { addTodo(c); });
	}
};

window.onunload = function() {
	var todoList = ft_list.childNodes;
	var newEntry = [];

	for (var i = 0; i < todoList.length; i++)
		newEntry.unshift(todoList[i].innerHTML);
	document.cookie = JSON.stringify(newEntry);
};

function newTodo() {
	var todoContent = prompt("renseigner le nouveau to do:");

	if (todoContent)
		addTodo(todoContent);
}

function addTodo(content) {
	var newDiv = document.createElement("div");
	var todoObject = document.createTextNode(content);

	newDiv.onclick = delTodo;
	newDiv.appendChild(todoObject);
	ft_list.insertBefore(newDiv, ft_list.firstChild);
}

function delTodo() {
	if (confirm("supprimer le to do '" + this.innerHTML + "' ?"))
		this.parentElement.removeChild(this);
}
