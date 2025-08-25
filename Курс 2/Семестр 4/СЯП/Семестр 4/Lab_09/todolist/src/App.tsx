import React, { useState } from 'react';
import { useDispatch, useSelector, TypedUseSelectorHook } from 'react-redux';
import { addTodo, toggleTodo, deleteTodo, editTodo } from './redux/actions';
import { RootState, AppDispatch } from './redux/store';
import TodoList from './components/TodoList';
import TodoForm from './components/TodoForm';
import { Todo } from './types/todo';
import styles from './styles/App.module.css';

const useTypedSelector: TypedUseSelectorHook<RootState> = useSelector;

const App: React.FC = () => {
  const todos = useTypedSelector((state) => state);
  const dispatch: AppDispatch = useDispatch<AppDispatch>();

  const [editingTodo, setEditingTodo] = useState<Todo | null>(null);

  return (
    <div className={styles.container}>
      <h1>Список дел</h1>
      <TodoForm
        addTodo={(text) => dispatch(addTodo(text))}
        editingTodo={editingTodo}
        saveEdit={(id, text) => {
          dispatch(editTodo(id, text));
          setEditingTodo(null);
        }}
      />
      <TodoList
        todos={todos}
        onToggle={(id) => dispatch(toggleTodo(id))}
        onDelete={(id) => dispatch(deleteTodo(id))}
        onEdit={(todo) => setEditingTodo(todo)}
      />
    </div>
  );
};

export default App;
