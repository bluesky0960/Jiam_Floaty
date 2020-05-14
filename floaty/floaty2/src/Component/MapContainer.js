import React, {Component} from 'react';
import {Map, GoogleApiWrapper, Marker} from 'google-maps-react';
import Firebase, {fire, getFireDB} from "./Firebase";

const mapStyles = {
    width: '100%', height: '100%'
};
class MapContainer extends Component {
    constructor(props){
        super(props);
        this.state = {
            stores: [{latitude: 37.609802, longitude: 126.997692},
                {latitude: 47.359423, longitude: -122.021071},
                {latitude: 47.2052192687988, longitude: -121.988426208496},
                {latitude: 47.6307081, longitude: -122.1434325},
                {latitude: 47.3084488, longitude: -122.2140121},
                {latitude: 47.5524695, longitude: -122.0425407}],
            //locations: []
        };

    }

    componentDidMount(){
        setTimeout(()=>{
            console.log('hello')
            this.setState({
                locations: [
                    {
                        id: this.props.id,
                        lat: this.props.lat,
                        lng: this.props.lng
                    }
                ]
            })
        }, 5000)
    }

    _renderLocations= () =>{
        const Loc = this.state.locations.map(location=>{
            return <Marker key ={location.id} lat = {location.lat} lng = {location.lng}/>
        })
        return Loc
    }
    render()
    {
        console.log(this.props)
        return (


                <Map
                    google={this.props.google}
                    zoom={8}
                    style={mapStyles}
                    initialCenter={{
                        lat: 36.4009, lng: 129.3528
                    }}
                >{this.state.locations ? this._renderLocations() : 'Loading'}

                </Map>

        );
    }
}


export default GoogleApiWrapper({
    apiKey: ''
})(MapContainer);
