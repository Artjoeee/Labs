class Sudoku {
  constructor() {
    this.emptyBoard = Array(9).fill(null).map(() => Array(9).fill(0));
    this.board = this.emptyBoard;
  }

  resetBoard() {
    this.board = this.emptyBoard;
    console.log("Игровое поле сброшено.");
  }

  checkRow(rowIndex) {
    const row = this.board[rowIndex];
    const seen = new Set();

    for (const num of row) {
      if (num !== 0) {
        if (seen.has(num)) { 
          return false;
        }
        
        seen.add(num);
      }
    }

    return true;
  }

  checkColumn(colIndex) {
    const seen = new Set();

    for (const row of this.board) {
      const num = row[colIndex];

      if (num !== 0) {
        if (seen.has(num)) {
          return false;
        }

        seen.add(num);
      }
    }

    return true;
  }

  checkSquare(squareIndex) {
    const seen = new Set();
    const startRow = Math.floor(squareIndex / 3) * 3;
    const startCol = (squareIndex % 3) * 3;

    for (let i = startRow; i < startRow + 3; i++) {
      for (let j = startCol; j < startCol + 3; j++) {
        const num = this.board[i][j];

        if (num !== 0) {
          if (seen.has(num)) { 
            return false;
          }

          seen.add(num);
        }
      }
    }

    return true;
  }

  checkBoard() {
    let isValid = true;

    for (let i = 0; i < 9; i++) {
      if (!this.checkRow(i)) {
        console.log(`Ошибка в строке ${i}`);
        isValid = false;
      }
    }

    for (let i = 0; i < 9; i++) {
      if (!this.checkColumn(i)) {
        console.log(`Ошибка в столбце ${i}`);
        isValid = false;
      }
    }

    for (let i = 0; i < 9; i++) {
      if (!this.checkSquare(i)) {
        console.log(`Ошибка в квадрате ${i}`);
        isValid = false;
      }
    }

    return isValid;
  }

  generateBoard() {
    this.resetBoard();

    const shuffle = (array) => {
      for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));

        [array[i], array[j]] = [array[j], array[i]];
      }

      return array;
    };

    const isSafe = (row, col, num) => {
      if (this.board[row].includes(num)) {
        return false;
      }

      for (let i = 0; i < 9; i++) {
        if (this.board[i][col] === num) { 
          return false;
        }
      }

      const startRow = Math.floor(row / 3) * 3;
      const startCol = Math.floor(col / 3) * 3;

      for (let i = startRow; i < startRow + 3; i++) {
        for (let j = startCol; j < startCol + 3; j++) {
          if (this.board[i][j] === num) { 
            return false;
          }
        }
      }

      return true;
    };

    const fillBoard = (row, col) => {
      if (row === 9) {
        return true;
      }
      if (col === 9) {
        return fillBoard(row + 1, 0);
      }
      if (this.board[row][col] !== 0) { 
        return fillBoard(row, col + 1);
      }

      const numbers = shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]);

      for (const num of numbers) {
        if (isSafe(row, col, num)) {
          this.board[row][col] = num;

          if (fillBoard(row, col + 1)) {
            return true;
          }
          
          this.board[row][col] = 0;
        }
      }

      return false;
    };

    if (fillBoard(0, 0)) {
      console.log("Игровое поле успешно сгенерировано.");
    } else {
      console.log("Не удалось сгенерировать игровое поле.");
    }
  }

  introduceError() {
    const randomRow = Math.floor(Math.random() * 9);
    const randomCol = Math.floor(Math.random() * 9);
    const wrongValue = Math.floor(Math.random() * 9) + 1;

    console.log(`Вносим ошибку в клетку (${randomRow}, ${randomCol})`);
    this.board[randomRow][randomCol] = wrongValue;
  }
}

const sudoku = new Sudoku();

sudoku.generateBoard();
sudoku.introduceError();
console.table(sudoku.board);
console.log(sudoku.checkBoard());
