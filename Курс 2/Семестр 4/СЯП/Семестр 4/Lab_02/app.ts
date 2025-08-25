// 1
type Person = {id: number, name: string, group: number};

const array: Person[] = [
    {id: 1, name: 'Vasya', group: 10}, 
    {id: 2, name: 'Ivan', group: 11},
    {id: 3, name: 'Masha', group: 12},
    {id: 4, name: 'Petya', group: 10},
    {id: 5, name: 'Kira', group: 11},
]


// 2
interface CarsType {
    manufacturer?: string,
    model?: string
};

let car: CarsType = {};
car.manufacturer = "manufacturer";
car.model = 'model';


// 3
type ArrayCarsType = {cars: CarsType[]};

const car1: CarsType = {};
car1.manufacturer = "manufacturer";
car1.model = 'model';

const car2: CarsType = {};
car2.manufacturer = "manufacturer";
car2.model = 'model';

const arrayCars: Array<ArrayCarsType> = [{
    cars: [car1, car2]
}];


// 4
type DoneType = boolean;
type MarkFilterType = 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10;
type GroupFilterType = 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12;

type MarkType = {
    subject: string,
    mark: MarkFilterType,
    done: DoneType,
}

type StudentType = {
    id: number,
    name: string,
    group: GroupFilterType,
    marks: Array<MarkType>
}

type GroupType = {
    students: Array<StudentType>,
    studentsFilter: (group: number) => Array<StudentType>,
    marksFilter: (mark: number) => Array<StudentType>,
    deleteStudent: (id: number) => void,
    mark: MarkFilterType,
    group: GroupFilterType
}

let mathScore1: MarkType = {
    subject: "Математика",
    mark: 8,
    done: true
};

let philosophyScore1: MarkType = {
    subject: "Философия",
    mark: 10,
    done: true
};

let mathScore2: MarkType = {
    subject: "Математика",
    mark: 3,
    done: false
};

let philosophyScore2: MarkType = {
    subject: "Философия",
    mark: 6,
    done: true
};

let student1: StudentType = {
    id: 1000,
    name: "Павел",
    group: 8,
    marks: [mathScore1, philosophyScore1]
};

let student2: StudentType = {
    id: 2000,
    name: "Иван",
    group: 6,
    marks: [mathScore2, philosophyScore2]
};

let student3: StudentType = {
    id: 3000,
    name: "Андрей",
    group: 8,
    marks: [mathScore2, philosophyScore1]
};

let student4: StudentType = {
    id: 4000,
    name: "Николай",
    group: 6,
    marks: [mathScore1, philosophyScore2]
};

let group: GroupType = {
    students: [student1, student2, student3, student4],

    studentsFilter: function(group) {
        return this.students.filter(student => student.group == group);
    },

    marksFilter: function(mark) {
        return this.students.filter(student => student.marks[0].mark == mark);
    },

    deleteStudent: function(id) {
        let newStudentsList: Array<StudentType> = this.students.filter(student => student.id != id);
        console.log(newStudentsList);
    },

    mark: 8,
    group: 8
}

console.log(group.studentsFilter(8));
console.log(group.marksFilter(8));
group.deleteStudent(4000);