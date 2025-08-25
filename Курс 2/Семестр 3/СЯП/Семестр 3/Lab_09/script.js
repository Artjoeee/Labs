// 1

let Shape = {
    color: "none",
};

let Square = Object.create(Shape);
Square.color = "yellow";
Square.sideLength = 4;

let Circle = Object.create(Shape);
Circle.radius = 10;

let Triangle = Object.create(Shape);
Triangle.sides = 3;
Triangle.sideLength = 5;
Triangle.hasLines = 1;

let GreenCircle = Object.create(Circle);
GreenCircle.color = "green";

let TriangleWithLines = Object.create(Triangle);
TriangleWithLines.hasLines = 3;

let SmallSquare = Object.create(Square);
SmallSquare.sideLength = 2;

console.log("Cвойства, которые отличают фигуру «зеленый круг»:", Object.keys(GreenCircle));
console.log("Cвойства, которые описывают фигуру «треугольник с тремя линиями»:", Object.keys(TriangleWithLines));
console.log("Есть ли у фигуры «маленький квадрат» собственное свойство, которое определяет цвет фигуры ?", SmallSquare.hasOwnProperty("color"));


// 2

class Human {
    constructor(name, surname, birthYear, address) {
        this.name = name;
        this.surname = surname;
        this.birthYear = birthYear;
        this.address = address;
    }

    get age() {
        const currentYear = new Date().getFullYear();
        return currentYear - this.birthYear;
    }

    set age(newAge) {
        const currentYear = new Date().getFullYear();
        this.birthYear = currentYear - newAge;
    }

    setAddress(newAddress) {
        this.address = newAddress;
    }

}

class Student extends Human {
    constructor(name, surname, birthYear, address, faculty, course, group, recordBookNumber) {
        super(name, surname, birthYear, address);
        this.faculty = faculty;
        this.course = course;
        this.group = group;
        this.recordBookNumber = recordBookNumber;
    }

    setCourseAndGroup(newCourse, newGroup) {
        this.course = newCourse;
        this.group = newGroup;
    }

    getFullName() {
        return `${this.name} ${this.surname}`;
    }
}

class Faculty {
    constructor(name, groupCount, studentCount) {
        this.name = name;
        this.groupCount = groupCount;
        this.studentCount = studentCount;
        this.students = [];
    }

    updateGroups(newGroupCount) {
        this.groupCount = newGroupCount;
    }

    updateStudentCount(newStudentCount) {
        this.studentCount = newStudentCount;
    }

    addStudent(student) {
        this.students.push(student);
    }

    getDev() {
        return this.students.filter(student => student.recordBookNumber[1] === '3').length;
    }

    getGroupe(groupName) {
        return this.students.filter(student => student.group === groupName);
    }
}

let facultyFIT = new Faculty("ФИТ", 5, 150);

let student1 = new Student("Иван", "Иванов", 2005, "Минск", "ФИТ", 2, "ПОИТ-10", "712013001");
let student2 = new Student("Анна", "Сидорова", 2006, "Минск", "ФИТ", 1, "ДЭВИ-6", "732013002");
let student3 = new Student("Петр", "Петров", 2005, "Гомель", "ФИТ", 3, "ДЭВИ-5", "732013003");
let student4 = new Student("Мария", "Кузнецова", 2006, "Брест", "ФИТ", 2, "ИСИТ-4", "722013004");
let student5 = new Student("Алексей", "Смирнов", 2005, "Могилев", "ФИТ", 1, "ДЭВИ-7", "732013005");

student4.setAddress("Витебск");
student4.setCourseAndGroup(3, "ПОИТ-10");
student4.birthYear = 2005;

console.log(student4.getFullName());

facultyFIT.addStudent(student1);
facultyFIT.addStudent(student2);
facultyFIT.addStudent(student3);
facultyFIT.addStudent(student4);
facultyFIT.addStudent(student5);

facultyFIT.updateGroups(6);
facultyFIT.updateStudentCount(160);

console.log(facultyFIT.studentCount);

console.log("Студенты из группы ПОИТ-12:", facultyFIT.getGroupe("ПОИТ-10"));
console.log("Количество студентов ДЭВИ:", facultyFIT.getDev());

