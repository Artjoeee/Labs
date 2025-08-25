// 1. Определите тип перменных

let a = 5;
let name = "name";
let i = 0;
let double = 0.23;
let result = 1/0;
let answer = true;
let no = null;

сonsole.log(typeof 5);
console.log(typeof "name");
console.log(typeof 0);
console.log(typeof 0.23);
console.log(typeof 1/0);
console.log(typeof true);
console.log(typeof null);


// 2. Сколько квадратов В со сторонами 5 мм поместятся в четырехугольник А (45мм х 21мм)

const widthA = 45;
const heightA = 21;

const sideB = 5;

const squaresHorizontal = Math.floor(widthA / sideB);
const squaresVertical = Math.floor(heightA / sideB);

const totalSquares = squaresHorizontal * squaresVertical;
console.log(totalSquares);

// 3.  Сравните а и b 

let num = 2;
let num1 = num--;
let num2 = num++;
console.log(`${num} ${num1} ${num2}`);


// 4. Сравните и объясните

let str1 = "Котик";
let str2 = "котик";
let str3 = "китик";
let str4 = "Кот";
let str5 = "Привет";
let str6 = "Пока";
let str7 = 73;
let str8 = "53";
let str9 = false;
let str10 = 0.54;
let str11 = true;
let str12 = 123;
let str13 = "3";
let str14 = 3;
let str15 = "5мм";
let str16 = 8;
let str17 = "-2";
let str18 = 34;
let str19 = "34";
let str20 = null;
let str21 = undefined;

str1 < str2 ? console.log("Да") : console.log("Нет");
str1 < str3 ? console.log("Да") : console.log("Нет");
str4 < str1 ? console.log("Да") : console.log("Нет");
str5 > str6 ? console.log("Да") : console.log("Нет");
str7 > str8 ? console.log("Да") : console.log("Нет");
str9 > str10 < str11 ? console.log("Да") : console.log("Нет");
str12 > str9 ? console.log("Да") : console.log("Нет");
str11 < str13 ? console.log("Да") : console.log("Нет");
str14 != str15 ? console.log("Да") : console.log("Нет");
str16 > str17 ? console.log("Да") : console.log("Нет");
str18 == str19 ? console.log("Да") : console.log("Нет");
str20 == str21 ? console.log("Да") : console.log("Нет");


// 5. Пользователь вводит имя в диалоговое окно

const btn1 = document.getElementById("btn1");
btn1.addEventListener("click", ()=>{

    const teacherName = "МАРИНА ФЕДОРОВНА КУДЛАЦКАЯ";

    let userInput = prompt("Введите имя преподавателя:");

    userInput = userInput.toLowerCase().trim();
    const normalizedTeacherName = teacherName.toLowerCase().trim();

    const userParts = userInput.split(" ");
    const teacherParts = normalizedTeacherName.split(" ");

    let isValid = false;

    if (userParts.length === 1 && userParts[0] === teacherParts[0]) {
        isValid = true;
    }

    if (userParts.length === 2 && userParts[0] === teacherParts[0] && userParts[1] === teacherParts[1]) {
        isValid = true;
    }

    if (userParts.length === 3 && userParts[0] === teacherParts[0] && userParts[1] === teacherParts[1] && userParts[2] === teacherParts[2]) {
        isValid = true;
    }

    if (isValid) {
        alert("Введенные данные верные.");
    } 
    else {
        alert("Введенные данные неверные.");
    }
});


// 6. У студента 3 экзамена: русский, математика, английский

let russian = true;
let math = false;
let english = true;

if (russian && math && english) {
    console.log("Студент переведен на следующий курс.");
} 
else if (!russian && !math && !english) {
    console.log("Студент отчислен.");
} 
else {
    console.log("Студента ожидает пересдача.");
}


// 7. Вычислите и поясните

let example1 = true + true;
let example2 = 0 + "5";
let example3 = 5 + "мм";
let example4 = 8 / Infinity;
let example5 = 9 * "\n9";
let example6 = null - 1;
let example7 = "5" - 2;
let example8 = "5px" - 3;
let example9 = true - 3;
let example10 = 7 || 0;

console.log(example1);
console.log(example2);
console.log(example3);
console.log(example4);
console.log(example5);
console.log(example6);
console.log(example7);
console.log(example8);
console.log(example9);
console.log(example10);


// 8. К каждому четному числу в диапазоне [1, 10] прибавьте 2

for (i = 1; i <= 10; i++) {
    if (i % 2 === 0) {
        console.log(i + 2);
    }
    else {
        console.log(i + "мм");
    }
}


// 9. По номеру дня недели определить какой это день

// const btn2 = document.getElementById("btn2");
// btn2.addEventListener("click", ()=>{
    
//     const daysOfWeekObj = {
//         1: "Понедельник",
//         2: "Вторник",
//         3: "Среда",
//         4: "Четверг",
//         5: "Пятница",
//         6: "Суббота",
//         7: "Воскресенье"
//     };

//     let dayNumber = parseInt(prompt("Введите номер дня недели (1-7):"));

//     if (daysOfWeekObj[dayNumber]) {
//         alert(`День недели: ${daysOfWeekObj[dayNumber]}`);
//     }  
//     else {
//         alert("Некорректный номер дня недели.");
//     }
// });


const btn2 = document.getElementById("btn2");
btn2.addEventListener("click", ()=>{

    const daysOfWeekArr = ["Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье", " "];

    let dayNumberArr = parseInt(prompt("Введите номер дня недели (1-7):"));

    if (daysOfWeekArr[dayNumberArr]) {
        alert(`День недели: ${daysOfWeekArr[dayNumberArr - 1]}`);
    }  
    else {
        alert("Некорректный номер дня недели.");
    }
});



// 10. Реализуйте функцию с тремя параметрами

let param1;
let param2 = 3;

const btn3 = document.getElementById("btn3");
btn3.addEventListener("click", ()=>{

    function showParameter(param1 = 2, param2, param3) {
        alert(`${param1} ${param2} ${param3}`);
    }

    let param3 = parseInt(prompt('Введите третий параметр:'));

    showParameter(param1, param2, param3);
});


// 11. Известны стороны четырехугольника a и b

function params(a, b) {
    if (a == b) {
        return a * 4;
    }
    else {
        return a * b;
    }
}


// let params = function(a, b) {
//     if (a == b) {
//         return a * 4;
//     }
//     else {
//         return a * b;
//     }
// }

// const params = (a, b) => {
//     if (a === b) {
//         return a * 4;
//     } 
//     else {
//         return a * b;
//     }
// };


console.log(params(2, 4));
console.log(params(5, 5));
