/**
 * @author Tobias Ocean Klein
 * @date 05/02/2026
 * @description Exemplo de Função
 * @comment Execute através do Node.js
 */

function par_impar(n) {
    if (n % 2 == 0)
        return "Par"
    else
        return "Ímpar"
}

console.log(`O número 2 é ${par_impar(2)}`)
console.log(`O número 3 é ${par_impar(3)}`)