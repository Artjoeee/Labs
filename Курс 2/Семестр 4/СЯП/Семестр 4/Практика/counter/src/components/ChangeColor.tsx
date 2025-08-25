import React, { useState } from "react";

let ChangeColor: React.FC<{}> = () => {
    let [change, setChange] = useState("");

    const update = () => {
        if (change == "") {
            setChange("changed");
        }
        else {
            setChange("");
        }
    }

    return (
        <div>
            <div className="change" style={{background: change == "" ? "green" : "red"}}></div>
            <button onClick={update}>change</button>
        </div>
    )
}

export default ChangeColor;