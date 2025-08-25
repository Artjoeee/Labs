import { Todo } from '../types/todo';
import { TodoActionTypes } from './actions';
import { ADD_TODO, TOGGLE_TODO, DELETE_TODO, EDIT_TODO } from './actionTypes';

const initialState: Todo[] = [];

export const todoReducer = (state = initialState, action: TodoActionTypes): Todo[] => {
  switch (action.type) {
    case ADD_TODO:
      return [...state, { id: Date.now(), text: action.payload, completed: false }];
    case TOGGLE_TODO:
      return state.map(todo =>
        todo.id === action.payload ? { ...todo, completed: !todo.completed } : todo
      );
    case DELETE_TODO:
      return state.filter(todo => todo.id !== action.payload);
    case EDIT_TODO:
      return state.map(todo =>
        todo.id === action.payload.id ? { ...todo, text: action.payload.text } : todo
      );
    default:
      return state;
  }
};
