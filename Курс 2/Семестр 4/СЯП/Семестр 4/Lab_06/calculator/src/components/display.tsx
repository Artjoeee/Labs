import "../style.css";

interface IDisplay {
    displayValue: string;
    historyValue: string;
}

const Display: React.FC<IDisplay> = ({ displayValue, historyValue }) => {
    const limitedValue = displayValue.length > 11
        ? displayValue.slice(0, 11)
        : displayValue;

    const limitedHistory = historyValue.length > 11
        ? historyValue.slice(0, 11)
        : historyValue;   

    return (
        <div>
            <div className="DisplayHistory">{limitedHistory}</div>
            <div className="Display">
                <span>=</span> {limitedValue}
            </div>
            
        </div>
    );
};

export default Display;