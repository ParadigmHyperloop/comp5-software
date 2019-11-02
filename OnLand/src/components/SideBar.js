import React from 'react';
import SideNav, { Toggle, Nav, NavItem, NavIcon, NavText } from '@trendmicro/react-sidenav';
import AirplanemodeActiveIcon from '@material-ui/icons/AirplanemodeActive';
import BatteryIcon from '@material-ui/icons/BatteryChargingFull';
import AppsIcon from '@material-ui/icons/Apps';
import Paper from '@material-ui/core/Paper';
import Grid from '@material-ui/core/Grid';

import '@trendmicro/react-sidenav/dist/react-sidenav.css';

import Dashboard from  './Dashboard';

class SideBar extends React.Component {

  constructor(props) {
    super(props);

    this.state = { 
      page: "Dashboard"
    };

  }

  loadSelectedPage() {
    switch (this.state.page) {
      case 'Dashboard':
        return <Dashboard />;
        break;
      case 'Batteries':
        return <Dashboard />;
        break;
      case 'Flight':
        return <Dashboard />;
        break;
      default:
        return <Dashboard />;
        break;
    }
  }

  render() {
    return (
      <div>
        <Grid container spacing={1}>
          <Grid item xs={1}>
            <SideNav
                onSelect={(selected) => {
                  console.log(selected);
                }}
            >
            <SideNav.Toggle />
              <SideNav.Nav defaultSelected="Dashboard">
                <NavItem eventKey="Dashboard">
                  <NavIcon>
                    <AppsIcon />
                  </NavIcon>
                </NavItem>
                <NavItem eventKey="Batteries">
                  <NavIcon>
                    <BatteryIcon />
                  </NavIcon>
                </NavItem>
                <NavItem eventKey="Fight">
                  <NavIcon>
                    <AirplanemodeActiveIcon />
                  </NavIcon>
                </NavItem>
              </SideNav.Nav>
            </SideNav>
          </Grid>
          <Grid item xs={11}>
            {this.loadSelectedPage()}
          </Grid>
        </Grid>
      </div>
    );
  }
}

export default SideBar;
