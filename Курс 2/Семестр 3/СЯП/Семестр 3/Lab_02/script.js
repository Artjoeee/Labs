// 1. Функция принимает basicOperation принимает три аргумента

function basicOperation(operation, value1, value2) {
    
    switch (operation) {
        case '+':
            return value1 + value2;
            
        case '-':
            return value1 - value2;

        case '*':
            return value1 * value2;

        case '/':
            return value1 / value2;
        default:
            break;
    }
}

// let basicOperation = function(operation, value1, value2) {
    
//     switch (operation) {
//         case '+':
//             return value1 + value2;
            
//         case '-':
//             return value1 - value2;

//         case '*':
//             return value1 * value2;

//         case '/':
//             return value1 / value2;
//         default:
//             break;
//     }
// }

// let basicOperation = (operation, value1, value2) => {

//     switch (operation) {
//         case '+':
//             return value1 + value2;
            
//         case '-':
//             return value1 - value2;

//         case '*':
//             return value1 * value2;

//         case '/':
//             return value1 / value2;
//         default:
//             break;
//     }
// }

console.log(basicOperation('/', 5, 10));


// 2. Реализовать функцию, которая принимает число n

let sum = 0;
let cube = 0;

// function sumOfCubes(n) {
    
//     for (let i = 1; i <= n; i++) {

//         cube = i*i*i;
//         sum = sum + cube;
//     }

//     return sum;
// }

let sumOfCubes = function(n) {

    for (let i = 1; i <= n; i++) {

        cube = i*i*i;
        sum = sum + cube;
    }

    return sum;
}

// let sumOfCubes = (n) => {

//     for (let i = 1; i <= n; i++) {

//         cube = i*i*i;
//         sum = sum + cube;
//     }

//     return sum;
// }

console.log(sumOfCubes(5));


// 3. Среднее арифметическое всех элементов массива

// function arithmeticMeanArr(arr) {
//     let sumArr = 0;

//     for (let i = 0; i < arr.length; i++) {

//         sumArr = sumArr + arr[i];
//     }

//     let arithmeticMean = sumArr / arr.length;

//     return arithmeticMean;
// }

// let arithmeticMeanArr = function(arr) {

//     let sumArr = 0;

//     for (let i = 0; i < arr.length; i++) {

//         sumArr = sumArr + arr[i];
//     }

//     let arithmeticMean = sumArr / arr.length;

//     return arithmeticMean;
// }

let arithmeticMeanArr = (arr) => {

    let sumArr = 0;

    for (let i = 0; i < arr.length; i++) {

        sumArr = sumArr + arr[i];
    }

    let arithmeticMean = sumArr / arr.length;

    return arithmeticMean;
}

let array = [1, 2, 3, 4, 5];
console.log(arithmeticMeanArr(array));


// 4. Реализовать функцию, которая получает строку str

// function reverseString(text) {
//     let filteredText = text.split("").filter(char => char.match(/[a-zA-Z]/)).join("");
    
//     let reversedText = filteredText.split("").reverse().join("");
    
//     return reversedText;
// }

// let reverseString = function(text) {
//     let filteredText = text.split("").filter(char => char.match(/[a-zA-Z]/)).join("");
    
//     let reversedText = filteredText.split("").reverse().join("");
    
//     return reversedText;
// }

let reverseString = (text) => {
    let filteredText = text.split("").filter(char => char.match(/[a-zA-Z]/)).join("");
    
    let reversedText = filteredText.split("").reverse().join("");
    
    return reversedText;
}

const str = "JavaScr53э? ipt";
console.log(reverseString(str));


// 5. Напишите функцию, которая принимает целое число n и строку s

// function coupleOfStrings(n, s) {
    
//     return s.repeat(n);
// }

let coupleOfStrings = function(n, s) {

    return s.repeat(n);
}

// let coupleOfStrings = (n, s) => {

//     return s.repeat(n);
// }

console.log(coupleOfStrings(3, "JavaScript"));


// 6. Напишите функцию, которая принимает два массива строк arr1 и arr2

// function excludingStrings(arr1, arr2) {
//     let arr3 = [];

//     for (let i = 0; i < arr1.length; i++) {

//       if (!arr1.includes(arr2[i])) {

//         arr3.push(array1[i]);
//       }
//     }

//     return arr3;
// }


// let excludingStrings = function(arr1, arr2) {
//     let arr3 = [];

//     for (let i = 0; i < arr1.length; i++) {

//       if (!arr1.includes(arr2[i])) {

//         arr3.push(array1[i]);
//       }
//     }

//     return arr3;
// }


let excludingStrings = (arr1, arr2) => {
    let arr3 = [];

    for (let i = 0; i < arr1.length; i++) {

      if (!arr1.includes(arr2[i])) {

        arr3.push(array1[i]);
      }
    }

    return arr3;
}

const array1 = ["aa", "bb", "cc", "dd"];
const array2 = ["aa", "ee", "ff", "dd"];

console.log(excludingStrings(array1, array2));