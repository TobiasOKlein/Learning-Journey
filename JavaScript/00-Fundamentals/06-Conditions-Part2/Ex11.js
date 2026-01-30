var iIdade = 22

console.log(`Você tem ${iIdade} anos.`)

if (iIdade < 16)
    console.log('Não vota')

else (iIdade < 18 || iIdade > 65) ? console.log('Voto opcional')
                                  : console.log('Voto obrigatório')
