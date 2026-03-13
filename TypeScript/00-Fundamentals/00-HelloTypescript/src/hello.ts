function greet(name: string): string {
  return `Hello, ${name}!`;
}

const message: string = greet("World");
console.log(message);

// Isso transforma o arquivo num módulo isolado e para o erro de colisão de variáveis!
export {}; 