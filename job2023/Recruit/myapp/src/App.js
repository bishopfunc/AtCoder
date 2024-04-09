import React from 'react';
import './App.css';
import Button from './components/Button';
import { useState } from 'react';

function App() {
  const [allCount, setAllCount] = useState(0);
  const [allPrice, setAllPrice] = useState(0);

  const handleClickFunc = (count, price) => {
    setAllCount(allCount + 1);
    setAllPrice(allPrice + 1 * price);
  };

  return (
    <div className='container'>
      <div>
        <Button
          name="コーヒー"
          price={420}
          id="coffee"
          counter_id="coffee-count"
          handleParentFunc={handleClickFunc}
        />
        <Button
          name="紅茶"
          price={280}
          id="tea"
          counter_id="tea-count"
          handleParentFunc={handleClickFunc}
        />
        <Button
          name="ミルク"
          price={180}
          id="milk"
          counter_id="milk-count"
          handleParentFunc={handleClickFunc}
        />
        <Button
          name="コーラ"
          price={190}
          id="coke"
          counter_id="coke-count"
          handleParentFunc={handleClickFunc}
        />
        <Button
          name="ビール"
          price={580}
          id="beer"
          counter_id="beer-count"
          handleParentFunc={handleClickFunc}
        />
      </div>
      <div className='card'>
        <p className='card__titletext'>お会計</p>
        <div className='card__textbox'>
          <div>
            <span id="count">商品数: {allCount}個</span>
          </div>
          <div>
          <span id="price">合計金額: {allPrice}円</span>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;
