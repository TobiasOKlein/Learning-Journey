var dataAtual = new Date()
var iHora = dataAtual.getHours()
var iMinuto = dataAtual.getMinutes()

console.log(`Agora são exatamente ${iHora}:${iMinuto}.`)

iHora = iHora + (iMinuto / 60)

if (iHora < 12) {
    console.log('Bom dia!')
} else if (iHora <= 18) {
    console.log('Boa tarde!')
} else {
    console.log('Boa noite!')
}