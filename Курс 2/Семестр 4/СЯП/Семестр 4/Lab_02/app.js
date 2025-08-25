"use strict";
const array = [
    { id: 1, name: 'Vasya', group: 10 },
    { id: 2, name: 'Ivan', group: 11 },
    { id: 3, name: 'Masha', group: 12 },
    { id: 4, name: 'Petya', group: 10 },
    { id: 5, name: 'Kira', group: 11 },
];
;
let car = {};
car.manufacturer = "manufacturer";
car.model = 'model';
const car1 = {};
car1.manufacturer = "manufacturer";
car1.model = 'model';
const car2 = {};
car2.manufacturer = "manufacturer";
car2.model = 'model';
const arrayCars = [{
        cars: [car1, car2]
    }];
let mathScore1 = {
    subject: "Математика",
    mark: 8,
    done: true
};
let philosophyScore1 = {
    subject: "Философия",
    mark: 10,
    done: true
};
let mathScore2 = {
    subject: "Математика",
    mark: 3,
    done: false
};
let philosophyScore2 = {
    subject: "Философия",
    mark: 6,
    done: true
};
let student1 = {
    id: 1000,
    name: "Павел",
    group: 8,
    marks: [mathScore1, philosophyScore1]
};
let student2 = {
    id: 2000,
    name: "Иван",
    group: 6,
    marks: [mathScore2, philosophyScore2]
};
let student3 = {
    id: 3000,
    name: "Андрей",
    group: 8,
    marks: [mathScore2, philosophyScore1]
};
let student4 = {
    id: 4000,
    name: "Николай",
    group: 6,
    marks: [mathScore1, philosophyScore2]
};
let group = {
    students: [student1, student2, student3, student4],
    studentsFilter: function (group) {
        return this.students.filter(student => student.group == group);
    },
    marksFilter: function (mark) {
        return this.students.filter(student => student.marks[0].mark == mark);
    },
    deleteStudent: function (id) {
        let newStudentsList = this.students.filter(student => student.id != id);
        console.log(newStudentsList);
    },
    mark: 8,
    group: 8
};
console.log(group.studentsFilter(8));
console.log(group.marksFilter(8));
group.deleteStudent(4000);
