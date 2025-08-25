import React, { useState, useEffect } from 'react';
import styles from '../styles/App.module.css';

interface Props {
  addTodo: (text: string) => void;
  editingTodo: { id: number; text: string } | null;
  saveEdit: (id: number, text: string) => void;
}

const TodoForm: React.FC<Props> = ({ addTodo, editingTodo, saveEdit }) => {
  const [text, setText] = useState('');

  useEffect(() => {
    if (editingTodo) setText(editingTodo.text);
  }, [editingTodo]);

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!text.trim()) return;
    editingTodo ? saveEdit(editingTodo.id, text) : addTodo(text);
    setText('');
  };

  return (
    <form onSubmit={handleSubmit} className={styles.form}>
      <input
        type="text"
        value={text}
        onChange={e => setText(e.target.value)}
        placeholder="Введите задачу"
      />
      <button type="submit">{editingTodo ? 'Сохранить' : 'Добавить'}</button>
    </form>
  );
};

export default TodoForm;
