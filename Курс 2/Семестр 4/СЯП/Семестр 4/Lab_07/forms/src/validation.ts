export const usersDB = new Map<string, { name: string; password: string }>();

export const validateName = (name: string) => {
  if (!name.trim()) 
  {
    return 'Имя обязательно';
  }

  if (!/^[А-Яа-яЁёA-Za-z\s]+$/.test(name)) 
  {
    return 'Имя должно содержать только буквы и пробелы';
  }

  if (name.length < 2) 
  {
    return 'Имя должно содержать минимум 2 символа';
  }

  if (name.length > 50)
  {
    return 'Имя должно содержать не более 50 символов';
  }

  return '';
};

export const validateEmail = (email: string) => {
  if (!email.trim()) 
  {
    return 'Email обязателен';
  }

  if (/\s/.test(email)) 
  {
    return 'Email не должен содержать пробелов';
  }

  const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

  if (!emailRegex.test(email)) 
  {
    return 'Некорректный формат email';
  }

  return '';
};

export const validatePassword = (password: string) => {
  if (!password) 
  {
    return 'Пароль обязателен';
  }

  if (/\s/.test(password)) 
  {
    return 'Пароль не должен содержать пробелов';
  }

  if (password.length < 8) 
  {
    return 'Минимальная длина пароля 8 символов';
  }

  if (!/[A-Z]/.test(password)) 
  {
    return 'Пароль должен содержать хотя бы одну заглавную букву';
  }

  if (!/[a-z]/.test(password)) 
  {
    return 'Пароль должен содержать хотя бы одну строчную букву';
  }

  if (!/[0-9]/.test(password)) 
  {
    return 'Пароль должен содержать хотя бы одну цифру';
  }

  return '';
};

export const validatePasswordConfirm = (password: string, confirm: string) => {
  if (!confirm) 
  {
    return 'Подтвердите пароль';
  }

  if (password !== confirm) 
  {
    return 'Пароли не совпадают';
  }

  return '';
};
