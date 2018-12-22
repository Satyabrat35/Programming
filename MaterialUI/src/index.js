import React, { Component } from "react";
import ReactDOM from "react-dom";
import ButtonAppBar from "./components/ButtonAppBar";
import MediaControlCard from "./components/MediaControlCard.js";
import Chips from "./components/Chips.js";

class App extends Component {
  render() {
    return (
      <div>
        <div>
          <ButtonAppBar />
        </div>
        <div>
          <MediaControlCard />
        </div>
        <div>
          <Chips />
        </div>
      </div>
    );
  }
}

ReactDOM.render(<App />, document.getElementById("root"));
