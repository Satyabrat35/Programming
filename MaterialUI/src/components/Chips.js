import React from "react";
import Avatar from "@material-ui/core/Avatar";
import Chip from "@material-ui/core/Chip";
import "../styles.css";

function handleClick() {
  alert("Wie kannst du nicht ein Antisemit sein, ein Sozialist!");
}

function Chips() {
  return (
    <div className="chip-root">
      <Chip
        avatar={<Avatar>☭</Avatar>}
        label="Советская армия"
        onClick={handleClick}
        className="chip"
        color="secondary"
      />
    </div>
  );
}

export default Chips;
