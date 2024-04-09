import React, { useState } from "react";

const Button = (props) => {
  const { id, counter_id, name, price, handleParentFunc} = props;
  const [count, setCount] = useState(0);
  const handleClick = () => {
    setCount(count + 1);
    handleParentFunc(count + 1, price);
  };

  return (
    <div id={id} className="button-container">
      <button onClick={handleClick} className="button">
        <span>{name}</span>
        <span>{price}</span>
      </button>
      <span id={counter_id} className="badge">
        {count}
      </span>
    </div>
  );
};

export default Button;
