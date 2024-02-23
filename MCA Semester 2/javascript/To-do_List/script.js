
function getAnUpdate(){
  console.log("Updating List...");
  titleform = document.getElementById("title").value;
  descform = document.getElementById("taskDescription").value;
  if(localStorage.getItem("itemJSON") == null){
    itemJsonArray = [];
    itemJsonArray.push([titleform, descform]);
    localStorage.setItem("itemJSON", JSON.stringify(itemJsonArray));
  }
  else{
    itemJsonArraystr = localStorage.getItem("itemJSON");
    itemJsonArray = JSON.parse(itemJsonArraystr);
    itemJsonArray.push([titleform, descform]);
    localStorage.setItem("itemJSON", JSON.stringify(itemJsonArray));
  }
  update();
}


function update(){
  if(localStorage.getItem("itemJSON") == null){
    itemJsonArray = [];
    localStorage.setItem("itemJSON", JSON.stringify(itemJsonArray));
  }
  else{
    let itemJsonArraystr = localStorage.getItem("itemJSON");
    itemJsonArray = JSON.parse(itemJsonArraystr);
  }
  //populate
  let tableBody = document.getElementById("tableBody");
  let str = "" ;
  itemJsonArray.forEach((Element, index) =>{
    str+= `
    <tr style="color: aliceblue;">
            <th scope="row">${index+1}</th>
            <th>${Element[0]}</th>
            <td>${Element[1]}</td>
            <td><button class="btn btn-primary" onclick="dlt(${index})" style="background-color: aqua; color: black;font-weight: 500" >Delete</button></td>
          </tr>
    `
  });
  tableBody.innerHTML = str;
};

const add = document.getElementById("add");
add.addEventListener("click", getAnUpdate);
update();

function dlt(index) {
  itemJsonArraystr = localStorage.getItem("itemJSON");
  itemJsonArray = JSON.parse(itemJsonArraystr);
  //Delete
  itemJsonArray.splice(index, 1);
  localStorage.setItem("itemJSON", JSON.stringify(itemJsonArray));
  update();
}

function clearStorage(){
  if (confirm("Do you areally want to clear?")){
  console.log('Clearing the storage')
  localStorage.clear();
  update()
  }
}


function clear2(){  
   document.getElementById("title").value = "";
   document.getElementById("taskDescription").value = "";
   }

