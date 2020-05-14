import React, { Component } from 'react';

class locationInfo extends Component {
    static defaultProps = {
        info: {
            lat: 0,
            lng: 0,
            id: 0
        }
    }

    render() {
        const style = {
            border: '1px solid black',
            padding: '8px',
            margin: '8px'
        };

        const {
            lat, lng, id
        } = this.props.info;

        return (
            <div style={style}>
                <div><b>{lat}</b></div>
                <div>{lng}</div>
            </div>
        );
    }
}

export default locationInfo;