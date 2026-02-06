/**
 * @author Tobias Ocean Klein
 * @date 05/02/2026
 * @description Exemplo de Vetor
 * @comment Execute através do Node.js
 */

let xNum = [5, 8, 4]

console.log(`Vetor: ${xNum}`)

xNum[3] = 6

console.log(`Vetor: ${xNum}`)

xNum.push(7)

console.log(`Vetor: ${xNum}`)

console.log(`Tamanho do vetor: ${xNum.length}`) // length é um atributo, não um método

xNum.sort()

console.log(`Vetor: ${xNum}`)

console.log(`O primeiro valor é ${xNum[0]}`)

/*
for(let i = 0; i < xNum.length; i++)
    console.log(`A posição ${i} tem o valor ${xNum[i]}`)
*/

for(let i in xNum)
    console.log(`A posição ${i} tem o valor ${xNum[i]}`)

// Searching a repeated value

let iNumRepeated = 8
let xRepetitions = []
let bStillSearching = true
let iIndex = 0

xNum.push(8)
xNum.push(7)
xNum.push(8)

console.log(`\nVetor: ${xNum}`)

console.log(`O número ${iNumRepeated} está no vetor?`)

while(bStillSearching) {
    iIndex = xNum.indexOf(iNumRepeated, iIndex) // Começa a procurar a partir do último índice encontrado

    if(iIndex == -1) {
        bStillSearching = false
    } else {
        xRepetitions.push(iIndex)
        iIndex++ // Avança para a próxima posição para continuar a busca
    }
}

console.log(`O número ${iNumRepeated} aparece nas posições: ${xRepetitions}`)