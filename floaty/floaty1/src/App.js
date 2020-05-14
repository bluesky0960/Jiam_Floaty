import React, { Component} from 'react';
import './App.css';
import {Map, GoogleApiWrapper} from 'google-maps-react';

const mapStyles = {
    width: '100%',
    height: '100%'
};

class App extends Component{
    render(){
        return(
            <Map
                google={this.props.google}
                zoom={8}
                style={mapStyles}
                initialCenter={{lat: 47.444, lng: -122.176}}
            />
        );
    }
}

export default GoogleApiWrapper({
    apiKey: ''
})(App);


/*function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <Map
          google={this.props.google}
          zoom={8}
          //style={mapStyles}
          initialCenter={{lat: 47.444, lng: -122.176}}
        />
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;*/