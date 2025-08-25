import React, { useState } from "react";

let SyncInput: React.FC<{}> = () => {
    let [text, setText] = useState("");

    const update = (event: React.ChangeEvent<HTMLInputElement>) => {
        setText(event.target.value);
    }

    return (
        <div>
            <input type="text" value={text} onChange={update}/>
            <input type="text" value={text} onChange={update}/>
        </div>
    )
}

export default SyncInput;