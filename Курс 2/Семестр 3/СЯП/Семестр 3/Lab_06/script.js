// 1. Имеется массив numbers

let numbers = [1, 2, 3, 4];
let [one] = numbers;

console.log(one);


// 2. Объект user имеет свойства name, age

let user = {
    name: "Volodya",
    age: 25
}

let admin = {
    admin: "Admin",
    ...user
}

let {name: d = "g", age} = user;

console.log(`${admin.admin} ${user.name} ${user.age}`);


// 3. Выполнить деструктуризацию объекта store

let store = {
    state: {
        profilePage: {
            posts: [
                {id: 1, message: "Hi", likesCount: 12},
                {id: 2, message: "By", likesCount: 1}
            ],
            newPostText: "About me"
        },
        dialogsPage: {
            dialogs: [
                {id: 1, name: "Valera"},
                {id: 2, name: "Andrey"},
                {id: 3, name: "Sasha"},
                {id: 4, name: "Viktor"}
            ],
            messages: [
                {id: 1, message: "hi"},
                {id: 2, message: "hi hi"},
                {id: 3, message: "hi hi hi"}
            ]
        },
        sidebar: []
    }
};

let {
    state: {
        profilePage: { posts, newPostText },
        dialogsPage: { dialogs, messages },
        sidebar,
    }
} = store

posts.forEach(post => console.log(post.likesCount));

console.log(dialogs.filter(dialog => dialog.id % 2 == 0));

console.log(messages.map(num => num.message = "Hello user"));


// 4. В массиве tasks хранится список задач

let tasks = [
    { id: 1, title: "HTML&CSS", isDone: true },
    { id: 2, title: "JS", isDone: true },
    { id: 3, title: "ReactJS", isDone: false },
    { id: 4, title: "Rest API", isDone: false },
    { id: 5, title: "GraphQL", isDone: false },
];

let task = {id: 6, title: "TypeScript", isDone: false};

tasks = [...tasks, task];
console.log(tasks);


// 5. Массив [1, 2, 3] передайте в качестве параметра

let array = [1, 2, 3];

function sumValues(x, y, z) {
    return x + y + z;
}

console.log(sumValues(...array));