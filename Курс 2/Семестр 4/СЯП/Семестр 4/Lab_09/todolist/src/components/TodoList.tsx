import React from 'react';
import { Todo } from '../types/todo';
import TodoItem from './TodoItem';

interface Props {
  todos: Todo[];
  onToggle: (id: number) => void;
  onDelete: (id: number) => void;
  onEdit: (todo: Todo) => void;
}

const TodoList: React.FC<Props> = ({ todos, onToggle, onDelete, onEdit }) => {
  return (
    <ul>
      {todos.map(todo => (
        <TodoItem key={todo.id} todo={todo} onToggle={onToggle} onDelete={onDelete} onEdit={onEdit} />
      ))}
    </ul>
  );
};

export default TodoList;
