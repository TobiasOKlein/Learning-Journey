
function atualizarConteudo() {
    var sMensagem = document.getElementById("mensagem");
    var sImagem = document.getElementById("imagem");
    var xData = new Date();
    //var iHora = xData.getHours();
    //var iMinuto = xData.getMinutes();
    var iHora = 20; // Teste
    var iMinuto = 30; // Teste

    sMensagem.innerHTML = `Agora são ${iHora} horas e ${iMinuto} minutos.`;

    iHora = iHora + (iMinuto / 60); // Hora com fração de minutos

    if (iHora >= 5 && iHora <= 12) {
        // Bom dia
        sImagem.src = "manha.png";
        document.body.style.background = "#f7efcf";
        document.querySelector("header").style.color = "#4c5049";
        document.querySelector("footer").style.color = "#4c5049";
    } else if (iHora > 12 && iHora <= 18.5) {
        // Boa tarde
        sImagem.src = "tarde.png";
        document.body.style.background = "#6bb824";
        document.querySelector("header").style.color = "#ffffe4";
        document.querySelector("footer").style.color = "#e2feff";
    } else {
        // Boa noite
        sImagem.src = "noite.png";
        document.body.style.background = "#19435f";
        document.querySelector("header").style.color = "#d2f1ff";
        document.querySelector("footer").style.color = "#ffffe4";
    }

}