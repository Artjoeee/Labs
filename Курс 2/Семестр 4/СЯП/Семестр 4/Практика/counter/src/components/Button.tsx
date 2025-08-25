import React from "react";

interface ButtonComponent {
    title: string;
    callBack: () => void;
    disabled: boolean;
}

let Button: React.FC<ButtonComponent> = ({title, callBack, disabled = true}) => {
    return (
        <button className={title} onClick={callBack} disabled={disabled}>
            {title}
        </button>
    )
}

export default Button;