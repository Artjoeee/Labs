import React, { useState } from "react";
import Button from "./Button";

let Counter: React.FC<{}> = () => {
    let [count, setCount] = useState(0);

    const increase = () => {
        if(count < 5) {
            setCount(++count);
        }
    }

    const reset = () => {
        if (count > 0) {
            setCount(0);
        }
    }

    return (
        <div className="block">
            <h1 style={{color: count == 5 ? "red" : "black"}}>{count}</h1>
            <div className="buttons">
                <Button title="inc" callBack={increase} disabled={count == 5}></Button>
                <Button title="reset" callBack={reset} disabled={count == 0}></Button>
            </div>
        </div>
    )
}

export default Counter;