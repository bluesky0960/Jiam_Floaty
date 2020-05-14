import * as Firebase from 'firebase';
let config = {
    apiKey: "",
    authDomain: "",
    databaseURL: "",
    projectId: "",
    storageBucket: "",
    messagingSenderId: "",
    appId: ""
};
let database;
export const fire = () => {
    if (!Firebase.apps.length) {
        Firebase.initializeApp(config);
    }
    database = Firebase.database()
}

export const getFireDB = () =>{
    return database.ref('/Accident').on('value')
}
export default Firebase;