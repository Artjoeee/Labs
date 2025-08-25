import React, { useState } from 'react';
import TodoForm from './components/TodoForm';
import TodoList from './components/TodoList';
import { useAppDispatch, useAppSelector } from './redux/hooks';
import { addTodo, editTodo } from './redux/todosSlice';
import { Todo } from './types/todo';
import styles from './styles/App.module.css';

const App: React.FC = () => {
  const todos = useAppSelector(state => state.todos);
  const dispatch = useAppDispatch();

  const [editingTodo, setEditingTodo] = useState<Todo | null>(null);

  return (
    <div className={styles.container}>
      <h1>Список дел</h1>
      <TodoForm
        addTodo={(text) => dispatch(addTodo(text))}
        editingTodo={editingTodo}
        saveEdit={(id, text) => {
          dispatch(editTodo({ id, text }));
          setEditingTodo(null);
        }}
      />
      <TodoList
        todos={todos}
        onEdit={setEditingTodo}
      />
    </div>
  );
};

export default App;
