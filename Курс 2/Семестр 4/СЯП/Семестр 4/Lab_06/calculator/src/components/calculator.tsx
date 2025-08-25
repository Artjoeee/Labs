import React, { useState, useEffect } from "react";
import "../style.css";
import logo from '../theme.svg';
import Button from './button';
import Theme from './theme';
import Display from './display';
import ButtonContainer from './buttonContainer';
import CalculatorContainer from './calculatorContainer';

const Calculator: React.FC<{}> = () => {
    const [displayValue, setDisplayValue] = useState("0");
    const [operator, setOperator] = useState<string | null>(null);
    const [previousValue, setPreviousValue] = useState<string | null>(null);
    const [waitingForOperand, setWaitingForOperand] = useState(false);
    const [resultJustComputed, setResultJustComputed] = useState(false);
    const [historyValue, setHistoryValue] = useState("");
    const [showHistory, setShowHistory] = useState(false);
    const [saveHistoryValue, setSaveHistoryValue] = useState("");
    const [theme, setTheme] = useState<"dark" | "light">("dark");


    useEffect(() => {
        document.body.classList.remove("light", "dark");
        document.body.classList.add(theme);
    }, [theme]);


    const toggleTheme = () => {
        setTheme(prev => (prev === "dark" ? "light" : "dark"));
    };


    const inputDigit = (digit: string) => {
        if (resultJustComputed && !waitingForOperand) {
            setHistoryValue(saveHistoryValue);
            setShowHistory(true);
            setDisplayValue(digit);
            setResultJustComputed(false);
            return;
        }    

        if (waitingForOperand) {
            setDisplayValue(digit);
            setWaitingForOperand(false);
        } else {
            setDisplayValue((prev) => (prev === "0" ? digit : prev + digit));
        }
    };


    const inputDot = () => {
        if (resultJustComputed) {
            setDisplayValue("0,");
            setResultJustComputed(false);
            return;
        }

        if (waitingForOperand) {
            setDisplayValue("0,");
            setWaitingForOperand(false);
            return;
        }

        if (!displayValue.includes(",")) {
            setDisplayValue(displayValue + ",");
        }
    };


    const clearAll = () => {
        setShowHistory(false);
        setDisplayValue("0");
        setOperator(null);
        setPreviousValue(null);
        setWaitingForOperand(false);
        setResultJustComputed(false);
    };


    const clearEntry = () => {
        setSaveHistoryValue(historyValue);
        setOperator(null);
        setDisplayValue("0");

    };


    const backspace = () => {
        if (displayValue === "Ошибка") {
            setDisplayValue("0");
            setResultJustComputed(false);
            return;
        }
        
        if (resultJustComputed) return;

        setDisplayValue((prev) =>
            prev.length > 1 ? prev.slice(0, -1) : "0"
        );
    };


    const toggleSign = () => {
        if (displayValue === "Ошибка") {
            return;
        }

        if (resultJustComputed) {
            return;
        }

        if (displayValue !== "0") {
            setDisplayValue((prev) =>
                prev.startsWith("-") ? prev.slice(1) : "-" + prev
            );
        }
    };


    const performOperation = (nextOperator: string) => {
        if (displayValue === "Ошибка") {
            setDisplayValue("0");
            setPreviousValue(null);
            setOperator(null);
            setWaitingForOperand(false);
            return;
        }

        const inputValue = parseFloat(displayValue.replace(",", "."));

        if (previousValue != null && operator && !waitingForOperand) {
            const prev = parseFloat(previousValue.replace(",", "."));
            let result: number;

            switch (operator) {
                case "+":
                    result = prev + inputValue;
                    break;
                case "-":
                    result = prev - inputValue;
                    break;
                case "*":
                    result = prev * inputValue;
                    break;
                    case "/":
                        if (inputValue === 0) {
                            setDisplayValue("Ошибка");
                            setPreviousValue(null);
                            setOperator(null);
                            setWaitingForOperand(false);
                            setResultJustComputed(true);
                            return;
                        }
                        result = prev / inputValue;
                        break;
                default:
                    return;
            }

            const resultStr = String(result).replace(".", ",");
            setDisplayValue(resultStr);
            setPreviousValue(resultStr);
            
        } else {
            setPreviousValue(displayValue);
        }

        setOperator(nextOperator);
        setWaitingForOperand(true);
        setResultJustComputed(false);
    };


    const handleEquals = () => {
        if (operator && previousValue) {
            const current = parseFloat(displayValue.replace(",", "."));
            const prev = parseFloat(previousValue.replace(",", "."));

            let newValue: number;

            switch (operator) {
                case "+":
                    newValue = prev + current;
                    break;
                case "-":
                    newValue = prev - current;
                    break;
                case "*":
                    newValue = prev * current;
                    break;
                case "/":
                    if (current === 0) {
                        setDisplayValue("Ошибка");
                        setPreviousValue(null);
                        setOperator(null);
                        setWaitingForOperand(false);
                        setResultJustComputed(true);
                        return;
                    }
                    newValue = prev / current;
                    break;
                default:
                    return;
            }

            if (waitingForOperand) {
                newValue = Number(displayValue);
            }
            
            const newValueStr = String(newValue).replace(".", ",");

            setSaveHistoryValue(newValueStr);
            setDisplayValue(newValueStr);
            setPreviousValue(null);
            setOperator(null);
            setWaitingForOperand(false);
            setResultJustComputed(true);
        }
    };


    const buttonConfig = [
        { label: "CE", onClick: clearEntry, special: true },
        { label: "C", onClick: clearAll },
        { label: "⌫", onClick: backspace },
        { label: "÷", onClick: () => performOperation("/"), special: true },
        { label: "7", onClick: () => inputDigit("7") },
        { label: "8", onClick: () => inputDigit("8") },
        { label: "9", onClick: () => inputDigit("9") },
        { label: "×", onClick: () => performOperation("*"), special: true },
        { label: "4", onClick: () => inputDigit("4") },
        { label: "5", onClick: () => inputDigit("5") },
        { label: "6", onClick: () => inputDigit("6") },
        { label: "-", onClick: () => performOperation("-"), special: true },
        { label: "1", onClick: () => inputDigit("1") },
        { label: "2", onClick: () => inputDigit("2") },
        { label: "3", onClick: () => inputDigit("3") },
        { label: "+", onClick: () => performOperation("+"), special: true },
        { label: "±", onClick: toggleSign },
        { label: "0", onClick: () => inputDigit("0") },
        { label: ",", onClick: inputDot },
        { label: "=", onClick: handleEquals, secondary: true }
    ];


    return (
        <CalculatorContainer theme={theme === "dark" ? "CalculatorContainer dark" : "CalculatorContainer light"}>
            <Theme onClick={toggleTheme} logo={logo}/>
            <Display displayValue={displayValue} historyValue={showHistory ? historyValue : ""}/>
            <ButtonContainer>
                {buttonConfig.map(({ label, onClick, special, secondary= false }) => (
                    <Button
                        key={label}
                        onClick={onClick}
                        special={special}
                        variant={secondary}
                    >
                        {label}
                    </Button>
                ))}
            </ButtonContainer>
        </CalculatorContainer>
    );
};


export default Calculator;
