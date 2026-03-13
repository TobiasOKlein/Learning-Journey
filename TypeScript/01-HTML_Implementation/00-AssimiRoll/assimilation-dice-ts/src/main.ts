/**
 * @author Tobias Ocean Klein
 * @date 09/mar/2026
 * @description Testing Typescript through HTML rolling dice
 */

// IMPORT //

import './style.css'

// MAIN CODE //

/**
 * @type Interface
 * @description Quantity of each label on roll result
 */
interface AssimilationDice {
    Pressure : number;
    Adaptation : number;
    Success : number;
    Nothing : number;
}

/**
 * @function rollDice 
 * @param iQuantity: number
 * @param iFaces: number
 * @returns string[]
 */
function rollDice (iQuantity : number = 1, iFaces : number = 6) : Partial<AssimilationDice>[] {
    let sResult: Partial<AssimilationDice>[] = [];
    let aRandomNumbers = new Uint32Array(iQuantity);
    window.crypto.getRandomValues(aRandomNumbers);

    for (let i : number = 0; i < iQuantity; i++) {
        let fpRandomPoint : number = aRandomNumbers[i] / 4294967296;
        let iNewRoll : number = Math.floor(fpRandomPoint * iFaces) + 1;
        let xAssimiRoll : AssimilationDice = switchAssimilationDice(iNewRoll);
        
        let singleDie: Partial<AssimilationDice> = {};

        if (xAssimiRoll.Pressure)   singleDie.Pressure   = xAssimiRoll.Pressure;
        if (xAssimiRoll.Adaptation) singleDie.Adaptation = xAssimiRoll.Adaptation;
        if (xAssimiRoll.Success)    singleDie.Success    = xAssimiRoll.Success;
        if (xAssimiRoll.Nothing)    singleDie.Nothing    = xAssimiRoll.Nothing;

        sResult.push(singleDie);
    }
  
    return sResult;
}


/**
 * @function switchAssimilationDice
 * @param iResult 
 * @returns AssimilationDice
 */
function switchAssimilationDice (iResult : number) : AssimilationDice {
    let xResult : AssimilationDice = {Nothing : 0, Pressure : 0, Adaptation : 0, Success : 0};
    switch (iResult) {
        case 1:
            xResult.Nothing += 1;
            break;
        case 2:
            xResult.Nothing += 1;
            break;
        case 3:
            xResult.Pressure += 1;
            break;
        case 4:
            xResult.Pressure += 1;
            xResult.Adaptation += 1;
            break;
        case 5:
            xResult.Pressure += 1;
            xResult.Adaptation += 1;
            break;
        case 6:
            xResult.Success += 1;
            break;
        case 7:
            xResult.Success += 2;
            break;
        case 8:
            xResult.Success += 1;
            xResult.Adaptation += 1;
            break;
        case 9:
            xResult.Success += 1;
            xResult.Adaptation += 1;
            xResult.Pressure += 1;
            break;
        case 10:
            xResult.Success += 2;
            xResult.Pressure += 1;
            break;
        case 11:
            xResult.Success += 1;
            xResult.Adaptation += 2;
            xResult.Pressure += 1;
            break;
        case 12:
            xResult.Pressure += 2;
            break;
    }
    return xResult;
}


// HTML INTERFACE //

document.querySelector<HTMLDivElement>('#app')!.innerHTML = `
  <div>
    <h1>Assimilation Roller</h1>
    <div class="card">
      <input type="number" id="qty" value="1" min="1" max="20">
      <select id="type">
        <option value="6">d6</option>
        <option value="10">d10</option>
        <option value="12">d12</option>
      </select>
      <button id="roll-btn" type="button">Rolar Dados</button>
    </div>
    <div id="results"></div>
  </div>
`


// BUTTON AND RESULTS TABLE //

const btn = document.querySelector<HTMLButtonElement>('#roll-btn')!;
const resultsDiv = document.querySelector<HTMLDivElement>('#results')!;

btn.addEventListener('click', () => {
    const qty = parseInt(document.querySelector<HTMLInputElement>('#qty')!.value);
    const faces = parseInt(document.querySelector<HTMLSelectElement>('#type')!.value);
    
    const results = rollDice(qty, faces);
    
    // Gerando a tabela HTML para o navegador
    let tableHTML = `<table>
        <tr><th>#</th><th>Nothing</th><th>Pressure</th><th>Adaptation</th><th>Success</th></tr>`;
    
    results.forEach((die, index) => {
        tableHTML += `<tr>
            <td>${index+1}</td>
            <td>${die.Nothing || ''}</td>
            <td>${die.Pressure || ''}</td>
            <td>${die.Adaptation || ''}</td>
            <td>${die.Success || ''}</td>
        </tr>`;
    });
    
    tableHTML += `</table>`;
    resultsDiv.innerHTML = tableHTML;
});