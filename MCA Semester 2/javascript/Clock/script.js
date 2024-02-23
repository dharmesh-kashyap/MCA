console.warn("Test javascript");
hidden.addEventListener("mousedown", function () {
  document.querySelector("#hidden").innerText = "Bakchodi mat kar padhai kar";
});

var prev = document.querySelector("#hidden").innerText;
hidden.addEventListener("mouseup", function () {
  document.querySelector("#hidden").innerText = prev;
});

buttond.addEventListener("click", function () {
  document.getElementById("btn").innerText =
    "bola n mat hath laga bhadwe samjh nahi ata kya";
  setTimeout(function () {
    document.getElementById("btn").innerText = " ";
  }, 2000);
  var clr = setTimeout(function () {
    document.getElementById("btn").innerText = " ";
  }, 2000);
  clearTimeout(clr);
});
let a;
let d;
let t;
const options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };
setInterval(function () {
  a = new Date();
  d = a.toLocaleDateString(undefined,options);
  t = a.getHours() + ":" + a.getMinutes() + ":" + a.getSeconds();
  document.getElementById("clock").innerHTML =
    "<h3>Date: </h3>" + d + " <br>Time:  " + t;
}, 1000);
