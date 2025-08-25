// 1. Что выведет alert в примерах

function makeCounter() {
    let currentCount = 1;

    return function() {
        return currentCount++;
    };
}

let counter = makeCounter();

console.log( counter() );
console.log( counter() );
console.log( counter() );

let counter2 = makeCounter();
console.log( counter2() );
console.log(counter);

// let currentCount = 1;

// function makeCounter() {
//     return function() {
//         return currentCount++;
//     };
// }

// let counter = makeCounter();
// let counter2 = makeCounter();

// alert( counter() );
// alert( counter() );

// alert( counter2() );
// alert( counter2() );


// 2. Реализуйте каррированную функцию

function curry(func) {
    return function curried(...args) {
      if (args.length >= func.length) {
        return func.apply(this, args);
      } else {
        return function(...args2) {
          return curried.apply(this, args.concat(args2));
        }
      }
    };
}

function volume(a, b, c) {
    return a * b * c;
}
  
volume = curry(volume);

let volumeNow = volume(3);

console.log( volumeNow(2)(3) );
console.log( volumeNow(1)(4) );
console.log( volumeNow(3)(5) );


// 3. Пользователь управляет движением объекта

let coordinates = {
    x: 0,
    y: 0
};

function* gen() {
    while (true) {
        let key = prompt("Введите направление (left, right, up, down) или 'end' для завершения:");
              
        switch (key) {
            case "left":
                coordinates.x -= 10;
                yield coordinates;
                break;
            case "right":
                coordinates.x += 10;
                yield coordinates;
                break;
            case "down":
                coordinates.y -= 10;
                yield coordinates;
                break;
            case "up":
                coordinates.y += 10;
                yield coordinates;
                break;
            case "end":
                return;
            default:
                alert("Неверное направление. Попробуйте снова.");
                break;
        }
    }
}

let generator = gen();

while (true) {
    let result = generator.next();
    if (result.done) break;
    console.log(`Текущие координаты: x = ${result.value.x}, y = ${result.value.y}`);
}


// 4. Какие переменные и функции сохраняются в глобальный объект window

var globalValue = 50;
console.log(globalValue);

for (let prop in window) {
    if (window.hasOwnProperty(prop)) {
        console.log(prop + ": " + window[prop]);
    }
}

window.globalValue = 100;
console.log(globalValue);

window.makeCounter = function() {
    return "Hello";
}

console.log( makeCounter() );