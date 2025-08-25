import { createStore, Dispatch } from 'redux';
import { todoReducer } from './reducer';
import { TodoActionTypes } from './actions';

export const store = createStore(todoReducer);

export type RootState = ReturnType<typeof todoReducer>;

export type AppDispatch = Dispatch<TodoActionTypes>;
