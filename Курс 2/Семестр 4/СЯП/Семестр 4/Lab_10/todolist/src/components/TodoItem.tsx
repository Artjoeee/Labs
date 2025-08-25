import React from 'react';
import { Todo } from '../types/todo';
import { useAppDispatch } from '../redux/hooks';
import { toggleTodo, deleteTodo } from '../redux/todosSlice';
import styles from '../styles/App.module.css';

interface Props {
  todo: Todo;
  onEdit: (todo: Todo) => void;
}

const TodoItem: React.FC<Props> = ({ todo, onEdit }) => {
  const dispatch = useAppDispatch();

  return (
    <li className={styles.todoItem}>
      <div className={styles.todoLeft}>
        <input type="checkbox" checked={todo.completed} onChange={() => dispatch(toggleTodo(todo.id))} />
        <span className={`${styles.todoText} ${todo.completed ? styles.completed : ''}`}>{todo.text}</span>
      </div>
      <div className={styles.todoButtons}>
        <button onClick={() => onEdit(todo)}>Редактировать</button>
        <button onClick={() => dispatch(deleteTodo(todo.id))}>Удалить</button>
      </div>
    </li>
  );
};

export default TodoItem;
