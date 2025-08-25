import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import { usersDB, validateEmail } from '../validation';
import '../Form.css';

const SignIn = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [showPassword, setShowPassword] = useState(false);
  const [errors, setErrors] = useState<{ [key: string]: string }>({});
  const [success, setSuccess] = useState('');

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();

    let errs: { [key: string]: string } = {};
    setSuccess('');

    if (!email.trim()) 
    {
      errs.email = 'Email обязателен';
    }
    else if (validateEmail(email) !== '') 
    {
      errs.email = validateEmail(email);
    }

    if (!password) 
    {
      errs.password = 'Пароль обязателен';
    }

    setErrors(errs);

    if (Object.keys(errs).length === 0) {
      const user = usersDB.get(email);
      if ((user && user.password === password) || (email === 'test@test.com' && password === 'test')) {
        setSuccess('Вход выполнен успешно!');
      } else {
        setErrors({ password: 'Неверный email или пароль' });
      }
    }
  };

  return (
    <form onSubmit={handleSubmit} className="form-container">
      <h2>Вход</h2>
      {success && <div className="success">{success}</div>}

      <input
        type="text"
        placeholder="Email"
        value={email}
        onChange={e => setEmail(e.target.value)}
        className={errors.email ? 'error' : ''}
      />
      {errors.email && <div className="error-message">{errors.email}</div>}

      <input
        type={showPassword ? 'text' : 'password'}
        placeholder="Пароль"
        value={password}
        onChange={e => setPassword(e.target.value)}
        className={errors.password ? 'error' : ''}
      />
      {errors.password && <div className="error-message">{errors.password}</div>}

      <label>
        <input type="checkbox" className='checkbox' checked={showPassword} onChange={() => setShowPassword(!showPassword)} /> Показать пароль
      </label>

      <button type="submit">Войти</button>

      <div className="redirect">
        Нет аккаунта? <Link to="/sign-up">Зарегистрироваться</Link><br />
        Забыли пароль? <Link to="/reset-password">Восстановить</Link>
      </div>
    </form>
  );
};

export default SignIn;
