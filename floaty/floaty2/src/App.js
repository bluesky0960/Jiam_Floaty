import React, {Component} from 'react';
import {Map, GoogleApiWrapper, Marker, InfoWindow} from 'google-maps-react';
import ship from './images/아이콘_배_01_01.svg'
import recueMarker from './images/아이콘_구조대_대지_1.svg'
import flowty from './images/아이콘_플로티_대지 1.svg'
import './App.css'


const mapStyles = {
    width: '100%', height: '100%'
};
const scroll = {
    overflow: 'auto'
};


class App extends Component {

    state = {
        showingInfoWindow: false,
        activeMarker: {},
        selectedPlace: {},
        accidents: [],
        zoom: 10
    }

    componentDidMount(){

    }

    _activeAcc1 = () =>{
        this.setState({

            accidents: [
                {
                    id: 0,
                    lat: 36.127670,
                    lng: 129.948714,
                    icon: ship
                }],
        })
        setTimeout(()=>{
            console.log('hello')
            this.setState({
                accidents: [
                    ...this.state.accidents,
                    {
                        id:1,
                        lat: 36.107381,
                        lng: 129.444570,
                        icon: recueMarker
                    }
                ]
            })
        }, 1000)
        setTimeout(()=>{
            console.log('hello')
            this.setState({
                accidents: [
                    //...this.state.accidents,
                    {
                        id: 0,
                        lat: 36.127670,
                        lng: 129.948714,
                        icon: ship
                    },
                    {
                        id:2,
                        lat: 36.119583,
                        lng: 129.572269,
                        icon: recueMarker
                    }
                ]
            })
        }, 2000)
        setTimeout(()=>{
            console.log('hello')
            this.setState({
                accidents: [
                    //...this.state.accidents
                    {
                        id: 0,
                        lat: 36.127670,
                        lng: 129.948714,
                        icon: ship
                    },
                    {
                        id:3,
                        lat: 36.123895,
                        lng: 129.693132,
                        icon: recueMarker
                    },
                    {
                        id: 30,
                        lat: 36.099927,
                        lng: 129.850235,
                        icon: flowty
                    },
                    {
                        id: 31,
                        lat: 36.144336,
                        lng: 129.795120,
                        icon: flowty
                    }
                ]
            })
        }, 3000)
        setTimeout(()=>{
            console.log('hello')
            this.setState({
                accidents: [
                    //...this.state.accidents,
                    {
                        id: 0,
                        lat: 36.127670,
                        lng: 129.948714,
                        icon: ship
                    },
                    {
                        id:4,
                        lat: 36.132503,
                        lng: 129.822296,
                        icon: recueMarker
                    },
                    {
                        id:40,
                        lat: 36.12767,
                        lng: 129.958715,
                        icon: flowty
                    },
                    {
                        id: 41,
                        lat: 36.139843,
                        lng: 129.90598,
                        icon: flowty
                    },
                    {
                        id: 42,
                        lat: 36.106482,
                        lng: 130.08647,
                        icon: flowty
                    },
                    {
                        id: 43,
                        lat: 36.086555,
                        lng: 129.987772,
                        icon: flowty
                    }
                ]
            })
        }, 4000)
        console.log(this.state.accidents.lat)
    }
    _resetBoard = () =>{
        this.setState({
            accidents: []
        })
        let ul = document.getElementById('list');
        ul.remove('li')
    }
    _onMarkerClick = (props, marker, e)=>{
        this.setState({
            selectedPlace: props,
            activeMarker: marker,
            showingInfoWindow: true
        })
        this._addList()
    }
    _onClose = props => {
        if(this.state.showingInfoWindow){
            this.setState({
                showingInfoWindow: false,
                activeMarker: null
            })
        }
    }
    _renderAccident = () => {
        const Acc = this.state.accidents.map(accident=>{
            return <Marker onClick = {this._onMarkerClick} icon = {accident.icon} name={'lat= '+accident.lat +"         "+'lng= '+accident.lng}
                           key={accident.id} position = {{lat :accident.lat, lng :accident.lng}} lat={accident.lat} lng={accident.lng}/>
        })
        console.log(Acc)
        return Acc
    }

    _addList = () =>{
        let ul = document.getElementById('list');
        let li = document.createElement('li');
        li.appendChild(document.createTextNode('lat: '+this.state.selectedPlace.lat +' '+' '+'lng: '+this.state.selectedPlace.lng));
        ul.appendChild(li)
    }
    _getDate = () => {
        let currentDate = new Date();
        let msg = currentDate.getFullYear()+'-'+currentDate.getMonth()+'-'+currentDate.getDate()+' '+currentDate.getHours()+':';
    }



  render()

    {

        return (
            <div>
                <Map
                    google={this.props.google}
                    zoom={this.state.zoom}
                    style={mapStyles}
                    initialCenter={{
                        lat: 36.120348, lng: 129.551231
                    }}
                ><div  className='box'>
                    <div>
                        <button onClick={this._activeAcc1}>click!</button>
                        <button onClick={this._resetBoard}>reset</button>
                    </div>
                    <div>
                        <ul className='box_inbox'  id = 'list'/>
                    </div>
                </div>
                    {this.state.accidents ? this._renderAccident() : 'Loading'}

                    <InfoWindow
                        marker = {this.state.activeMarker}
                        visible={this.state.showingInfoWindow}
                        onClose={this._onClose}
                    ><div>
                        <div className='getRedFont'>
                            2019-09-17 09:41
                        </div>

                        <div className='getFont'>
                            lat: {this.state.selectedPlace.lat}
                        </div>
                        <div className='getFont'>
                            lng: {this.state.selectedPlace.lng}
                        </div>
                    </div>
                    </InfoWindow>

                </Map>

            </div>


        );
    }
}

export default GoogleApiWrapper({
    apiKey: ''
})(App);

/*
<div id ="page-wrap">
<button onClick={this._activeAcc1}>click!</button>
                        <button onClick={this._resetBoard}>reset</button>

                        <Map
                        google={this.props.google}
                        zoom={8}
                        style={mapStyles}
                        initialCenter={{
                            lat: 36.4009, lng: 129.3528
                        }}
                    >{this.state.accidents ? this._renderAccident() : 'Loading'}

                        <InfoWindow
                            marker = {this.state.activeMarker}
                            visible={this.state.showingInfoWindow}
                            onClose={this._onClose}>
                            <div>
                                <h4>{this.state.selectedPlace.name}</h4>
                            </div>
                        </InfoWindow>


                    </Map>

                    <button onClick={this._activeAcc1}>click!</button>
                <button onClick={this._resetBoard}>reset</button>
                <Sidebar/>
                    <Map
                        google={this.props.google}
                        zoom={10}
                        style={mapStyles}

                        initialCenter={{
                            lat: 36.120348, lng: 129.551231
                        }}
                    >
                        {this.state.accidents ? this._renderAccident() : 'Loading'}

                        <InfoWindow
                            marker = {this.state.activeMarker}
                            visible={this.state.showingInfoWindow}
                            onClose={this._onClose}>
                            <div>
                                <h4>{this.state.selectedPlace.name}</h4>
                            </div>
                        </InfoWindow>

                    </Map>
                    <img src={Logo} className='logo'/>
                    <button onClick={this._activeAcc1}>click!</button>
                    <button onClick={this._resetBoard}>reset</button>
                    <div id = 'nav'>
 */