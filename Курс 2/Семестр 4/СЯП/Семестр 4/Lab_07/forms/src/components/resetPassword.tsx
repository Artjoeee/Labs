import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import { usersDB, validateEmail } from '../validation';
import '../Form.css';

const ResetPassword = () => {
  const [email, setEmail] = useState('');
  const [errors, setErrors] = useState<{ [key: string]: string }>({});
  const [success, setSuccess] = useState('');

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    setSuccess('');

    let errs: { [key: string]: string } = {};

    if (!email.trim()) 
    {
      errs.email = 'Email обязателен';
    }
    else if (validateEmail(email) !== '') 
    {
      errs.email = validateEmail(email);
    }

    setErrors(errs);

    if (Object.keys(errs).length === 0) {
      const exists = usersDB.has(email);
      if (exists) {
        const newPassword: string = 'Password111';
        const user = usersDB.get(email);

        if (user) {
          usersDB.set(email, { ...user, password: newPassword });
        }

        setSuccess(`Новый пароль: ${newPassword}`);
      } else {
        errs.email = 'Email не найден';

        setErrors(errs);
      }
    }
  };

  return (
    <form onSubmit={handleSubmit} className="form-container">
      <h2>Восстановление пароля</h2>
      {success && <div className="success">{success}</div>}

      <input
        type="text"
        placeholder="Email"
        value={email}
        onChange={e => setEmail(e.target.value)}
        className={errors.email ? 'error' : ''}
      />
      {errors.email && <div className="error-message">{errors.email}</div>}

      <button type="submit">Сбросить пароль</button>

      <div className="redirect">
        Вспомнили пароль? <Link to="/sign-in">Войти</Link>
      </div>
    </form>
  );
};

export default ResetPassword;
