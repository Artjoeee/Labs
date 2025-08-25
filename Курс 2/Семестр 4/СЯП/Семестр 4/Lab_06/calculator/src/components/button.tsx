import "../style.css";

interface ButtonProps {
    children: React.ReactNode;
    onClick: () => void;
    special?: boolean;
    variant?: boolean;
}

const Button: React.FC<ButtonProps> = ({ children, onClick, special, variant = "primary" }) => {
    const classes = [
        "ButtonSpecial",
        variant ? "secondary" : "primary",
        special ? "special" : ""
    ].join(" ");

    return (
        <button className={classes} onClick={onClick}>
            {children}
        </button>
    );
};

export default Button;