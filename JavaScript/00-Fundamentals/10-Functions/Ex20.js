/**
 * @author Tobias Ocean Klein
 * @date 05/02/2026
 * @description Exemplo de Função
 * @comment Execute através do Node.js
 */

// Função Comum
function factorialCommon(n) {
    let fact = 1
    for (let i = 1; i <= n; i++)
        fact *= i
    return fact
}

console.log(factorialCommon(5))

// Função Recursiva
function factorialRecursive(n) { 
    if (n == 1)
        return 1
    else
        return n * factorialRecursive(n - 1) // Chama a si mesma
}

console.log(factorialRecursive(5))