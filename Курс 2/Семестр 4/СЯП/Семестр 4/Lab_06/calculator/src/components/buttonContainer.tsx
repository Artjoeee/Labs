import "../style.css";

interface ButtonContainerProps {
    children: React.ReactNode;
}

const ButtonContainer: React.FC<ButtonContainerProps> = ({ children }) => {
    return <div className="ButtonContainer">{children}</div>;
};

export default ButtonContainer;