#!/usr/bin/env ts-node

/**
 * @author Tobias Ocean Klein
 * @date 09/mar/2026
 * @description Testing a dice roll with NodeJS through a TypeScript program,
 * but considering "Assimilation RPG" dice system
 */

// ARGUMENT VALIDATION //
const argv : string[] = process.argv.slice(2); // Argument Vector
const argQuantity : string | undefined = argv[0]; // ex: "2"
const argDiceType : string | undefined = argv[1]; // ex: "d6"

const diceQuantity : number = argQuantity ? parseInt(argQuantity) : 1;

let diceType : number = 6; // std: d6
if (argDiceType) {
    // Regular Expression (/\D/g, '') removes any letter (as "d") and only keeps the number
    const faceNumber = parseInt(argDiceType.replace(/\D/g, ''));
    if (!isNaN(faceNumber))
        diceType = faceNumber;
}

const allowedDiceSize : number[] = [6, 10, 12];

if (!allowedDiceSize.includes(diceType)) {
    console.error(`\n Error: the die 'd${diceType}' does not exit in Assimilation RPG rules.`);
    console.error(` Please, use only: d6, d10 or d12.\n`);
    process.exit(1); 
}


// EXECUTION //

console.log(`Rolling ${diceQuantity}d${diceType} dice...`);
//console.log(rollDice(diceQuantity, diceType));

const rawResults = rollDice(diceQuantity, diceType);
const tableFormat = rawResults.map(die => {
    return {
        Nothing: die.Nothing || "",
        Pressure: die.Pressure || "",
        Adaptation: die.Adaptation || "",
        Success: die.Success || ""
    };
});
console.table(tableFormat);


// DEFINITIONS //

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

    for (let i : number = 0; i < iQuantity; i++) {
        let newRoll : number = Math.floor(Math.random() * iFaces) + 1;
        let AssimiRoll : AssimilationDice = switchAssimilationDice(newRoll);
        
        let singleDie: Partial<AssimilationDice> = {};

        if (AssimiRoll.Pressure)   singleDie.Pressure   = AssimiRoll.Pressure;
        if (AssimiRoll.Adaptation) singleDie.Adaptation = AssimiRoll.Adaptation;
        if (AssimiRoll.Success)    singleDie.Success    = AssimiRoll.Success;
        if (AssimiRoll.Nothing)    singleDie.Nothing    = AssimiRoll.Nothing;

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