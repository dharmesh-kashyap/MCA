// var a = 6;
// var b = 7;

// console.log("The the Addition of ", a, " and ", b, " is ", a+b);

// var str1 = "My name is Dharmesh";
// var num = 46.64;
// var marks = {dharmeh: 56, shubham: 63};

// console.log(str1);
// console.log(num);
// console.log(marks);

// var c = true;
// var d = false ;

// console.log(c,d);

//variables are by default undefined in javascript or we can set as undefined  
// var f = undefined;
// console.log(f);

// //NuLL
//  var n = null;
//  console.log(n);


//Arrays in Javascript
// var arr = [1,"Dharmesh",3,4];
// console.log(arr);

// console.log(arr[1]);

//operators in javasscript  + - * / %;
// var a = 9;
// var b = 10;
// console.log("VAriable A : ", a , "Variable B : ", b);
// console.log("Addistion of A and B : ", a+b);
// console.log("Substraction of A and B : ", a-b);
// console.log("Multiplication of A and B : ", a*b);
// console.log("divide of A and B : ", a/b);
// console.log("mod of A and B : ", a%b);


//Logical Operators: 

//logical and
// console.log(true && false);
// console.log(false && true);
// console.log(true && true);
// console.log(false && false);


//Logical or
// console.log(true || false);
// console.log(false || true);
// console.log(true || true);
// console.log(false || false);

// //logical not !
// console.log(!true);
// console.log(!false);


// function average(a, b){
//     d = (a+b)/2;
//     return d;
// }

// const prompt = require("prompt-sync")();
// let a = parseInt(prompt("Enter the value of A: "));
// let b = parseInt(prompt("Ente the value of B: "));
// var c1 = average(a, b);

// console.log(c1);
// //console.log(c2);


// function add(a,b){
//     sum=a+b;
//     return sum;
// }
// const prompt = require("prompt-sync")();
// var a=parseInt(prompt("N"));
// var b=parseInt(prompt("m"));
// var c=add(a,b);
// console.log(c);

// {
//     var a  = 10;
// }

// var arr = [2, "dharmesh", 3 ];

// console.log(arr[0]);
// console.log(arr[1]);
// // console.log(arr);
// const prompt = require ("prompt-sync")();


// if else in javascript
// var a = parseInt(prompt("Enter value of a: "));
// if (a < 10){
//     console.log("Hello less than ten")
// }
// else if( a < 25){
//     console.log("less than 25");
// }
// else {
//     console.log("more than 25 ")
// }

//for each loop

// var array = [1,2,3,4,5,6,7,8,9,10];

// for (let index = 0; index < array.length; index++) {
//     console.log(array[index]);
// }

// const a = 10;
// console.log(a);
// a++;





//for each loop
// array.forEach(function(element){
//     console.log(element);
// })


// While Loop
// var array1 = [1,2,3,4,5,6,7,8,9,10];

// let j = 0;
// while(j<array.length){
//     console.log(array[j]);
//     j++;
// }

// do{
//     console.log(array[j]);
//     j++;
// }while(j<array.length);


// for (let index = 0; index < array.length; index++) {
//     if(index == 5){
//         continue;
//     }
//     console.log(array[index]);
// }

// let array4 = ["Dharesh", "Kashyap", 2, 3, true, false, null];
// // for(let i  = 0; i < array4.length; i++ ){
// //     console.log(array4[i]);
// // }
// // console.log(array4[1]);
// array4.pop();
// array4.push("Dhaval");
// array4.shift()
// array4.unshift("Kuch")
// var d = array4.toString();
// console.log(array4);
// console.log(d);
// console.log("The length of array is: ",array4.length)
// var arr5 = [9,6,5,7,4,2,1,3];
// var k =arr5.sort();
// console.log(k);
// console.clear()
// var str2= "What is your name:";
// console.log(str2)
// console.log(str2.length)
// // console.log(str2.indexOf("your")) // return the index of the given word 
// var h = str2.indexOf("your")
// console.log(h) // return the index of the given word 

// let md = new Date();
// console.log(md.getTime());

// console.log(md.getDate())

// console.log(md.getFullYear());

// console.log(md.getMilliseconds())

console.error("Chal be bhadwe kaam pe jaa");


//Document object Model Manipulation
// document.getElementById('click').click();
//let elem = getElementById('click').style.border = '2px solid red'

// let tn = document.getElementsByTagName('div');
// createdElement = document.createElement('p');
// created.innerHTMl = "Hello this is created paragraph ";
// tn[0].appendChild(createdElement)


//Events in javascript

// function clickedbtn(){
//     console.log("You've clicked the button");
// }
// window.onload = function(){
//     console.log("Loaded");
// }

// var Second1 = document.getElementById('Second'); // Replace 'yourElementId' with the actual id of your HTML element

// Second1.addEventListener('mouseover', function() {
//     console.log('mouse over');
// });


// check.addEventListener("click",function(){
//     console.log("Yeh mene  banaya hai madarchod")
// })

// Head.addEventListener("mouseup", function(){
//     document.getElementsByTagName('h1')[0].innerHTML = "<b>Yeh badal jayegab</b>"

// })


// Head.addEventListener("mousedown", function(){
//     document.getElementsByTagName('h1')[0].innerHTML = "<b>Yeh fir badal jayegab</b>"

// })


// Arrow function

// function sum(a,b){
//     return a+b;
// }

// var sum = (a,b) => {
//     return a+b
// }

// var Som = ()=>{
//     console.log("yaar fir ek function")
// }
// setTimeout(Som,  3000)

// var f = setInterval(Som, 2000)

//clearInterval, clearTimeout

//JSON;
var d = {name: "Dharmesh", Std: "MCA", sub: "Javascript" }
var k = JSON.stringify(d);
console.log(k);
console.log(typeof k);
var h = JSON.parse(k);
console.log(h)
console.log(typeof h)










