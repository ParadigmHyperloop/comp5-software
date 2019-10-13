import './scss/style.scss';
import React from 'react';
import ReactDOM from 'react-dom';

import Dashboard from './components/Dashboard';

const renderApplication = () => {
  ReactDOM.render(
    <Dashboard /> ,
    document.querySelector('#root')
  );
}

renderApplication(Dashboard);

if (module.hot) {
  module.hot.accept("./components/Dashboard", () => {
    renderApplication();
  });
}
