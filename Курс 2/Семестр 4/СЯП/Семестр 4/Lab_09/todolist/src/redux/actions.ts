import { ADD_TODO, TOGGLE_TODO, DELETE_TODO, EDIT_TODO } from './actionTypes';

export interface AddTodoAction {
  type: typeof ADD_TODO;
  payload: string;
}

export interface ToggleTodoAction {
  type: typeof TOGGLE_TODO;
  payload: number;
}

export interface DeleteTodoAction {
  type: typeof DELETE_TODO;
  payload: number;
}

export interface EditTodoAction {
  type: typeof EDIT_TODO;
  payload: { id: number; text: string };
}

export type TodoActionTypes = AddTodoAction | ToggleTodoAction | DeleteTodoAction | EditTodoAction;

export const addTodo = (text: string): AddTodoAction => ({
  type: ADD_TODO,
  payload: text,
});

export const toggleTodo = (id: number): ToggleTodoAction => ({
  type: TOGGLE_TODO,
  payload: id,
});

export const deleteTodo = (id: number): DeleteTodoAction => ({
  type: DELETE_TODO,
  payload: id,
});

export const editTodo = (id: number, text: string): EditTodoAction => ({
  type: EDIT_TODO,
  payload: { id, text },
});
