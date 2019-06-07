import React from "react";
import Card from "@material-ui/core/Card";
import CardContent from "@material-ui/core/CardContent";
import CardMedia from "@material-ui/core/CardMedia";
import IconButton from "@material-ui/core/IconButton";
import Typography from "@material-ui/core/Typography";
import SkipPreviousIcon from "@material-ui/icons/SkipPrevious";
import PlayArrowIcon from "@material-ui/icons/PlayArrow";
import SkipNextIcon from "@material-ui/icons/SkipNext";
import "../styles.css";

function MediaControlCard(props) {
  return (
    <Card className="card">
      <div className="details">
        <CardContent className="content">
          <Typography component="h5" variant="h5">
            Live From Space
          </Typography>
          <Typography variant="subtitle1" color="textSecondary">
            Mac Miller
          </Typography>
        </CardContent>
        <div className="controls">
          <IconButton aria-label="Previous">
            <SkipPreviousIcon />
          </IconButton>
          <IconButton aria-label="Play/pause">
            <PlayArrowIcon className="playicon" />
          </IconButton>
          <IconButton aria-label="Next">
            <SkipNextIcon />
          </IconButton>
        </div>
      </div>
      <CardMedia
        className="cover"
        image="https://i.scdn.co/image/8f064e22bedf4df2928513d8b81d2bfbee43ddb2"
        title="Live from space album cover"
      />
    </Card>
  );
}

export default MediaControlCard;
