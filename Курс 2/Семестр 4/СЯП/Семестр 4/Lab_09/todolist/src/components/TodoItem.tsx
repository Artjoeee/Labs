import React from 'react';
import { Todo } from '../types/todo';
import styles from '../styles/App.module.css';

interface Props {
  todo: Todo;
  onToggle: (id: number) => void;
  onDelete: (id: number) => void;
  onEdit: (todo: Todo) => void;
}

const TodoItem: React.FC<Props> = ({ todo, onToggle, onDelete, onEdit }) => {
  return (
    <li className={styles.todoItem}>
      <div className={styles.todoLeft}>
        <input type="checkbox" checked={todo.completed} onChange={() => onToggle(todo.id)} />
        <span className={`${styles.todoText} ${todo.completed ? styles.completed : ''}`}>
          {todo.text}
        </span>
      </div>
      <div className={styles.todoButtons}>
        <button onClick={() => onEdit(todo)}>Редактировать</button>
        <button onClick={() => onDelete(todo.id)}>Удалить</button>
      </div>
    </li>
  );
};

export default TodoItem;
