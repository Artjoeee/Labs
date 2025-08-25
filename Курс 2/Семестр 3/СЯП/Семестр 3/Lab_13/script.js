class Task {
    constructor(id, name, isCompleted = false) {
        this.id = id;
        this.name = name;
        this.isCompleted = isCompleted;
    }

    updateName(newName) {
        this.name = newName;
    }

    toggleCompletion() {
        this.isCompleted = !this.isCompleted;
    }
}

class Todolist {
    constructor(id, name) {
        this.id = id;
        this.name = name;
        this.tasks = [];
    }

    addTask(task) {
        this.tasks.push(task);
    }

    filterTasks(isCompleted) {
        if (isCompleted === 'all') {
            return this.tasks;
        }

        return this.tasks.filter(task => task.isCompleted === (isCompleted === 'completed'));
    }

    deleteTask(id) {
        this.tasks = this.tasks.filter(task => task.id !== id);
    }
}

const todolist = new Todolist(1, 'Cписок дел');

function addTask() {
    const taskName = document.getElementById('task-name').value;
    
    if (taskName.trim() === '') {
        return;
    }

    const taskId = todolist.tasks.length ? todolist.tasks[todolist.tasks.length - 1].id + 1 : 1;
    const newTask = new Task(taskId, taskName);

    todolist.addTask(newTask);
    document.getElementById('task-name').value = '';
    renderTasks();
}

function renderTasks(filteredTasks = 'all') {
    const taskList = document.getElementById('task-list');
    taskList.innerHTML = '';

    const tasksToRender = todolist.filterTasks(filteredTasks);

    tasksToRender.forEach(task => {
        const taskItem = document.createElement('li');

        taskItem.classList.add('task-item');
        taskItem.innerHTML = `
            <input type="checkbox" ${task.isCompleted ? 'checked' : ''} onchange="toggleTaskCompletion(${task.id})" />
            <span class="task-name" onclick="enableEdit(this)">${task.name}</span>
            <button class="edit-btn" onclick="toggleEditMode(${task.id}, this)">Редактировать</button>
            <button onclick="deleteTask(${task.id})">Удалить</button>
        `;

        taskList.appendChild(taskItem);
    });
}

function filterTasksInList(status) {
    renderTasks(status);
}

function toggleTaskCompletion(taskId) {
    const task = todolist.tasks.find(t => t.id === taskId);

    task.toggleCompletion();
    renderTasks();
}

function enableEdit(taskElement) {
    const taskSpan = taskElement;

    taskSpan.contentEditable = 'true';
    taskSpan.focus();
}

function deleteTask(taskId) {
    todolist.deleteTask(taskId);
    renderTasks();
}

function toggleEditMode(taskId, buttonElement) {
    const task = todolist.tasks.find(t => t.id === taskId);
    const taskSpan = buttonElement.previousElementSibling;

    if (taskSpan.contentEditable === 'true') {
        const newName = taskSpan.innerText.trim();

        if (newName) {
            task.updateName(newName);
        } else {
            taskSpan.innerText = task.name;
        }
        
        taskSpan.contentEditable = 'false';
        renderTasks();
    } else {
        taskSpan.contentEditable = 'true';
        taskSpan.focus();
    }
}
