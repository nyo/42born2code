window.onload = function() {

	/* webcam variables */
	const webcamVideo = document.getElementById("cr-webcam-source");
	const webcamButton = document.getElementById("cr-from-webcam");
	const webcamCanvas = document.getElementById("cr-canvas");
	const webcamContext = webcamCanvas.getContext("2d");

	/* submit form variables */
	const submitButton = document.getElementById("cr-submit-button");
	var formFilterUrl = document.getElementById("cr-filter-url");
	var formSnapshot = document.getElementById("cr-snapshot");
	var currentFilter = null;

	/* filters variables */
	const filtersHandler = document.getElementsByClassName("cr-filters-handler");
	const filtersResetButton = document.getElementById("cr-reset-filter");
	const filtersCanvas = document.getElementById("cr-filters");
	const filtersContext = filtersCanvas.getContext("2d");

	/* upload variables */
	const uploadButton = document.getElementById("cr-from-computer");

	/* webcam stream handling */
	if (navigator.mediaDevices.getUserMedia) {
		navigator.mediaDevices.getUserMedia({ "audio": false, "video": true })
		.then(function(stream) {
			webcamVideo.srcObject = stream;
			webcamButton.disabled = false;
		})
		.catch(function(error) {
			console.error(error);
		});
	}

	/* webcam capture handling */
	webcamButton.addEventListener("click", function() {
		if (webcamButton.value != "retry") {
			webcamCanvas.style.backgroundColor = "lightyellow";
			window.setTimeout(function() {
				webcamCanvas.style.backgroundColor = "transparent";
				webcamContext.drawImage(webcamVideo, 83, 0, 483, 480, 0, 0, 500, 500);
				webcamButton.value = "retry";
				formSnapshot.value = webcamCanvas.toDataURL("image/png");
				formFilterUrl.value = currentFilter ? currentFilter.split("public/")[1] : null;
				submitButton.disabled = false;
			}, 100);
		} else {
			webcamContext.clearRect(0, 0, webcamCanvas.width, webcamCanvas.height);
			webcamButton.value = "from webcam";
			submitButton.disabled = true;
		}
	});

	/* filters handling */
	for (let i = 0; i < filtersHandler.length; i++) {
		let filterHandler = filtersHandler[i];
		filterHandler.onclick = function() {
			let f = new Image();
			f.src = this.src;
			f.onload = function() {
				filtersContext.clearRect(0, 0, filtersCanvas.width, filtersCanvas.height);
				filtersContext.drawImage(f, 0, 0, 500, 500);
				currentFilter = this.src;
				filtersResetButton.disabled = false;
				formFilterUrl.value = currentFilter ? currentFilter.split("public/")[1] : null;
			};
		};
	}
	filtersResetButton.onclick = function() {
		currentFilter = null;
		formFilterUrl.value = null;
		filtersContext.clearRect(0, 0, filtersCanvas.width, filtersCanvas.height);
	};

	/* upload handling */
	function draw() {
		filtersContext.clearRect(0, 0, filtersCanvas.width, filtersCanvas.height);
		webcamContext.clearRect(0, 0, webcamCanvas.width, webcamCanvas.height);
		webcamContext.drawImage(this, 0, 0, 500, 500);
		formSnapshot.value = webcamCanvas.toDataURL("image/png");
	};
	function fail() {
		alert("The provided file couldn't be loaded as an Image media.");
	};
	uploadButton.onchange = function() {
		let i = new Image();
		i.src = URL.createObjectURL(this.files[0]);
		i.onload = draw;
		i.onerror = fail;
		webcamButton.value = "retry";
		submitButton.disabled = false;
	};

};
