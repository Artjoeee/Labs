// 1. Имеется список товаров

let set = new Set();

let apple = { product: "apple", quantity: 4, price: 2.5 };
let orange = { product: "orange", quantity: 2, price: 1.5 };
let banana1 = { product: "banana", quantity: 1, price: 1 };
let banana2 = { product: "banana", quantity: 1, price: 1 };
let mango = { product: "mango", quantity: 3, price: 6 };

set.add(apple);
set.add(orange);
set.add(banana1);

set.delete(apple);

console.log(set.has(orange));

console.log(set.size);

for (let user of set) {
  console.log(user.product);
}


// 2. Используя коллекцию Set создайте список студентов

let studentSet = new Set();

let student1 = {
  number: 123,
  group: 1,
  name: "Жамойдо Артём Игоревич"
}

let student2 = {
  number: 456,
  group: 2,
  name: "Вонсик Станислав Иванович"
}

let student3 = {
  number: 789,
  group: 3,
  name: "Шахнович Глеб Николаевич"
}

let student4 = {
  number: 147,
  group: 3,
  name: "Мандрик Алексей Иванович"
}

studentSet.add(student1);
studentSet.add(student2);
studentSet.add(student3);
studentSet.add(student4);


function deleteStudents(set, num) {
  for (const student of set) {
    if (student.number == num) {
      set.delete(student);
    }
  }

  return set;
}


function filterStudents(set, num) {
  let newSet = new Set();

  for (const student of set) {
    if (student.group == num) {
      newSet.add(student);
    }
  }

  return newSet;
}


function sortStudents(set) {
  return [...set].sort((a, b) => a.number - b.number);
}


console.log(filterStudents(studentSet, 3));
console.log(sortStudents(studentSet));
console.log(deleteStudents(studentSet, 456));


// 3.	Используя коллекцию Map и ее методы, реализуйте хранилище товаров

let cart = new Map();

cart.set(1, apple);
cart.set(2, orange);
cart.set(3, banana1);
cart.set(4, banana2);
cart.set(5, mango);

cart.delete(2);


function deleteProductByName(map, name) {
  for (const [id, fruit] of map) {
    if (fruit.product === name) {
      cart.delete(id);
    }
  }

  return cart;
}

deleteProductByName(cart, 'banana');

function updateQuantity(id, quantity) {
  if (cart.has(id)) {
    let product = cart.get(id);
    product.quantity = quantity;
    cart.set(id, product);
  }

  return cart;
}

updateQuantity(5, 2);

function updatePrice(id, price) {
  if (cart.has(id)) {
    let product = cart.get(id);
    product.price = price;
    cart.set(id, product);
  }

  return cart;
}

console.log(updatePrice(1, 3.5));

console.log(cart.size);

function sumOfMap(cart) {
  let sum = 0;

  for (const fruit of cart.values()) {
    sum += fruit.price * fruit.quantity;
  }

  return sum;
}

console.log(sumOfMap(cart));


// 4.	Создайте коллекцию WeakMap для кеширования результатов функции

const cache = new WeakMap();

function cachedFunction(obj, calculation) {
  if (!cache.has(obj)) {
    const result = calculation(obj);
    cache.set(obj, result);  
  }

  return cache.get(obj);
}


function exampleCalculation(obj) {
  return obj.value * 2;
}

const obj1 = { value: 10 };
const obj2 = { value: 20 };

console.log(cachedFunction(obj1, exampleCalculation));
console.log(cachedFunction(obj1, exampleCalculation));
console.log(cachedFunction(obj2, exampleCalculation));
console.log(cachedFunction(obj2, exampleCalculation));
