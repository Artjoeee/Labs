import React, { useEffect, useState } from "react";

let List: React.FC<{}> = () => {
    let [count, setCount] = useState("");
    let [list, setList] = useState<string[]>([]);

    useEffect(() => {
        let inputValue = Number(count);
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
    }, [count])

    const update = (event: React.ChangeEvent<HTMLInputElement>) => {
        setCount(event.target.value);
    }

    return (
        <div>
            <input type="text" value={count} onChange={update}/>
            <ul>
                {list.map((item, i) => (
                    <li key={i}>{item}</li>))}
            </ul>
        </div>
    )
}

export default List;