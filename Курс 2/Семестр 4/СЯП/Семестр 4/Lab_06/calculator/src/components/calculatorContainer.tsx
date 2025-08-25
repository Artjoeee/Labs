import "../style.css";

interface CalculatorContainerProps {
    children: React.ReactNode;
    theme: string;
}

const CalculatorContainer: React.FC<CalculatorContainerProps> = ({ children, theme }) => {
    return <div className={theme}>{children}</div>;
};

export default CalculatorContainer;