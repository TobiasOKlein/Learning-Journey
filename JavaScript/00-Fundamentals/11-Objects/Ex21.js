/**
 * @author Tobias Ocean Klein
 * @date 05/02/2026
 * @description Exemplo de Objeto
 * @comment Execute através do Node.js
 */

let arrayTest = []
let objectTest = {}

console.log(`Array type: ${typeof arrayTest}`)
console.log(`Object type: ${typeof objectTest}`)

let objetoAmigo = {
    nome: 'Pedro',
    idade: 24,
    sexo: 'M',
    peso: 63,
    altura: 1.68,
    envelhecer(iIdade=this.idade){
        console.log(`Envelhecendo ${iIdade} anos`)
        this.idade += iIdade
    }
}

console.log(objetoAmigo)
console.log(`Idade: ${objetoAmigo.idade} anos`)
objetoAmigo.envelhecer(32)
console.log(`Idade: ${objetoAmigo.idade} anos`)
