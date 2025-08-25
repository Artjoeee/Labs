import React from 'react';
import { Todo } from '../types/todo';
import TodoItem from './TodoItem';

interface Props {
  todos: Todo[];
  onEdit: (todo: Todo) => void;
}

const TodoList: React.FC<Props> = ({ todos, onEdit }) => (
  <ul>
    {todos.map((todo) => (
      <TodoItem key={todo.id} todo={todo} onEdit={onEdit} />
    ))}
  </ul>
);

export default TodoList;
