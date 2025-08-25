import React, { useState } from "react";

let LoginForm: React.FC<{}> = () => {
    let [name, setName] = useState("");
    let [password, setPassword] = useState("");

    const updateName = (elem: React.ChangeEvent<HTMLInputElement>) => {
        setName(elem.target.value)
    }

    const updatePassword = (elem: React.ChangeEvent<HTMLInputElement>) => {
        setPassword(elem.target.value)
    }

    const exit = () => {
        if (name !== "" && password !== "") {
            if(name.length < 2) {
                alert("Слишком маленькое имя!");
            }
            else if (password.length < 6) {
                alert("Слишком маленький пароль!")
            }
            else {
                alert("Вы успешно вошли!");
            }
        }
        else {
            alert("Заполните все поля!");
        }
    }

    return (
        <div className="block">
            <h1>Авторизация</h1>
            <input type="text" placeholder="Имя" value={name} onChange={updateName}/>
            <input type="password" placeholder="Пароль" value={password} onChange={updatePassword}/>
            <button onClick={exit}>Войти</button>
        </div>
    )
}

export default LoginForm;