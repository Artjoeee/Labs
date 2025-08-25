import React, { useEffect, useState } from "react";

let DeleteItem: React.FC<{}> = () => {
    let [list, setList] = useState<string[]>([]);

    useEffect(() => {
        let inputValue = 10;
        if (inputValue > 0) {
            setList(() => {
                let items: string[] = [];
                for (let index = 1; index <= inputValue; index++) {
                    items.push(`Element ${index}`);
                }

                return items;
            });
        }
        else {
            setList([]);
        }
    }, [])

    const deleteLast = () => {
        setList(list.slice(0, -1));
    }

    return (
        <div>
            <ul>
                {list.map((item, i) => (
                    <li key={i}>{item}</li>))}
            </ul>
            <button onClick={deleteLast}>Delete</button>
        </div>
    )
}

export default DeleteItem;