import React from 'react';
import styles from './Button.module.css';

type ButtonProps = {
  onClick: () => void;
  children: React.ReactNode;
  disabled?: boolean;
};

const Button: React.FC<ButtonProps> = ({ onClick, children, disabled }) => (
  <button className={styles.button} onClick={onClick} disabled={disabled}>
    {children}
  </button>
);

export default Button;