


// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyByGcDDiA7RLBrIbcnQWd_lkKad0uaHR7U",
  authDomain: "fir-with-sensor-light.firebaseapp.com",
  databaseURL: "https://fir-with-sensor-light-default-rtdb.firebaseio.com",
  projectId: "fir-with-sensor-light",
  storageBucket: "fir-with-sensor-light.firebasestorage.app",
  messagingSenderId: "690578878513",
  appId: "1:690578878513:web:4af1d66b708dfc57122510",
  measurementId: "G-1Y02ELZZ58"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);

// Database Paths
const dataFloatPath = 'test/float';
const dataIntPath = 'test/int';
const dataStringPath = 'test/string';

// Get database references
const databaseFloatRef = ref(database, dataFloatPath);
const databaseIntRef = ref(database, dataIntPath);
const databaseStringRef = ref(database, dataStringPath);

// Variables to save database current values
let floatReading;
let intReading;
let stringReading;

// Attach listeners
onValue(databaseFloatRef, (snapshot) => {
    floatReading = snapshot.val();
    console.log("Float reading: " + floatReading);
    document.getElementById("reading-float").innerHTML = floatReading;
});

onValue(databaseIntRef, (snapshot) => {
    intReading = snapshot.val();
    console.log("Int reading: " + intReading);
    document.getElementById("reading-int").innerHTML = intReading;
});

onValue(databaseStringRef, (snapshot) => {
    stringReading = snapshot.val();
    console.log("String reading: " + stringReading);
    document.getElementById("reading-string").innerHTML = stringReading;
});