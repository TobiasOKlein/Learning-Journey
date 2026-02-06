/**
 * @author Tobias Ocean Klein
 * @description 
 * @date 05/02/2026
 * 
 */


// Não existe declaração de função em JS e a ordem não importa
//function isNumber(num);
//function inHistory(num, array);


let gNumArray = [] // Array global


function addNumber(numInput) {
    //console.log(`Objeto: ${numInput}`);
    let numHistory = document.getElementById('numHistory');
    
    if (isNumber(numInput) && !inHistory(numInput, gNumArray)) {
        gNumArray.push(Number(numInput));
        //console.log(gNumArray);

        let option = document.createElement('option');
        option.text = `Valor ${numInput} adicionado`;
        numHistory.add(option);
        //numHistory.appendChild(option); // Funciona da mesma forma

        document.querySelector('div#analysis').innerHTML = ''
    } else {
        window.alert('Valor inválido ou já adicionado');
    }
    let numInputElem = document.getElementById('numInput');
    numInputElem.value = '';
    numInputElem.focus();
}


function isNumber(num) {
    if (num >= 1 && num <= 100)
        return true
    else
        return false
}


function inHistory(num, array) {
    if (array.indexOf(Number(num)) != -1)
        return true
    else
        return false
}


function analyzeNumbers() {
    if (gNumArray.length == 0) {
        window.alert('Adicione números antes de finalizar');
    } else {
        let analysis = document.querySelector('div#analysis');
        
        let numCount = gNumArray.length
        let numMax = gNumArray[0]
        let numMin = gNumArray[0]
        let numSum = 0
        let numAvg = 0
        
        analysis.innerHTML = ''
        analysis.innerHTML += `<p>Total de números adicionados: ${numCount}</p>`

        
        for (let n in gNumArray) {
            if (gNumArray[n] > numMax)
                numMax = gNumArray[n]
            if (gNumArray[n] < numMin)
                numMin = gNumArray[n]
        }
        analysis.innerHTML += `<p>Maior número: ${numMax}</p>`
        analysis.innerHTML += `<p>Menor número: ${numMin}</p>`
        

        for (let n in gNumArray)
            numSum += Number(n)
        analysis.innerHTML += `<p>Soma dos números: ${numSum}</p>`


        numAvg = numSum / numCount
        analysis.innerHTML += `<p>Média dos números: ${numAvg}</p>`
        
    }
}