import React from 'react';
import { useAppDispatch, useAppSelector } from '../redux/hooks';
import { increment, decrement, reset } from '../redux/actions';
import Button from './Button';
import styles from './Counter.module.css';

const Counter: React.FC = () => {
  const count = useAppSelector((state) => state.count);
  const dispatch = useAppDispatch();

  return (
    <div className={styles.counter}>
      <h1 className={styles.count}>Counter: {count}</h1>
      <div className={styles.buttons}>
        <Button onClick={() => dispatch(increment())}>+</Button>
        <Button onClick={() => dispatch(decrement())} disabled={count === 0}>-</Button>
        <Button onClick={() => dispatch(reset())}>Reset</Button>
      </div>
    </div>
  );
};

export default Counter;