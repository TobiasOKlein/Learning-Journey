/**
 * @author Tobias Ocean Klein
 * @date 05/02/2026
 * @description Exemplo de Função
 * @comment Execute através do Node.js
 */

function sum(n1 = 0, n2 = 0) { // Parâmetros Opcionais (pré-definidos)
    return n1 + n2
}

console.log(`A soma de 2 e 3 é ${sum(2, 3)}`)
console.log(`A soma de 2 e NaN é ${sum(2)}`)
console.log(`A soma de NaN e NaN é ${sum()}`)