//버튼 클릭시 일부 화면 가리기

const hideBtn1 = document.getElementById("Hide--button1");
const nowBar = document.getElementById("Now--bar");

hideBtn1.addEventListener("click", () => {
  if (nowBar.style.display === "none" || nowBar.style.display === "") {
    nowBar.style.display = "flex";
  } else {
    nowBar.style.display = "none";
  }
});

const hideBtn2 = document.getElementById("Hide--button2");
const modeBtn = document.getElementById("Mode--button");

hideBtn2.addEventListener("click", () => {
  if (modeBtn.style.display === "none" || modeBtn.style.display === "") {
    modeBtn.style.display = "flex";
  } else {
    modeBtn.style.display = "none";
  }
});

const hideBtn3 = document.getElementById("Hide--button3");
const desireM = document.getElementById("Desire--main");

hideBtn3.addEventListener("click", () => {
  if (desireM.style.display === "none" || desireM.style.display === "") {
    desireM.style.display = "flex";
  } else {
    desireM.style.display = "none";
  }
});

const minusTem = document.getElementById("Minus--tem");
const plusTem = document.getElementById("Plus--tem");
const resultTem = document.getElementById("Temperature");
const minusHum = document.getElementById("Minus--hum");
const resultHum = document.getElementById("Humidity");
const plusHum = document.getElementById("Plus--hum");

let i = 25;
let j = 50;

minusTem.addEventListener("click", () => {
  if (i < 16) alert("에어컨 최저온도는 16도 입니다.");
  else {
    resultTem.textContent = i + "°C";
    i--;
  }
});

plusTem.addEventListener("click", () => {
  if (i > 30) alert("에어컨 최고온도는 30도 입니다.");
  else {
    resultTem.textContent = i + "°C";
    i++;
  }
});

minusHum.addEventListener("click", () => {
  if (j < 40) alert("에어컨의 최저습도는 40%입니다.");
  else {
    j--;
    resultHum.textContent = j + "%";
  }
});

plusHum.addEventListener("click", () => {
  if (j > 60) alert("에어컨의 최고습도는 60%입니다.");
  else {
    j++;
    resultHum.textContent = j + "%";
  }
});

function wantT() {
  const inputTem = document.getElementById("Input--tem").value;
  if (inputTem < 16) alert("에어컨의 최저온도는 16도 입니다.");
  else if (inputTem > 30) alert("에어컨의 최고온도는 30도 입니다.");
  else resultTem.textContent = inputTem + "°C";
}

function wantH() {
  const inputHum = document.getElementById("Input--hum").value;
  if (inputHum < 40) alert("에어컨의 최저습도는 40%입니다.");
  else if (inputHum > 60) alert("에어컨의 최고습도는 60%입니다.");
  else resultHum.textContent = inputHum + "%";
}
