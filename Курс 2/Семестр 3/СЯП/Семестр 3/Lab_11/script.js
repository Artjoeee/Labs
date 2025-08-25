class Task {
    constructor(id, name, isCompleted = false) {
        this.id = id;
        this.name = name;
        this.isCompleted = isCompleted;
    }

    changeName(newName) {
        this.name = newName;
    }

    changeStatus(isCompleted) {
        this.isCompleted = isCompleted;
    }
}

class Todolist {
    constructor(id, name) {
        this.id = id;
        this.name = name;
        this.tasks = [];
    }

    changeName(newName) {
        this.name = newName;
    }

    addTask(task) {
        this.tasks.push(task);
    }

    filterTasks(isCompleted) {
        return this.tasks.filter(task => task.isCompleted == isCompleted);
    }
}

let todolist1 = new Todolist(1, "Новогодние задачи");

let task1 = new Task(1, "Купить ёлку", true);
let task2 = new Task(2, "Купить украшения");
let task3 = new Task(3, "Купить подарки");

task3.changeStatus(true);

todolist1.changeName("Новогодние заботы");

todolist1.addTask(task1);
todolist1.addTask(task2);
todolist1.addTask(task3);

console.log(todolist1.name);
console.log("Задачи: ", todolist1.tasks);
console.log("Выполненные задачи:", todolist1.filterTasks(true));
console.log("Невыполненные задачи:", todolist1.filterTasks(false));

let todolist2 = new Todolist(2, "Задачи на вечер");

let task4 = new Task(4, "Приготовить ужин", true);
let task5 = new Task(5, "Сделать лабораторную работу", true);

todolist2.addTask(task4);
todolist2.addTask(task5);

console.log(todolist2.name);
console.log("Задачи: ", todolist2.tasks);
console.log("Выполненные задачи:", todolist2.filterTasks(true));