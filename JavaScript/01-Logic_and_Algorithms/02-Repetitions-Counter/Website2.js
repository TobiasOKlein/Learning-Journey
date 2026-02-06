
function count() {
    let start = window.document.getElementById('start')
    let end = document.getElementById('end')
    let step = window.document.querySelector('#step')
    let result = document.querySelector('#result')

    if (start.value.length == 0 || end.value.length == 0 || step.value.length == 0) {
        result.innerHTML = 'Impossível contar! Faltam dados!'
        //window.alert('ERRO! Faltam dados!')
    } else {
        result.innerHTML = "Contando: "
        let st = Number(start.value)
        let en = Number(end.value)
        let ste = Number(step.value)

        if (ste == 0) {
            window.alert('ERRO! O passo não pode ser zero! Considerando passo 1')
            ste = 1
        }

        if (st < en)
            // Contagem Crescente
            for (let i = st; i <= en; i += ste) {
                result.innerHTML += `${i}\u{27A1} ` 
            }
        else
            // Contagem Decrescente
            for (let i = st; i >= en; i -= ste) {
                result.innerHTML += `${i}\u{27A1} ` 
            }
        result.innerHTML += `\u{1F3C1}`
    }
}