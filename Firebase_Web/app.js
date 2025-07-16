
import { initializeApp } from "https://www.gstatic.com/firebasejs/14.10.1/firebase-app.js";
import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/14.10.1/firebase-database.js";

// Firebase configuration
const firebaseConfig = {
    apiKey: "AIzaSyByGcDDiA7RLBrIbcnQWd_lkKad0uaHR7U",
    authDomain: "fir-with-sensor-light.firebaseapp.com",
    databaseURL: "https://fir-with-sensor-light-default-rtdb.firebaseio.com",
    projectId: "fir-with-sensor-light",
    storageBucket: "fir-with-sensor-light.firebasestorage.app",
    messagingSenderId: "690578878513",
    appId: "1:690578878513:web:0bbc8ed9c0f3b514122510"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Get a reference to the database
const database = getDatabase(app);

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