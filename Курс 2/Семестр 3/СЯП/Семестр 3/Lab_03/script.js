// 1. Объедините два массива с вложенностью используя reduce()

function flatten(arr) {
  return arr.reduce(function (flat, toFlatten) {
    return flat.concat(Array.isArray(toFlatten) ? flatten(toFlatten) : toFlatten);
  }, []);
}

const array = [1, [1, 2, [3, 4]], [2,4]];

console.log(flatten(array));


function elementToString (arr) {
  return arr.reduce(function(acc, element) {
    return acc + element;
  }, "")
}

let arr = [1, 2, 3, 4];
console.log(elementToString(arr));

// 2. Найдите сумму элементов массива, если вложенность массива неизвестна

function sumArray(arr) {
  let sum = 0;
  arrForSum = flatten(arr);
    
  for (let index = 0; index < arrForSum.length; index++) {
    sum += arrForSum[index];
  }
    
  return sum;
}

console.log(sumArray(array));


// 3. Напишите функцию, которая на вход принимает массив из студентов

function objectOfStudents(arr) {
  return arr.reduce((acc, student) => {
    const groupId = student.groupId;
    const age = student.age;
    
    if (age < 18) {
      return acc;
    }
    
    if (groupId in acc) {
      acc[groupId].push(student);
    } else {
      acc[groupId] = [student];
    }
    
    return acc;
  }, {});
}

let student1 = { name: "Anton", age: 18, groupId: 10 };
let student2 = { name: "Lisa", age: 18, groupId: 7 };
let student3 = { name: "Victoria", age: 17, groupId: 7 };
let student4 = { name: "Max", age: 18, groupId: 10 };

let arrayOfStudents = [student1, student2, student3, student4];

console.log(objectOfStudents(arrayOfStudents));


// 4. Вам дана строка, состоящая из символов ASCII

function symbolToCode(str) {
  let total1 = new TextEncoder().encode(str).join("");
  let splitText = total1.split("");

  for (let index = 0; index < splitText.length; index++) {
    if (splitText[index] == 7) {
      splitText[index] = "1";
    }
  }

  let total2 = splitText.join("");
  let result = total1 - total2;

  return result;
}

let string = "ABC";

console.log(symbolToCode(string));


// 5. Создайте функцию, которая принимает несколько объектов в качестве параметров

function newObject(src1, src2, src3) {
  let dest = {};
  Object.assign(dest, src1, src2, src3);

  return dest;
}

let object1 = { a: 1};
let object2 = { b: 2};
let object3 = { c: 3};

console.log(newObject(object1, object2, object3));


// 6. Создайте башню-пирамиду, состоящую из символов "*"

function towerBuilder(floors) {
  let array = [];

  for (let i = 1; i <= floors; i++) {
    let space = (floors - i);
    let stars = i * 2 - 1;

    array.push(" ".repeat(space) + "*".repeat(stars) + " ".repeat(space));
  }

  return array;
}

let floors = 3;

console.log(towerBuilder(floors));