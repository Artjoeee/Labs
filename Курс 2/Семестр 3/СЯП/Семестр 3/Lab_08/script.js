// 1

let  user = {
    name: 'Masha',
    age: 21
};

let cloneUser = {...user};

user.age = 22;

console.log(cloneUser);


let numbers = [1, 2, 3];

let cloneNumbers = [...numbers];

console.log(cloneNumbers);


let user1 = {
    name: 'Masha',
    age: 23,
    location: {
        city: 'Minsk',
        country: 'Belarus'
    }
};

let cloneUser1 = {...user1, location: {...user1.location}};

console.log(cloneUser1);


let user2 = {
    name: 'Masha',
    age: 28,
    skills: ["HTML", "CSS", "JavaScript", "React"]
};

let cloneUser2 = {...user2, skills: [...user2.skills]};

console.log(cloneUser2);


const array = [
    {id: 1, name: 'Vasya', group: 10}, 
    {id: 2, name: 'Ivan', group: 11},
    {id: 3, name: 'Masha', group: 12},
    {id: 4, name: 'Petya', group: 10},
    {id: 5, name: 'Kira', group: 11}
];

const cloneArray = array.map(obj => ({...obj}));

console.log(cloneArray);


let user4 = {
    name: 'Masha',
    age: 19,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        exams: {
            maths: true,
            programming: false
        }
    }
};

let cloneUser4 = {...user4, studies: {...user4.studies, exams: {...user4.studies.exams}}};

console.log(cloneUser4);


// 2

let user5 = {
    name: 'Masha',
    age: 22,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { maths: true, mark: 8},
            { programming: true, mark: 4}
        ]
    }
};

let cloneUser5 = {
    ...user5,
    studies: {
        ...user5.studies, 
        department: {
            ...user5.studies.department
        }, 
        exams: user5.studies.exams.map(obj => ({...obj}))
    }
};

cloneUser5.studies.department.group = 12;
cloneUser5.studies.exams[1].mark = 10;

console.log(cloneUser5);


// 3

let user6 = {
    name: 'Masha',
    age: 21,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            {  
                maths: true,
		        mark: 8,
		        professor: {
		            name: 'Ivan Ivanov ',
		            degree: 'PhD'
		        }
	        },
            {
		        programming: true,
		        mark: 10,
		        professor: {
		            name: 'Petr Petrov',
		            degree: 'PhD'
		        }
	        }
        ]
    }
};

let cloneUser6 = {
    ...user6,
    studies: {
        ...user6.studies,
        department: {
            ...user6.studies.department,
        },
        exams: user6.studies.exams.map(obj => ({
            ...obj,
            professor: {
                ...obj.professor,
            }
        }))
    }
};

cloneUser6.studies.exams[0].professor.name = "Artsiom Artsiomov";
console.log(cloneUser6);


// 4

let user7 = {
    name: 'Masha',
    age: 20,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { 
		        maths: true,
		        mark: 8,
		        professor: {
		            name: 'Ivan Petrov',
		            degree: 'PhD',
		            articles: [
                        {title: "About HTML", pagesNumber: 3},
                        {title: "About CSS", pagesNumber: 5},
                        {title: "About JavaScript", pagesNumber: 1}
                    ]
		        }
	        },
            { 
		        programming: true,
		        mark: 10,
		        professor: {
		            name: 'Petr Ivanov',
		            degree: 'PhD',
		            articles: [
                        {title: "About HTML", pagesNumber: 3},
                        {title: "About CSS", pagesNumber: 5},
                        {title: "About JavaScript", pagesNumber: 1}
                    ]
		        }
	        }
        ]
    }
};

let cloneUser7 = {
    ...user7,
    studies: {
        ...user7.studies,
        department: {
            ...user7.studies.department,
        },
        exams: user7.studies.exams.map(obj => ({
            ...obj,
            professor: {
                ...obj.professor,
                articles: obj.professor.articles.map(article => ({...article}))
            }
        }))
    }
};

cloneUser7.studies.exams[1].professor.articles[1].pagesNumber = 3;
console.log(cloneUser7);


// 5

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

let cloneStore = {
    ...store,
    state: {
        ...store.state,
        profilePage: {
            ...store.state.profilePage,
            posts: store.state.profilePage.posts.map(post => 
            ({...post})
            )
        },
        dialogsPage: {
            ...store.state.dialogsPage,
            dialogs: store.state.dialogsPage.dialogs.map(dialog => 
                ({...dialog})
            ),
            messages: store.state.dialogsPage.messages.map(message =>
            ({...message})
            )
        },
        sidebar: [...store.state.sidebar]
    }
};

cloneStore.state.profilePage.posts.map(element => element.message = "Hello");
cloneStore.state.dialogsPage.messages.map(element => element.message = "Hello");
console.log(cloneStore);

let exam = {
     
        programming: true,
        mark: 10,
        professor: {
            name: 'Petr Ivanov',
            degree: 'PhD',
            articles: [
                {title: "About HTML", pagesNumber: 3},
                {title: "About CSS", pagesNumber: 5},
                {title: "About JavaScript", pagesNumber: 1}
            ]
        }
    
}

let cloneExam = {
    ... exam,
    professor: {
        articles: exam.professor.articles.map(obj => ({...obj}))
    }
};

console.log(cloneExam);