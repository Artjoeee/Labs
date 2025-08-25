import React, { useEffect, useState } from 'react';
import styles from '../styles/App.module.css';

interface Props {
  addTodo: (text: string) => void;
  editingTodo: { id: number; text: string } | null;
  saveEdit: (id: number, text: string) => void;
}

const TodoForm: React.FC<Props> = ({ addTodo, editingTodo, saveEdit }) => {
  const [text, setText] = useState('');

  useEffect(() => {
    if (editingTodo) {
      setText(editingTodo.text);
    }
  }, [editingTodo]);

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (text.trim() === '') return;

    if (editingTodo) {
      saveEdit(editingTodo.id, text.trim());
    } else {
      addTodo(text.trim());
    }

    setText('');
  };

  return (
    <form className={styles.form} onSubmit={handleSubmit}>
      <input
        type="text"
        placeholder="Введите задачу"
        value={text}
        onChange={(e) => setText(e.target.value)}
      />
      <button type="submit">{editingTodo ? 'Сохранить' : 'Добавить'}</button>
    </form>
  );
};

export default TodoForm;
