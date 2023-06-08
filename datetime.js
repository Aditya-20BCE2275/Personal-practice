var date = new Date();
var greet = date.getHours();
if (greet >= 6 && greet < 12) {
    console.log("Good Morning");
}
else if (greet >= 12 && greet < 18)
    console.log("good afternoon");
