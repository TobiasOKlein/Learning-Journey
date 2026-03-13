console.log("Hello Docker!");

const os = require('os');
console.log('Executando JavaScript dentro do Docker...');
console.log(`Arquitetura do Container: ${os.arch()}`);
console.log(`Plataforma: ${os.platform()}`);
console.log(`Versão do Node: ${process.version}`);