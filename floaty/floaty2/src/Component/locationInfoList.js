import React, { Component } from 'react';
import locationInfo from './locationInfo';

class locationInfoList extends Component {
    static defaultProps = {
        data: []
    }

    render() {
        const { data } = this.props;
        const list = data.map(
            info => (<locationInfo key={info.id} info={info}/>)
        );

        return (
            <div>
                {list}
            </div>
        );
    }
}

export default locationInfoList;