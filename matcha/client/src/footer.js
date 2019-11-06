import React, { Component } from "react";
import { Navbar } from "react-bootstrap";

export default class Footer extends Component {
	render() {
		return (
			<div>
				<Navbar bg="dark" variant="dark" fixed="bottom">
					<Navbar.Text>
						{ "© nyo & r0b" }
					</Navbar.Text>
				</Navbar>
				<Navbar bg="dark" variant="dark" style={{visibility: "hidden"}}>
					<Navbar.Text>
						{ "© nyo & r0b" }
					</Navbar.Text>
				</Navbar>
			</div>
		);
	}
}
