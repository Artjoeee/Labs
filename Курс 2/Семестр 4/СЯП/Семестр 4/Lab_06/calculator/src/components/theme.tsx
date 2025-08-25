import "../style.css";

interface ThemeProps {
    onClick: () => void;
    logo: string;
}

const Theme: React.FC<ThemeProps> = ({ onClick, logo}) => {
    return (
        <button className="ThemeToggle" onClick={onClick}>
            <img src={logo} alt="logo"/>
        </button>
    );
};

export default Theme;