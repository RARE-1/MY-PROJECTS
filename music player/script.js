consol.log("Welcome to Musicfy");
//initiate the variables 
let songIndex = 0;
let audioElement = new Audio('Feeling good.mp3');
let masterplay = document.getElementsById('masterPlay');
let myProgressBar = document.getElementById('myProgressBar');
let songs = [
    {songName: "Feeling good", filepath: "Feeling good.mp3", coverPath: "bg.jpg"},
    {songName: "Feeling good", filepath: "Feeling good.mp3", coverPath: "bg.jpg"},
    {songName: "Feeling good", filepath: "Feeling good.mp3", coverPath: "bg.jpg"},
    {songName: "Feeling good", filepath: "Feeling good.mp3", coverPath: "bg.jpg"},
    {songName: "Feeling good", filepath: "Feeling good.mp3", coverPath: "bg.jpg"},
    {songName: "Feeling good", filepath: "Feeling good.mp3", coverPath: "bg.jpg"},
]

// audioElement.play()

// handle play/pause click
masterplay.addEventListener('click',()=>{
    if(audioElement.paused || audioElement.currentTime<=0){
        audioElement.play();
    }
})
//listen to events 
myProgressBar.addEventListener('timeupdate', ()=>{
    console.log('timeupdate');
    //update seekbar
})