class Sudoku {
    constructor() {
        this.numSelected = null;
        this.board = [];
        this.solution = [];
        this.init();
    }

    init() {
        document.getElementById("newGameBtn").addEventListener("click", () => {
            this.generateNewGame();
            this.updateBoard();
        });

        document.getElementById("clearBoardBtn").addEventListener("click", () => {
            this.clearUserInput();
            this.updateBoard();
        });

        document.getElementById("showAnswer").addEventListener("click", () => {
            this.showAnswers();
        });

        this.generateNewGame();
        this.setGame();
    }

    generateNewGame() {
        this.board = this.generateBoard();
        this.solution = this.generateSolution();
    }

    generateBoard() {
        let board = Array(9).fill().map(() => Array(9).fill(0));

        if (this.solveSudoku(board)) {
            let numToRemove = Math.floor(Math.random() * 40) + 30;

            for (let i = 0; i < numToRemove; i++) {
                let row = Math.floor(Math.random() * 9);
                let col = Math.floor(Math.random() * 9);

                board[row][col] = 0;
            }
        }

        return board;
    }

    generateSolution() {
        let solution = Array(9).fill().map(() => Array(9).fill(0));
        this.solveSudoku(solution);

        return solution;
    }

    solveSudoku(board) {
        for (let r = 0; r < 9; r++) {
            for (let c = 0; c < 9; c++) {
                if (board[r][c] === 0) {
                    for (let num = 1; num <= 9; num++) {
                        if (this.isSafe(board, r, c, num)) {
                            board[r][c] = num;

                            if (this.solveSudoku(board)) {
                                return true;
                            }

                            board[r][c] = 0;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    isSafe(board, row, col, num) {
        for (let i = 0; i < 9; i++) {
            if (board[row][i] === num || board[i][col] === num) {
                return false;
            }
        }

        let startRow = row - row % 3;
        let startCol = col - col % 3;

        for (let r = startRow; r < startRow + 3; r++) {
            for (let c = startCol; c < startCol + 3; c++) {
                if (board[r][c] === num) {
                    return false;
                }
            }
        }

        return true;
    }

    updateBoard() {
        const boardContainer = document.getElementById("board");
        boardContainer.innerHTML = "";

        this.setGame();
    }

    setGame() {
        const digitsContainer = document.getElementById("digits");
        digitsContainer.innerHTML = "";

        for (let i = 1; i <= 9; i++) {
            let number = document.createElement("div");

            number.id = i;
            number.innerText = i;
            number.addEventListener("click", () => this.selectNumber(number));
            number.classList.add("number");

            digitsContainer.append(number);
        }
    
        const boardContainer = document.getElementById("board");

        for (let r = 0; r < 9; r++) {
            for (let c = 0; c < 9; c++) {
                let tile = document.createElement("div");

                tile.id = r.toString() + "-" + c.toString();
    
                if (this.board[r][c] !== 0) {
                    tile.innerText = this.board[r][c];
                    tile.classList.add("tile-start");
                }
    
                if (r === 2 || r === 5) {
                    tile.classList.add("horizontal-line");
                }

                if (c === 2 || c === 5) {
                    tile.classList.add("vertical-line");
                }
    
                tile.addEventListener("click", () => this.selectTile(tile));
                tile.classList.add("tile");

                boardContainer.append(tile);
            }
        }
    }
    
    selectNumber(number) {
        if (this.numSelected !== null) {
            this.numSelected.classList.remove("number-selected");
        }

        this.numSelected = number;
        this.numSelected.classList.add("number-selected");
    }

    highlightError(row, col) {
        const num = parseInt(this.board[row][col]);
    
        for (let c = 0; c < 9; c++) {
            if (c !== col && this.board[row][c] === num) {
                for (let i = 0; i < 9; i++) {
                    let tile = document.getElementById(`${row}-${i}`);
                    tile.style.backgroundColor = "salmon";
                }
                
                return;
            }
        }
    
        for (let r = 0; r < 9; r++) {
            if (r !== row && this.board[r][col] === num) {
                for (let i = 0; i < 9; i++) {
                    let tile = document.getElementById(`${i}-${col}`);
                    tile.style.backgroundColor = "salmon";
                }

                return;
            }
        }
    
        let startRow = Math.floor(row / 3) * 3;
        let startCol = Math.floor(col / 3) * 3;

        for (let r = startRow; r < startRow + 3; r++) {
            for (let c = startCol; c < startCol + 3; c++) {
                if ((r !== row || c !== col) && this.board[r][c] === num) {
                    for (let r2 = startRow; r2 < startRow + 3; r2++) {
                        for (let c2 = startCol; c2 < startCol + 3; c2++) {
                            let tile = document.getElementById(`${r2}-${c2}`);
                            tile.style.backgroundColor = "salmon";
                        }
                    }

                    return;
                }
            }
        }

        return false;
    }
    
    clearHighlight() {
        const tiles = document.getElementsByClassName("tile");
    
        for (let tile of tiles) {
            tile.style.backgroundColor = "";
        }
    }
    
    selectTile(tile) {
        if (this.numSelected) {
            if (tile.innerText !== "") {
                return;
            }
    
            let coords = tile.id.split("-");
            let r = parseInt(coords[0]);
            let c = parseInt(coords[1]);
    
            if (this.solution[r][c] == this.numSelected.id) {
                tile.innerText = this.numSelected.id;
                tile.style.backgroundColor = "lightgreen";

                this.board[r][c] = parseInt(this.numSelected.id);

                setTimeout(() => {
                    this.clearHighlight();
                }, 1000);
                
            } else {
                this.board[r][c] = parseInt(this.numSelected.id);

                this.highlightError(r, c);
    
                if (this.highlightError(r, c) == false) {
                    tile.style.backgroundColor = "yellow";
                }

                setTimeout(() => {
                    this.clearHighlight();

                    this.board[r][c] = 0;
                }, 2000);
            }
        }
    }
     
    clearUserInput() {
        const tiles = document.getElementsByClassName("tile");
    
        for (let tile of tiles) {
            let coords = tile.id.split("-");
            let r = parseInt(coords[0]);
            let c = parseInt(coords[1]);

            if (!tile.classList.contains("tile-start")) {
                tile.innerText = "";
                tile.style.backgroundColor = "";

                this.board[r][c] = 0;
            }
        }
    }
    
    showAnswers() {
        const tiles = document.getElementsByClassName("tile");

        for (let tile of tiles) {
            let coords = tile.id.split("-");
            let r = parseInt(coords[0]);
            let c = parseInt(coords[1]);

            if (this.board[r][c] === 0) {
                tile.innerText = this.solution[r][c];
                tile.style.backgroundColor = "lightgreen";

                setTimeout(() => {
                    this.clearHighlight();
                }, 2000);
            }
        }
    }
}

window.onload = function() {
    new Sudoku();
};
