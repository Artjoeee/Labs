import React, { useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { usersDB, validateEmail, validatePassword, validateName } from '../validation';
import '../Form.css';

const SignUp = () => {
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [showPassword, setShowPassword] = useState(false);
  const [errors, setErrors] = useState<{ [key: string]: string }>({});
  const [success, setSuccess] = useState('');
  const navigate = useNavigate();

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();

    let errs: { [key: string]: string } = {};
    setSuccess('');

    if (!name.trim())
    {
      errs.name = 'Имя обязательно';
    }
    else if (validateName(name) !== '') 
    {
      errs.name = validateName(name);
    }

    if (!email.trim()) 
    {
      errs.email = 'Email обязателен';
    }
    else if (validateEmail(email) !== '') 
    {
      errs.email = validateEmail(email);
    }
    else if (usersDB.has(email)) 
    {
      errs.email = 'Email уже зарегистрирован';
    }

    if (!password) 
    {
      errs.password = 'Пароль обязателен';
    }
    else if (validatePassword(password) !== '') 
    {
      errs.password = validatePassword(password);
    }

    if (!confirmPassword) 
    {
      errs.confirmPassword = 'Подтвердите пароль';
    }
    else if (confirmPassword !== password) 
    {
      errs.confirmPassword = 'Пароли не совпадают';
    }

    setErrors(errs);

    if (Object.keys(errs).length === 0) {
      usersDB.set(email, { name, password });

      setSuccess('Регистрация прошла успешно!');
      setTimeout(() => navigate('/sign-in'), 2000);
    }
  };

  return (
    <form onSubmit={handleSubmit} className="form-container">
      <h2>Регистрация</h2>
      {success && <div className="success">{success}</div>}
      <input
        type="text"
        placeholder="Имя"
        value={name}
        onChange={e => setName(e.target.value)}
        className={errors.name ? 'error' : ''}
      />
      {errors.name && <div className="error-message">{errors.name}</div>}

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

      <input
        type={showPassword ? 'text' : 'password'}
        placeholder="Подтверждение пароля"
        value={confirmPassword}
        onChange={e => setConfirmPassword(e.target.value)}
        className={errors.confirmPassword ? 'error' : ''}
      />
      {errors.confirmPassword && <div className="error-message">{errors.confirmPassword}</div>}

      <label>
        <input type="checkbox" className='checkbox' checked={showPassword} onChange={() => setShowPassword(!showPassword)} /> Показать пароль
      </label>

      <button type="submit">Зарегистрироваться</button>

      <div className="redirect">
        Уже есть аккаунт? <Link to="/sign-in">Войти</Link>
      </div>
    </form>
  );
};

export default SignUp;
