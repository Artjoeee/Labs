import React, { useState } from "react";

let TextInput: React.FC<{}> = () => {
    let [text, setText] = useState("");

    const update = (event: React.ChangeEvent<HTMLInputElement>) => {
        setText(event.target.value)
    }

    return (
        <div>
            <input type="text" value={text} onChange={update}/>
            <h1>{text}</h1>
        </div>
    )
} 

export default TextInput;