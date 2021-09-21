console.clear()
type adjacencyArray = Array<Array<number>>;

const graphArray: adjacencyArray = [
  [0, 1, 1, 0],
  [1, 0, 0, 1],
  [1, 0, 0, 0],
  [0, 1, 0, 0],
];

function graphArrayPrint() {
  for (let i = 0; i < graphArray.length; i++) {
    for (let j = 0; j < graphArray[0].length; j++) {
      if (graphArray[i][j] === 1) {
        console.log(`${String.fromCharCode(i+65)}->${String.fromCharCode(j+65)}`);
      }
    }
  }
}

function graphArraySearch(col: number, row: number): boolean {
  return graphArray[col][row] === 1;
}

//graphArrayPrint();
console.log(graphArraySearch(0, 3));

console.log('-----------------')

type adjacencyList = Array<Array<number>>;

const graphList: adjacencyList = [
  [1, 2],
  [0, 3],
  [0],
  [1],
];

function graphListPrint() {
  for (let i = 0; i < graphList.length; i++) {
    for (let j = 0; j < graphList[i].length; j++) {
      console.log(`${String.fromCharCode(i+65)}->${String.fromCharCode(graphList[i][j]+65)}`);
    }
  }
}

function graphListSearch(col: number, row: number): boolean {
  return graphList[col].find(element => element === row) !== undefined
}

//graphListPrint();
console.log(graphListSearch(0, 2));