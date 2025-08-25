import React from 'react';
import Counter from './components/Counter';
import TextInput from './components/TextInput';
import SyncInput from './components/SyncInput';
import ChangeColor from './components/ChangeColor';
import List from './components/List';
import DeleteItem from './components/DeleteItem';
import './App.css';

function App() {
  return (
    <div className="App">
        <Counter></Counter>
        <TextInput></TextInput>
        <SyncInput></SyncInput>
        <ChangeColor></ChangeColor>
        <List></List>
        <DeleteItem></DeleteItem>
    </div>
  );
}

export default App;
