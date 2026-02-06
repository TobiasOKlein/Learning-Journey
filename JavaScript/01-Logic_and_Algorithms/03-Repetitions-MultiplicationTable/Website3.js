
function generateTable () {
    let xNumber = document.getElementById('number')
    let xTab = document.getElementById('sel_tab')

    if (xNumber.value.length == 0) {
        window.alert('Por favor, digite um número!')
    } else {
        let iNum = Number(xNumber.value)
        let iCounter = 1
        xTab.innerHTML = '' // Limpa o select
        while (iCounter <= 10) {
            let xItem = document.createElement('option') // Cria um elemento option no select
            xItem.text = `${iNum} x ${iCounter} = ${iNum * iCounter}`
            xItem.value = `tab${iCounter}`
            xTab.appendChild(xItem)
            iCounter++
        }
    }
}