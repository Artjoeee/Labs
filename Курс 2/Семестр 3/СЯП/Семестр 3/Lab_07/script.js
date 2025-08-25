// 1

let person = {
    name: "Artsiom",
    age: 19,
};

person.greet = function() {
    alert(`Hello, ${this.name}`);
};

person.ageAfterYears = function(years) {
    console.log(this.age + years);
};

let years = 8;

person.greet();
person.ageAfterYears(years);


// 2

let car = {
    model: "Toyota",
    year: 1990,
    getInfo() {
        console.log(`Модель: ${this.model}, Год: ${this.year}`);
    }
};

car.getInfo();


// 3

function Book(title, author) {
    this.title = title;
    this.author = author;

    this.getTitle = function() {
        console.log("Название: " + this.title);
    }

    this.getAuthor = function() {
        console.log("Автор: " + this.author);
    }
}

let book = new Book("Война и мир", "Толстой");

book.getTitle();
book.getAuthor();


// 4

let team = {
    players: [
        { name: "Алексей", position: "Нападающий" },
        { name: "Артём", position: "Полузащитник" },
        { name: "Александр", position: "Защитник"},
        { name: "Андрей", position: "Вратарь"}
    ],

    getPlayers() {
        this.players.forEach(element => {
            console.log(`Имя: ${element.name}, Позиция: ${element.position}`);
        });
    }
};

team.getPlayers();


// 5

const counter = (function() {
    let count = 0;

    return {
        value: count,
        increment: function() { return ++this.value; },
        decrement: function() { return --this.value; },
        getCount: function() { return this.value; }
    }
})();

console.log(counter.increment()); // 1
console.log(counter.increment()); // 2
console.log(counter.decrement()); // 1
console.log(counter.getCount()); // 1


// 6

let item = {
    price: 100,
};

item.price = 50;

Object.defineProperty(item, "price", {writable: false});

item.price = 25;

console.log(item.price);


// 7

let circle = {
    radius: 5,

    get area() {
        return 3.14 * this.radius * this.radius;
    },

    get changedRadius() {
        return this.radius;
    },

    set changedRadius(value) {
        this.radius = value;
    }
};

console.log(circle.area);

circle.changedRadius = 10;

console.log(circle.radius);


// 8

let anotherCar = {
    make: "Japan",
    mark: "Nissan",
    year: 1985
};

anotherCar.mark = "Mazda";

Object.defineProperties(anotherCar, {
    make: { writable: false },
    mark: { writable: false },
    year: { writable: false } 
});

anotherCar.make = "Germany";
anotherCar.mark = "Mercedes";
anotherCar.year = 1999;

console.log(`${anotherCar.make} ${anotherCar.mark} ${anotherCar.year}`);


// 9

let array = [1, 2, 3];

Object.defineProperty(array, "sum", {
    get: function() {
        return this.reduce((acc, element) => acc + element, 0);
    },
    enumerable: true,
    configurable: true
});

array.sum = 10;

console.log(array.sum);


// 10

let rectangle = {
    height: 5,
    width: 10,

    get area() {
        return this.height * this.width;
    },

    get changedHeight() {
        return this.height;
    },

    set changedHeight(value) {
        this.height = value;
    },

    get changedWidth() {
        return this.width;
    },

    set changedWidth(value) {
        this.width = value;
    }
};

console.log(rectangle.area);


// 11

let user = {
    firstName: "John",
    lastName: "Smith",
  
    get fullName() {
      return `${this.firstName} ${this.lastName}`;
    },
  
    set fullName(value) {
      [this.firstName, this.lastName] = value.split(" ");
    }
};
  
user.fullName = "Artsiom Zhamoida";
  
console.log(user.firstName);
console.log(user.lastName);