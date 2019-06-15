import React from "react";
//import PropTypes from "prop-types";
//import { withStyles } from "@material-ui/core/styles";
import AppBar from "@material-ui/core/AppBar";
import Toolbar from "@material-ui/core/Toolbar";
import Typography from "@material-ui/core/Typography";
import Button from "@material-ui/core/Button";
import IconButton from "@material-ui/core/IconButton";
import MenuIcon from "@material-ui/icons/Menu";
import BottomNavigation from "@material-ui/core/BottomNavigation";
import BottomNavigationAction from "@material-ui/core/BottomNavigationAction";
//import Icon from "@material-ui/core/Icon";
import RestoreIcon from "@material-ui/icons/Restore";
import FavoriteIcon from "@material-ui/icons/Favorite";
import LocationOnIcon from "@material-ui/icons/LocationOn";
import PhotoCamera from "@material-ui/icons/PhotoCamera";

import "../styles.css";

class ButtonAppBar extends React.Component {
  state = { value: "recents" };

  handleChange = (event, value) => {
    this.setState({ value });
  };

  render() {
    const { value } = this.state;
    return (
      <div className="root">
        <AppBar position="static">
          <Toolbar>
            <IconButton
              className="menuButton"
              color="inherit"
              aria-label="Menu"
            >
              <MenuIcon />
            </IconButton>
            <Typography variant="h6" color="inherit" className="grow">
              News
            </Typography>
            <Button color="inherit">Login</Button>
          </Toolbar>
        </AppBar>
        <BottomNavigation
          value={value}
          onChange={this.handleChange}
          className="bottom"
        >
          <BottomNavigationAction
            label="Recents"
            value="recents"
            icon={<RestoreIcon />}
          />
          <BottomNavigationAction
            label="Favorites"
            value="favorites"
            icon={<FavoriteIcon />}
          />
          <BottomNavigationAction
            label="Nearby"
            value="nearby"
            icon={<LocationOnIcon />}
          />
          <BottomNavigationAction
            label="Camera"
            value="camera"
            icon={<PhotoCamera />}
          />
        </BottomNavigation>
      </div>
    );
  }
}

export default ButtonAppBar;
