// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.1.0/firebase-app.js";  
const firebaseConfig = {
    apiKey: "AIzaSyDxynSlYp7N35IkF7UN7jUu9_cVrSkta1Q",
    authDomain: "smart-parking-project-csd.firebaseapp.com",
    databaseURL: "https://smart-parking-project-csd-default-rtdb.firebaseio.com",
    projectId: "smart-parking-project-csd",
    storageBucket: "smart-parking-project-csd.appspot.com",
    messagingSenderId: "718930764898",
    appId: "1:718930764898:web:df69f45af2890859e35d3b",
    measurementId: "G-Y0CF6N4JNW"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

var s1;
var s2;
var s3;
var s4;

import { getDatabase, ref ,get } from "https://www.gstatic.com/firebasejs/10.1.0/firebase-database.js";
const db= getDatabase();
const dbRef = ref(db);
get(dbRef,"").then((snapshot)=>{
    if(snapshot.exists()) 
        {
        s1=snapshot.val().slot1
        console.log(s1);
        }
    else{
        alert("ERROR");
    }
})
.catch((err)=>{
    alert(err);
})
get(dbRef,"").then((snapshot)=>{
    if(snapshot.exists()) 
    {
        s2=snapshot.val().slot2
        console.log(s2);
        }
    else{
        alert("ERROR");
    }
})
.catch((err)=>{
    alert(err);
})
get(dbRef,"").then((snapshot)=>{
    if(snapshot.exists()) 
    {
        s3=snapshot.val().slot3
        console.log(s3);
        }
    else{
        alert("ERROR");
    }
})
.catch((err)=>{
    alert(err);
})
get(dbRef,"").then((snapshot)=>{
    if(snapshot.exists()) 
    {
        s4=snapshot.val().slot4
        console.log(s4);
        }
    else{
        alert("ERROR");
    }
})
.catch((err)=>{
    alert(err);
})
