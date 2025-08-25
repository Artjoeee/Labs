import React, {useState} from 'react';
import "./App.css";

interface ButtonType {
  title: string,
  callBack: () => void,
  disabled?: boolean
}

let Button: React.FC<ButtonType> = ({title, callBack, disabled = false}) => {
  return (
    <button className={title} onClick={callBack} disabled={disabled} >
      {title}
    </button>
  );
}

function Counter() {
  let [count, setCount] = useState(0);
  const increase = () => {
    if (count < 5) {
      setCount(++count);
    }
  };

  const reset = () => {
    setCount(0);
  };

  return (
    <div className="block">
      <h1 className="count" style={{color: count === 5? "red": "aqua"}}>{count}</h1>
      <div className="button">
        <Button title="inc" callBack={increase} disabled={count === 5}/>
        <Button title="reset" callBack={reset} disabled={count === 0}/>
      </div>
    </div>
  );
}

function App() {
  return (
    <div className="App">
      <Counter/>
    </div>
  );
}

export default App;
