# Uses node version 22 as our base image
FROM node:22-alpine

# Goes to the app directory (think of it like a cd terminal command)
WORKDIR /app

#
# Copy package.json and package-lock.json (if available)
#COPY package*.json ./
#
# Install app dependencies
# RUN npm install
#

## Cada uma das partes que escrevemos acima é uma camada. Docker organiza e usa cache das camadas de forma inteligente conforme elas são modificadas, ou seja, na primeira vez que executamos um código, baixamos suas dependências. Se o modificamos e executamos, ele não baixa as dependências novamentes, mas usa em cache as que já foram instaladas ##

# Copy the rest of our app into the container
#COPY . .
COPY HelloDocker.js .

# Set port environment variable
#ENV PORT=9000

# Expose the port so our computer can acess it
#EXPOSE 9000

# Run the app
#CMD ["npm", "start"]
CMD ["node", "HelloDocker.js"]

# We don't use "RUN npm start", it happens when the image is built
# We use "CMD ["npm", "start"]" to start the container AFTER the building
# We can only have one CMD in a Dockerfile