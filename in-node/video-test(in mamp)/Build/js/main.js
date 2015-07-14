$(document).ready(function(){
var timer = 0;
var currentTime;
setInterval(function(){
timer = timer+1;
$("#results").text(timer);
}, 1000);

setInterval(function(){
currentTime = document.getElementById("video-plume").currentTime;
$("#current-time").text(currentTime);

if(currentTime >41 && currentTime < 47 

	)
{
	document.getElementById("video-plume").playbackRate = 1;
}

}, 0.1);

document.getElementById("video-plume").play();

$("#slider").on('change', function(){
var results = $(this).val();

// $("#results").text(results);

document.getElementById("video-plume").playbackRate = results /100;

});

});
